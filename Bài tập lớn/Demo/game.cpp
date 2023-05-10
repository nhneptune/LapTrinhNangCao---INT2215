#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
const string WINDOW_TITLE = "Fishing";
    
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

SDL_Rect boatLeft;
SDL_Rect boatRight;
SDL_Rect direction[2] = {boatLeft, boatRight};

enum direction {left, right};

class Texture;
class Object;
class Player;

vector<Object*> objects;

class Texture//lazyfoo tutorial
{
    public:
        Texture(int x = 0, int y = 0)
        {
            dTexture = NULL;
            tWidth = 0;
            tHeight = 0;
        }

        ~Texture()
        {
            free();
        }

        void render(int x = 0, int y = 0, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE )
        {
            SDL_Rect rect = {x, y, tWidth, tHeight};
            //SDL_Rect sized_rect = {x, y, 240*2, 208*2};
            if (clip != NULL)
            {
                rect.w = clip->w;
                rect.h = clip->h;
            }
            
           // SDL_RenderCopy(renderer, dTexture, NULL, NULL);
            SDL_RenderCopyEx(renderer, dTexture, clip, &rect, angle, center, flip);
            //SDL_RenderCopyEx(renderer, dTexture, NULL, NULL, angle, center, flip);
        }

        bool loadFile(string path)
        {
            free();
            SDL_Texture* convertedtexture = NULL;
            SDL_Surface* loadedsurface = IMG_Load(path.c_str());
            //dTexture = IMG_LoadTexture(path.c_str());
            if (loadedsurface == NULL)
                cout << "loadFile Error: can't load surface" << std::endl;
            else
            {
                convertedtexture = SDL_CreateTextureFromSurface(renderer, loadedsurface);
                if (convertedtexture == NULL)
                    cout << "loadFile Error: can't convert surface" << std::endl;
                else
                {
                    tWidth = loadedsurface->w;
                    tHeight = loadedsurface->h;

                }
                SDL_FreeSurface(loadedsurface);
            }
            dTexture = convertedtexture;
            //SDL_DestroyTexture(convertedtexture);
            if (dTexture == NULL)
                return false;
            else
                return true;
        }

        void free()
        {
            SDL_DestroyTexture(dTexture);
            dTexture = NULL;
            tWidth = 0;
            tHeight = 0;
        }

        int getWidth()
        {
            return tWidth;
        }

        int getHeight()
        {
            return tHeight;
        }

    private:
        int tWidth;
        int tHeight;
        SDL_Texture* dTexture;
};

Texture background;
Texture boat;

class Object
{
public:
    Object(int x = 0, int y = 0)
    {
        xPos = x;
        yPos = y;
        txtr = NULL;
        objects.push_back(this);
    }

    void setPos(float x, float y)
    {
        xPos = x;
        yPos = y;
        cbox.x = xPos;
        cbox.y = yPos;
    }

//    ~Object()
//    {
//        txtr->free();
//        objects.erase(std::remove(objects.begin(), objects.end(), this), objects.end());
//    }

    virtual void render()
    {
        txtr->render(xPos, yPos);
    }

    float getX()
    {
        return xPos;
    }

    float getY()
    {
        return yPos;
    }

    int getHeight()
    {
        return height;
    }

    int getWidth()
    {
        return width;
    }

    SDL_Rect getColBox()
    {
        return cbox;
    }

protected:
    float xPos, yPos;
    int width, height;
    SDL_Rect cbox;
    Texture* txtr;
};



class Player : public Object
{
    public:
        const int playerSpriteWidth = 36;
        const int playerSpriteHeight = 46;

        Player(int x, int y) : Object(x, y)
        {
            cbox.x = xPos+4;//plus offset
            cbox.y = yPos+6;
            xVel = 0;
            yVel = 0;
            xAcc = 0;
            yAcc = 0;
            currentDirection = 1;
            txtr = &boat;
            cbox.w = playerSpriteWidth; //link width in pixel
            cbox.h = playerSpriteHeight;//link height
        }

