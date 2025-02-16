#pragma once

#include <iostream>
#include <random>
#include <string>

#include <sgg/graphics.h>
#include "Ripley.h"
#include "Pickup.h"

using namespace std;

class Ammunation_icon : public Pickup
{
public:

	string textures;

	graphics::Brush br;
	int frame = 0;

	float transformX(float world_x, Ripley* ripley);
	float transformY(float world_y, Ripley* ripley);

	Ammunation_icon(float x,float y);

	virtual void update(float ms);

	virtual void draw(Ripley* ripley);

	virtual void applyCollisionEvent(Ripley* ripley);
};

