#pragma once

#include <SDL3/SDL.h>
#include <defs.h>

class CollisionObject {
public:
    CollisionObject(float x, float y, float w, float h);
    CollisionObject(SDL_FRect *hitBox);
    ~CollisionObject();

    bool isColliding(CollisionObject *body);
private:
    DEFS::Coordinates TopLeft;
    DEFS::Coordinates TopRight;
    DEFS::Coordinates BottomLeft;
    DEFS::Coordinates BottomRight;
};