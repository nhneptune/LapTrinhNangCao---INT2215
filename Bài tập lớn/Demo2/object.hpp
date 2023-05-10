#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream> 
#include <string>

class Object
{
protected:
    int width, height;
    int texture_width;
    int texture_height;
    int xPos = 0, yPos = 0; 
    SDL_Rect cbox;
    SDL_Texture* txtr;
public:
    void loadTexture(SDL_Renderer* renderer, char* path, int p_texture_width, int p_texture_height);

    void move(int p_x, int p_y = 0);

    void setPos(int x, int y);
    
    virtual void render(SDL_Renderer* renderer);

    int getX();

    int getY();

    int getHeight();

    int getWidth();

    SDL_Rect getColBox();

    bool checkCollision(Object obj);
};


class Boat : public Object
{
    private:
        bool right[2] = {false, true}; // true: right, false: left
    public:
        Boat();
        void moveBoat(int p_move);
        void render(SDL_Renderer* renderer);
        bool turnDirection();
};      

class Fish : public Object
{
    private:
        bool hooked = false;
    public:
        Fish();
        void copyTexture(Fish fish);
        void moveFish(int p_move);
        void gotHooked();
        bool isHooked();
};

class Hook : public Object
{
    private:
        bool isMovingUp = true;
        bool isMovingDown = true;
    public:
        Hook();
        void moveHook(int p_moveX, int p_moveY);
        bool isMoving();
        void update();
        void start();
        void catchFish();
};

class Rope : public Object
{
    private:
    public:
        Rope();
        void render(SDL_Renderer* renderer, int length);
        void moveRope(int p_moveX, int p_moveY);
};

