#include "Ammunation_icon.h"

float Ammunation_icon::transformX(float alien_x, Ripley* ripley) {
	return alien_x - ripley->x + 50;
}

float Ammunation_icon::transformY(float alien_y, Ripley* ripley) {
	return alien_y - ripley->y + 80;
}

Ammunation_icon::Ammunation_icon(float x, float y) : Pickup(3.5, 4.5, x, y)
{
	textures = "assets\\icons\\Ammo.png";

	br.outline_opacity = 0.0f;
	br.texture = "";
}

void Ammunation_icon::update(float ms)
{

}

void Ammunation_icon::draw(Ripley* ripley)
{
	br.texture = textures[frame];


	br.texture = "assets\\icons\\Ammo.png";

	graphics::drawRect(transformX(x, ripley), transformY(y, ripley), width, height, br);

}

void Ammunation_icon::applyCollisionEvent(Ripley* ripley)
{
	ripley->gunBulletsIncrease();
}

