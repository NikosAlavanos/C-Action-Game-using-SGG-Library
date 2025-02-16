#include "Gun_logo.h"

Gun_logo::Gun_logo()
{
	textures = "assets\\icons\\gun.png";

	br.outline_opacity = 0.0f;
	br.texture = "";
}

void Gun_logo::draw()
{
	br.texture = textures;

	graphics::drawRect(x, y, width, height, br);

}