#include "Bullet.h"

#include "Constants.h"
float Bullet::transformX(float alien_x, Ripley* ripley) {
	return alien_x - ripley->x + 50;
}

float Bullet::transformY(float alien_y, Ripley* ripley) {
	return alien_y - ripley->y + 80;
}

Bullet::Bullet(float x, float y, Direction direction) : x(x), y(y), direction(direction)
{
	textures = "assets\\icons\\Bullets\\b1.png";

	br.outline_opacity = 0.0f;
	br.texture = "";

	spawn_timestamp = graphics::getGlobalTime();
}

void Bullet::update(float ms)
{
	if (direction == Direction::LEFT) {
		x = x - ux * ms;
	}
	else {
		x = x + ux * ms;
	}

}

bool Bullet::expired() const
{
	float t = graphics::getGlobalTime();

	if (t - spawn_timestamp > Constants::BULLET_LIFETIME) {
		return true;
	}
	return false;

}

void Bullet::draw(Ripley* ripley)
{
	br.texture = textures;

	br.texture = "assets\\icons\\Bullets\\b1.png";

	graphics::drawRect(transformX(x, ripley), transformY(y, ripley), width, height, br);
}

void Bullet::applyCollisionEvent(Ripley* ripley)
{
	ripley->healthIncrease();
}
