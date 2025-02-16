#include "Pickup.h"

#include <cmath>

Pickup::Pickup(float width, float height, float x, float y) : width(width), height(height), x(x), y(y)
{
}

bool Pickup::checkCollision(Ripley* ripley)
{
    return InteractiveObject::checkCollision(ripley, width, height, x, y);
}
