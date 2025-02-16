#include "Door.h"
#include "Door.h"

float Door::transformX(float alien_x, Ripley* ripley) {
	return alien_x - ripley->x + 50;
}

float Door::transformY(float alien_y, Ripley* ripley) {
	return alien_y - ripley->y + 80;
}

Door::Door()
{
	textures = "assets\\icons\\Door.png";
	br.outline_opacity = 0;
	br.texture = "";

}

void Door::draw(Ripley* ripley)
{

	br.texture = textures;
	if (ripley->prisoners != 0) {
		graphics::drawRect(transformX(x, ripley), transformY(y, ripley), width, height, br);
	}
	

}

void Door::update(float ms) {
	
}

bool Door::checkCollision(Ripley* ripley)
{
	return InteractiveObject::checkCollision(ripley, width, height, x, y);
}
