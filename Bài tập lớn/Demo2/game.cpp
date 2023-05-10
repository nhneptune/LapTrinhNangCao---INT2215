#include "game.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
//#include <SDL2/SDL_Mixer.h>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "object.hpp"
#include "background.hpp"

Game::Game() {
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void Game::gameStart(int argc, char* argv[]) {
    // clouds
    Background cloud(renderer, "clouds.png", 0, 0, 640, 80, 10);
    //Ocean
    Background ocean(renderer, "ocean.png", 0, 80, 640, 400);
    //Sky
    Background sky(renderer, "sky.png", 0, 0, 640, 80);
    //Boat 
    Boat boat;
    boat.setPos(0, 48);
    boat.loadTexture(renderer, "boat.png", 64, 32);
    //Fish
    Fish fish[6];
    char* path = new char[6];
    path[0] = '0';
    path[2] = '.';
    path[3] = 'p';
    path[4] = 'n';
    path[5] = 'g';
    for (int i = 0/*0*/; i <= 5/*8*/; i++) {
//        for (int j = 0; j <= 9; j++){
            
//            path[0] = char(i + 48);
//            path[1] = char(j + 48);
            path[1] = char(i + 48);
            fish[i].loadTexture(renderer, path, 20, 12);
//        }
    }
    //Fish vector
    std::vector<Fish> fishes;
    //Hook
    Hook hook;
    hook.setPos(85, 54);
    hook.loadTexture(renderer, "hook.png", 32, 28);//32x28 pixels
    //Rope
    Rope rope;
    rope.setPos(98, 65);//85, 58
    rope.loadTexture(renderer, "rope.png", 2, 2);//2x2 pixels
    //Spawn fish
    srand(time(NULL)); 
    int maxFish = 10;
    int numberOfFish = 0;
    Uint32 lastTimeSpawn = SDL_GetTicks();
    //Music and sounds
    //reelSound = Mix_LoadWAV("reelSound.wav");
    //Game loop
    SDL_Event event;
    while (running) {
        Uint32 now = SDL_GetTicks();
        if (now - lastTimeSpawn >= 1000 && numberOfFish <= maxFish) {
            int x = rand() % 600 + 20;
            int y = rand() % 340 + 120;
            int fishType = rand() % 6;
            Fish newFish;
            newFish.setPos(x, y);
            newFish.copyTexture(fish[fishType]);
            fishes.push_back(newFish);
            lastTimeSpawn = now;
            numberOfFish ++;
        }
        // SDL_Log("Number of fish: %d",numberOfFish);
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                running = false;
                SDL_Quit();
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    running = false;
                    SDL_Quit();
                    break;
                case SDLK_LEFT:
                    if (!hook.isMoving()){
                        boat.moveBoat(-10);
                        if (boat.turnDirection() == false) {
                            hook.moveHook(-10, 0);
                            rope.moveRope(-10, 0);
                        }
                        else {
                            hook.moveHook(-85, 0);
                            rope.moveRope(-85, 0);
                        }
                    }
                    break;
                case SDLK_RIGHT:
                    if (!hook.isMoving()){
                        boat.moveBoat(10);
                        if (boat.turnDirection() == false) {
                            hook.moveHook(10, 0);
                            rope.moveRope(10, 0);
                        }
                        else {
                            hook.moveHook(85, 0);
                            rope.moveRope(85, 0);
                        }
                    }
                    break;
                case SDLK_SPACE:
                    // hookIsMoving = true;
                    hook.start();
//                    Mix_PlayChannel(-1, reelSound, 0);
                    break;
                }
                break;
            default:
                break;
            }
        }

        hook.update();
        
        SDL_RenderClear(renderer);

        ocean.render(renderer);
        sky.render(renderer);
        cloud.render(renderer);
         
        //Render objects
    
        boat.render(renderer);
        hook.render(renderer);
        rope.render(renderer, (hook.getY() - 58));

        //When fish is hooked
        for (int i = 0; i < numberOfFish-1; i++) {
//            fish->moveFish(1);
            fishes[i].render(renderer);
            if (fishes[i].checkCollision(hook)) {
                // fish->setPos(hook.getX() + 16, hook.getY() + 28);
                // fish->render(renderer);
                hook.catchFish();
                fishes[i].gotHooked();         
            }
            // else fish->render(renderer);
        }    
        //delete hooked fish
        for (int i = 0; i < numberOfFish-1; i++) {
            if (fishes[i].isHooked() == true) {
                fishes.erase(fishes.begin() + i);
                numberOfFish --;
            }
        }
        // SDL_Log("Number of fish: %d",numberOfFish);
        SDL_RenderPresent(renderer);
    }
}
