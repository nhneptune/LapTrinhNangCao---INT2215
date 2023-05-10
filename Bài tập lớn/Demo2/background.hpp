#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Background 
{
private:
    SDL_Texture* background;
    //SDL_Rect dest;
    int screen_width;
    int screen_height;
    int posX;
    int posY;
    Uint32 timePerFrame;
    int scrollingOffset;
    Uint32 lastTime;
public:
    Background(SDL_Renderer* renderer, const char* path, int p_posX, int p_posY, int p_screen_width, int p_screen_heigh, float pixelPerSecond = 0);
    void loadTexture(SDL_Renderer* renderer, const char* path);
    void setSpeed(float p_pixelPerSecond);
    void render(SDL_Renderer* renderer);
};
