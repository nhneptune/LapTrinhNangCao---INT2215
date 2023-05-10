#include "object.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

const int LIMIT_LEFT = 0;
const int LIMIT_RIGHT = 640;
const int LIMIT_TOP = 0;
const int LIMIT_BOTTOM = 480;

void Object::loadTexture(SDL_Renderer* renderer, char* path, int p_texture_width, int p_texture_height)
{
    txtr = IMG_LoadTexture(renderer, path);
    texture_width = p_texture_width;
    texture_height = p_texture_height;
    if (txtr == NULL)
    {
        SDL_Log("Failed to load texture: %s", SDL_GetError());
    }
}

void Object::setPos(int x, int y)
    {
        xPos = x;
        yPos = y;
        cbox.x = xPos;
        cbox.y = yPos;
    }

void Object::move(int p_x, int p_y)
{
    xPos += p_x;
    yPos += p_y;
    cbox.x = xPos;
    cbox.y = yPos;
}
 
void Object::render(SDL_Renderer* renderer)
{
    SDL_Rect src = {0, 0, texture_width, texture_height};
    SDL_Rect dest = {xPos, yPos, width, height};
    SDL_RenderCopy(renderer, txtr, &src, &dest);
}

int Object::getX()
{
    return xPos;
}

int Object::getY()
{
    return yPos;
}

int Object::getHeight()
{
    return height;
}

int Object::getWidth()
{
    return width;
}

SDL_Rect Object::getColBox()
{
    return cbox;
}

bool Object::checkCollision(Object obj)
{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = cbox.x;
    rightA = cbox.x + cbox.w;
    topA = cbox.y;
    bottomA = cbox.y + cbox.h;

    //Calculate the sides of rect B
    leftB = obj.getColBox().x;
    rightB = obj.getColBox().x + obj.getColBox().w;
    topB = obj.getColBox().y;
    bottomB = obj.getColBox().y + obj.getColBox().h;

    // Check if any side of A is outside B
    if (bottomA <= topB) return false;
    if (topA >= bottomB) return false;
    if (rightA <= leftB) return false;
    if (leftA >= rightB) return false;
    return true;
}

// Boat
Boat::Boat()
{ 
    width = 128;
    height = 64;

}

void Boat::moveBoat(int p_move)
{
    if (p_move == 0) return;
    if (p_move > 0) right[1] = true;
    if (p_move < 0) right[1] = false;
    if (getX() + p_move < LIMIT_LEFT) return;
    if (getX() + p_move > LIMIT_RIGHT - getWidth()) return;
    move(p_move);
}

void Boat::render(SDL_Renderer* renderer)
{
    SDL_Rect src = {0, 0, texture_width, texture_height};
    SDL_Rect dest = {xPos, yPos, width, height};
    if (right[1]) src.x = texture_width * 1;
    else src.x = texture_width * 0;
    right[0] = right[1];
    SDL_RenderCopy(renderer, txtr, &src, &dest);
}

bool Boat::turnDirection()
{
    if (right[0] != right[1]) return true;
    return false;
}

// Fish
Fish::Fish()
{
    width = 20;
    height = 12;
    cbox = {xPos, yPos, width, height};
}

void Fish::moveFish(int p_move)
{
    if (p_move == 0) return;
    if (getX() + p_move < LIMIT_LEFT) p_move = 0;
    if (getX() + p_move > LIMIT_RIGHT - getWidth()) p_move = 0;
    move(p_move);
}

void Fish::copyTexture(Fish fish)
{
    txtr = fish.txtr;
    texture_width = fish.texture_width;
    texture_height = fish.texture_height;
};

void Fish::gotHooked()
{
    hooked = true;
}

bool Fish::isHooked()
{
    return hooked;
}
// Hook quay sang phai van bi loi
Hook::Hook()
{
    width = 32;
    height = 28;
    cbox = {xPos, yPos, width, height};
}

void Hook::moveHook(int p_moveX, int p_moveY){
    if (p_moveX == 0 && p_moveY == 0) return;
    if (getX() + p_moveX < LIMIT_LEFT + 6) return;
    if (getX() + p_moveX > LIMIT_RIGHT - getWidth() - 10) return;
    if (getY() + p_moveY > LIMIT_BOTTOM - getHeight()) return;
    if (getY() + p_moveY < LIMIT_TOP) return;
    move(p_moveX, p_moveY);
}

bool Hook::isMoving() {
    return (isMovingUp || isMovingDown);
}

void Hook::start() {
    if (!isMoving()) {
        moveHook(0,10);
        isMovingDown = true;
        isMovingUp = false;
    }
}

void Hook::update() {
    int speed = 2; // pixel per frame
    if (isMovingDown) {
        moveHook(0,speed);
        if (getY() >= 480 - getHeight() - 10) {
            isMovingDown = false;
            isMovingUp = true;
        }
    }
    if (isMovingUp) {
        moveHook(0,-speed);
        if (getY() <= 58) {
            isMovingDown = false;
            isMovingUp = false;
            while (getY() < 54) moveHook(0,-1);
        }
    }
}

void Hook::catchFish() {
    isMovingDown = false;
    isMovingUp = true;
}

// Rope 
Rope::Rope()
{
    width = 10;
    height = 426;
}

void Rope::render(SDL_Renderer* renderer, int length)
{
    SDL_Rect src = {0, 0, 4, length};
    SDL_Rect dest = {xPos, yPos, width, length};
    SDL_RenderCopy(renderer, txtr, &src, &dest);
}

void Rope::moveRope(int p_moveX, int p_moveY){
    if (p_moveX == 0 && p_moveY == 0) return;
    if (getX() + p_moveX < LIMIT_LEFT + 20) return;
    if (getX() + p_moveX > LIMIT_RIGHT - getWidth() - 20) return;
    move(p_moveX, p_moveY);
}