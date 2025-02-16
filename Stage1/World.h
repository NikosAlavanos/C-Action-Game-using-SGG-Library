#pragma once

#include "ImageComponent.h"
#include "Ripley.h"

class World  : public ImageComponent 
{
public:

	World();

	float transformX(float world_x, Ripley* ripley);
	float transformY(float world_y, Ripley* ripley);

	void draw(Ripley* ripley);
};