        void move()
        {
            float xspeedDif = speedCap - abs(xVel);
            float xease = xspeedDif * xAcc/3;
            xVel += xease;
            if (-speedCap > xVel)
                xVel = -speedCap;
            if (xVel > speedCap)
                xVel = speedCap;
            float yspeedDif = speedCap - abs(yVel);
            float yease = yspeedDif * yAcc/3;
            yVel += yease;
            if (-speedCap > yVel)
                yVel = -speedCap;
            if (yVel > speedCap)
                yVel = speedCap;
            /*if (xAcc > 0)
                xAcc -= friction;
            else if (xAcc < 0)
                xAcc += friction;
            if (xAcc < friction && xAcc > -friction)
                xAcc = 0;*/
            //std::cout << "xVel: " << xVel << " xAcc = " << xAcc <<std::endl;
            //friction decelleration
            if (xVel > 0)
                xVel -= friction;
            else if (xVel < 0)
                xVel += friction;
            if (xVel < friction && xVel > -friction)
                xVel = 0;
            if (yVel > 0)
                yVel -= friction;
            else if (yVel < 0)
                yVel += friction;
            if (yVel < friction && yVel > -friction)
                yVel = 0;
            if (xVel > 0)
                currentDirection = 1;
            else if (xVel < 0)
                currentDirection = 0;
            // if (yVel > 0)
            //     currentDirection = down;
            // else if (yVel < 0)
            //     currentDirection = up;

            xPos += xVel;
            cbox.x = xPos+4;//plus offset
//             if (xPos < 0 || (xPos + 48/*CurrentClip->w*/) > LEVEL_WIDTH || checkCollisionObj(cbox, objs) || checkCollision(cbox, boss.getColBox()) || checkCollisionEnemy(cbox, slimes))
//             {
// //                std::cout << checkCollisionObj(cbox, objs);
//                 xPos -= xVel;
//             }
//             yPos += yVel;
//             cbox.y = yPos+6;
//             if (yPos < 0 || (yPos + 52/*CurrentClip->h*/)> LEVEL_HEIGHT || checkCollisionObj(cbox, objs) || checkCollision(cbox, boss.getColBox()))
//             {
//                 yPos -= yVel;
//             }
        }

        void render()
        {
            //SDL_Rect* CurrentClip = &spriteWalkleft[frame / 4];

            SDL_Rect* CurrentClip;

            if (xVel != 0 || yVel != 0)
            {
                CurrentClip = &direction[currentDirection];
//                Mix_PlayChannel(-1, footstep, -1);
            }
            else
            {
                CurrentClip = &direction[currentDirection];
//                Mix_HaltChannel(-1);
            }

//            std::cout << "xVel: " << xVel << " yVel: " << yVel << std::endl;
//            SDL_RenderFillRect(renderer, &cbox);//render underlying collisionbox
            txtr->render(xPos, yPos, CurrentClip);
//            renderHealth();
        }

//        void renderHitCone()
//        {
//            if ()
//        }

//         void renderHealth()
//         {
//             SDL_Rect healthBar = {xPos - camera.x, yPos - camera.y, health/2, 10};
//             SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x0F, 0xFF);
//             SDL_RenderFillRect(renderer, &healthBar);

// //            for (int i = 0; i < 6; i++)
// //            {
// //                SDL_Rect healthBaroutline = {20-i, 20-i, 200+2*i, 30+2*i};
// //                SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
// //                SDL_RenderDrawRect(renderer, &healthBaroutline);
// //            }
//         }
        // void collectCoin()
        // {
        //     money++;
        //     std::cout << "couin: " << money << std::endl;
        // }
        void displayCoinCount()
        {

        }

        void update()
        {

        }

//         void attack(std::vector<Object*> objs)
//         {
//             SDL_Rect attackBox;
//             int atkScale = 2;
//             if (currentDirection == up)
//                 attackBox = {xPos-camera.x + 5, yPos - cbox.w/2 + 25 - camera.y - atkScale*cbox.h/2, cbox.w, cbox.h/2 * atkScale};
//             else if (currentDirection == down)
//                 attackBox = {xPos-camera.x + 5, yPos + cbox.w + 10 - camera.y, cbox.w, cbox.h/2 * atkScale};
//             else if (currentDirection == right)
//                 attackBox = {xPos-camera.x + cbox.w + 35, yPos - camera.y, cbox.w/2 * atkScale, cbox.h};
//             else if (currentDirection == left)
//                 attackBox = {xPos-camera.x - cbox.w + 10 - atkScale*cbox.w/2, yPos - camera.y, cbox.w/2 * atkScale, cbox.h};

//             SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x0F, 0xFF);
//             SDL_RenderFillRect(renderer, &attackBox);

//             for (auto obj : objs)
//             {
//                 std::cout << obj->getX() << "," << obj->getY() << std::endl;
//                 SDL_Rect objBox = {obj->getColBox().x - camera.x, obj->getColBox().y - camera.y, obj->getColBox().w, obj->getColBox().h};
// //                SDL_SetRenderDrawColor(renderer, 0, 255, 0, 50);
// //                SDL_RenderFillRect(renderer, &objBox);
//                 if(checkCollision(attackBox, objBox))
//                 {
//                     if(obj != this)
//                     {
//                         obj->updateStatus(5);
//                         obj->knockback(angleBetweenRect(cbox, obj->getColBox()));
// //                        std::cout << angleBetweenRect(cbox, obj->getColBox()) << std::endl;
//                         SDL_SetRenderDrawColor(renderer, 0, 0, 255, 50);
// //                        int i = 0;
// //                        while(i<10)
// //                        {
// //                            i++;
// //                            std::cout << i << std::endl;
//                             SDL_RenderFillRect(renderer, &objBox);
// //                            SDL_Delay(1000);
// //                        }
//                     }
//                 }
//             }
//         }

