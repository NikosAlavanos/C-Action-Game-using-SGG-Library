#pragma once

#include <iostream>
#include <random>
#include <string>

#include <sgg/graphics.h>

#include "Ripley.h"
#include "InteractiveObject.h"

class Door : public InteractiveObject
{
public:
	float width = 4;
	float height = 18.4f;
	string textures;


	graphics::Brush br;

	float ux = 0.1f, uy = 0.1f;

	float transformX(float world_x, Ripley* ripley);
	float transformY(float world_y, Ripley* ripley);

	float x = 402.0f;
	float y = 193.7f;

	Door();

	void draw(Ripley* ripley);

	void update(float ms);

	bool checkCollision(Ripley* ripley);


	virtual void applyCollisionEvent(Ripley* ripley) {

	}
};


