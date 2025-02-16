#include "World.h"

#define WORLD_WIDTH 1360
#define WORLD_HEIGHT 720
#define SCALE_FACTOR 0.3f

#include "Ripley.h"

float World::transformX(float world_x, Ripley* ripley) {
	return world_x + width / 2 + 50 - ripley->x;
}

float World::transformY(float world_y, Ripley* ripley) {
	return world_y + height / 2 + 80 - ripley->y;
}

World::World() : ImageComponent(0,0,1360* SCALE_FACTOR,720* SCALE_FACTOR, "assets\\background\\background.png")
{

}

void World::draw(Ripley * ripley) {
	graphics::drawRect(transformX(x, ripley), transformY(y, ripley), width, height, br);
}