#pragma once

#include "Ripley.h"
#include "InteractiveObject.h"

class Pickup : public InteractiveObject
{
public:
	float width;
	float height;
	float x;
	float y;
	float frame_timer = 0;
	float ux = 0.1f, uy = 0.1f;

	Pickup(float width, float height, float x, float y);


	bool checkCollision(Ripley* ripley);

	virtual void update(float ms) = 0;

	virtual void draw(Ripley* ripley) = 0;
};
