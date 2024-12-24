#pragma once

#include <SDL3/SDL.h>
#include <defs.h>

class CollisionObject {
public:
    CollisionObject(SDL_FRect *hitbox);
    ~CollisionObject();

    bool isColliding(CollisionObject *body);
    bool isCollidingMouse(float mouseX, float mouseY);
private:
    SDL_FRect *hitbox;
};