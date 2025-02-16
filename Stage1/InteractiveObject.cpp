#include "InteractiveObject.h"

bool InteractiveObject::collides(Ripley* ripley, float width, float height, float x, float y) {
    float dx = (ripley->x - x);
    float dy = (ripley->y - y);

    if (dx < 0) {
        dx = -dx;
    }

    if (dy < 0) {
        dy = -dy;
    }


    if (dx < ripley->width/2 + width/2 && dy < ripley->height/2 + height/2) {
        return true;
    }
    else {
        return false;
    }
}

bool InteractiveObject::collides(Bullet* bullet, float width, float height, float x, float y) {
    float dx = (bullet->x - x);
    float dy = (bullet->y - y);

    if (dx < 0) {
        dx = -dx;
    }

    if (dy < 0) {
        dy = -dy;
    }


    if (dx < bullet->width / 2 + width / 2 && dy < bullet->height / 2 + height / 2) {
        return true;
    }
    else {
        return false;
    }
}


bool InteractiveObject::checkCollision(Ripley* ripley, float width, float height, float x, float y)
{
    if (collides(ripley, width, height, x, y)) {
        applyCollisionEvent(ripley);
        return true;
    }

    return false;
}


bool InteractiveObject::checkCollision(Bullet* bullet, float width, float height, float x, float y) {
    if (collides(bullet, width, height, x, y)) {
        return true;
    }

    return false;
}