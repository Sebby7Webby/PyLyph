#include <collision.h>
#include <iostream>
#include <initializer_list>

CollisionObject::CollisionObject(float x, float y, float w, float h) {
    TopLeft = DEFS::Coordinates{x, y};
    TopRight = DEFS::Coordinates{x+w, y};
    BottomLeft = DEFS::Coordinates{x, y+h};
    BottomRight = DEFS::Coordinates{x+w, y+h};
}

CollisionObject::CollisionObject(SDL_FRect *hitBox) {
    TopLeft = DEFS::Coordinates{hitBox->x, hitBox->y};
    TopRight = DEFS::Coordinates{hitBox->x+hitBox->w, hitBox->y};
    BottomLeft = DEFS::Coordinates{hitBox->x, hitBox->y+hitBox->h};
    BottomRight = DEFS::Coordinates{hitBox->x+hitBox->w, hitBox->y+hitBox->h};
}

CollisionObject::~CollisionObject() {}

bool CollisionObject::isColliding(CollisionObject *body) {
    for (DEFS::Coordinates *point : {&body->TopLeft, &body->TopRight, &body->BottomLeft, &body->BottomRight}) {
        if (!(TopLeft.x >= point->x >= BottomRight.x && TopLeft.y >= point->y >= BottomRight.y)) {
            continue;
        }

        if (point == &body->BottomLeft) {
            std::cout << "bl\n";
        } else if (point == &body->BottomRight) {
            std::cout << "br\n";
        } else if (point == &body->TopLeft) {
            std::cout << "tl\n";
        } else {
            std::cout << "tr\n";
        }

    }
    return false;
}