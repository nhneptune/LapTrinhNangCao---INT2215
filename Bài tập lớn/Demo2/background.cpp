#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "background.hpp"

Background::Background(SDL_Renderer* renderer, const char* path, int p_posX, int p_posY, int p_screen_width, int p_screen_heigh ,float pixelPerSecond) {
    loadTexture(renderer, path);
    setSpeed(pixelPerSecond);
    if (pixelPerSecond > 0) {
        timePerFrame = 1000 / pixelPerSecond;
    }
    else {
        timePerFrame = 4 * 1e9;
    }
    
    posX = p_posX;
    posY = p_posY;
    screen_height = p_screen_heigh;
    screen_width = p_screen_width;
    scrollingOffset = 0;
    lastTime = SDL_GetTicks();
}
void Background::loadTexture(SDL_Renderer* renderer, const char* path) {
    background = IMG_LoadTexture(renderer, path);
}
void Background::setSpeed(float p_pixelPerSecond) {// pixel per second
    timePerFrame = 1000 / p_pixelPerSecond;
}
void Background::render(SDL_Renderer* renderer) {
    SDL_Rect dest1 = {posX + scrollingOffset, posY, screen_width, screen_height};
    SDL_Rect dest2 = {posX + scrollingOffset - screen_width, posY, screen_width, screen_height};
    SDL_RenderCopy(renderer, background, NULL, &dest1);
    SDL_RenderCopy(renderer, background, NULL, &dest2);
    if (timePerFrame != 4 * 1e9){
        Uint32 currentTime = SDL_GetTicks();
        if (currentTime - lastTime >= timePerFrame) {
            scrollingOffset++;
            lastTime = currentTime;
        }
        if (scrollingOffset >= screen_width) {
            scrollingOffset = 0;
        }
    }
}