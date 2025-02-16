#pragma once

#include <iostream>
#include <random>
#include <string>

#include <sgg/graphics.h>
#include "Ripley.h"

#include "Pickup.h"

using namespace std;

class Health_icon : public Pickup
{
public:
	string textures;

	graphics::Brush br;

	float transformX(float world_x, Ripley* ripley);
	float transformY(float world_y, Ripley* ripley);

	Health_icon(float x, float y);

	
	virtual void update(float ms);

	virtual void draw(Ripley* ripley);

	virtual void applyCollisionEvent(Ripley* ripley);
};