#include "Health_icon.h"

float Health_icon::transformX(float alien_x, Ripley* ripley) {
	return alien_x - ripley->x + 50;
}

float Health_icon::transformY(float alien_y, Ripley* ripley) {
	return alien_y - ripley->y + 80;
}

Health_icon::Health_icon(float x, float y) : Pickup(4,4, x, y)
{
	textures = "assets\\icons\\Health_pack.png";

	br.outline_opacity = 0.0f;
	br.texture = "";
}

void Health_icon::update(float ms)
{

}

void Health_icon::draw(Ripley* ripley)
{
	br.texture = textures;

	br.texture = "assets\\icons\\Health_pack.png";

	graphics::drawRect(transformX(x, ripley), transformY(y, ripley), width, height, br);
}

void Health_icon::applyCollisionEvent(Ripley* ripley)
{
	ripley->healthIncrease();
}