        void handleInput(SDL_Event& e)
        {
            if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
            {
                switch(e.key.keysym.sym)
                {
                    // case SDLK_w:
                    //     yAcc -= ACC;
                    //     break;
                    case SDLK_a:
                        xAcc -= ACC;
                        break;
                    // case SDLK_s:
                    //     yAcc += ACC;
                    //     break;
                    case SDLK_d:
                        xAcc += ACC;
                        break;
                    // case SDLK_v:
                    //     attack(objects);
                    //     charging = true;
                    //     std::cout << "pressing v" << std::endl;
                    //     break;
                    // case SDLK_f:
                    //     ACC = 1;
                    //     std::cout << "pressing F" << std::endl;
                    //     break;
                }


            }
            if (e.type == SDL_KEYUP && e.key.repeat == 0)
            {
                switch(e.key.keysym.sym)
                {
                    // case SDLK_w:
                    //     yAcc += ACC;
                    //     break;
                    case SDLK_a:
                        xAcc += ACC;
                        break;
                    // case SDLK_s:
                    //     yAcc -= ACC;
                    //     break;
                    case SDLK_d:
                        xAcc -= ACC;
                        break;
                    // case SDLK_v:
                    //     charging = false;
                    //     std::cout << "releasing v" << std::endl;
                    //     break;
                    // case SDLK_f:
                    //     ACC = 0.5;
                    //     std::cout << "release F" << std::endl;
                    //     break;
                }
            }
        }

        float getX()
        {
            return xPos;
        }

        float getY()
        {
            return yPos;
        }

    private:
        float xVel, yVel;
        float xAcc, yAcc;
        float ACC = 0.5;
        float speedCap = 5;
        float friction = 0.3;
        //float Boost = 1;

        bool charging;
        int currentDirection;
//        SDL_Rect playerCollisionBox;
};

bool init(std::string path)
{
    bool success = true;
    if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 )
		success = false;
	else
    {
		window = SDL_CreateWindow( path.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if(window == NULL)
			success = false;
		else
		{
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if(renderer == NULL)
				return false;
			else
			{
				//SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

				int imgFlags = IMG_INIT_PNG;
				if(!(IMG_Init( imgFlags ) & imgFlags))
					success = false;
                    // if( Mix_OpenAudio( 24100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
                    // {
                    //     printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
                    //     success = false;
                    // }
			}
		}
    }
    return success;
}

void quit()
{
    background.free();
    SDL_DestroyWindow(window);
    window = NULL;
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
    SDL_Quit();
}

int main(int argc, char* argv[])
{    
    if(init(WINDOW_TITLE) == false){
        cout << "Failed to initialize!" << endl;
    }
    else{
        if(background.loadFile("bg1.png") == false)
            cout << "Failed to load background!" << endl;
        if(boat.loadFile("boat.png") == false)
            cout << "Failed to load the boat!" << endl;
        else
        {    
            boatLeft = {0, 0, 32, 64};
            boatRight = {64, 0, 32, 64};

            background.render();
            SDL_RenderPresent(renderer);
            SDL_Event e; 
            bool quit = false;
            Player p(1000, 200);
            SDL_Rect testrect = {400,400,50,20};
            while (quit == false) { 

                while (SDL_PollEvent(&e)) { 
                    if (e.type == SDL_QUIT) 
                    { 
                        quit = true; 
                    } 
                    p.handleInput(e);
                } 
            }
            p.move();
            p.render();
            SDL_RenderPresent(renderer);
        }
    }

    quit();

    return 0;
}

