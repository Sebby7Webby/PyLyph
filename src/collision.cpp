#include <collision.h>
#include <iostream>
#include <initializer_list>

CollisionObject::CollisionObject(SDL_FRect *hitbox)
 : hitbox(hitbox) {}

CollisionObject::~CollisionObject() {}

bool CollisionObject::isColliding(CollisionObject *body) {
    SDL_FRect *BodyHB = body->hitbox;

    if (hitbox->x < BodyHB->x+BodyHB->w &&
        hitbox->x+hitbox->w > BodyHB->x &&
        hitbox->y < BodyHB->y+BodyHB->h &&
        hitbox->y+hitbox->h > BodyHB->y) {return true;}
    return false;
}

bool CollisionObject::isCollidingMouse(float mouseX, float mouseY) {
    if (hitbox->x <= mouseX && mouseX <= hitbox->x+hitbox->w && hitbox->y <= mouseY && mouseY <= hitbox->y+hitbox->h) {
        return true;
    }
    return false;
}