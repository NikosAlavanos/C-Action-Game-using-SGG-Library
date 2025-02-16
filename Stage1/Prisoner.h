#pragma once

#include <iostream>
#include <random>
#include <string>

#include <sgg/graphics.h>

#include "Ripley.h"

#include "Pickup.h"

using namespace std;

class Prisoner : public Pickup
{
public:
	string trapped_textures[5];
	string free_textures[4];


	graphics::Brush br;



	bool free = false;
	bool trapped = true;

	float transformX(float world_x, Ripley* ripley);
	float transformY(float world_y, Ripley* ripley);

	Prisoner(float x, float y);

	virtual void draw(Ripley* ripley);

	void reset();

	virtual void update(float ms);

	virtual void applyCollisionEvent(Ripley* ripley);


};

