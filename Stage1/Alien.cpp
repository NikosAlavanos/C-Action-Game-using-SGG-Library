
#include <cmath>

#include "Alien.h"
#include "Bullet.h"

Alien::Alien(float width, float height, float x, float y, float range_x, float range_y, float health) : width(width), height(height), x(x), y(y), health(health)
{
    min_x = x - range_x;
    max_x = x + range_x;

    min_y = y - range_y;
    max_y = y + range_y;


    if (range_x > 0) {
        this->x = (rand() % ((int)(max_x - min_x + 1))) + min_x;
    }

    if (range_y > 0) {
        this->y = (rand() % ((int)(max_x - min_x + 1))) + min_x;
    }

}

void Alien::decreaseHealth()
{
    health--;
}

bool Alien::checkCollision(Ripley* ripley)
{
    return InteractiveObject::checkCollision(ripley, width, height, x, y);
}


bool Alien::checkCollision(Bullet* bullet) {
    return InteractiveObject::checkCollision(bullet, width, height, x, y);

}