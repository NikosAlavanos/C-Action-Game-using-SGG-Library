#pragma once

#pragma once

#include <iostream>
#include <random>
#include <string>

#include <sgg/graphics.h>
#include "Ripley.h"


using namespace std;

enum Direction {
	LEFT = 1,
	RIGHT = 2
};

class Bullet 
{
public:
	string textures;
	float width = 2;
	float height = 2;
	float x;
	float y;
	float ux = 0.15f;

	Direction direction;
	
	graphics::Brush br;

	float spawn_timestamp;

	float transformX(float world_x, Ripley* ripley);
	float transformY(float world_y, Ripley* ripley);

	Bullet(float x, float y, Direction direction);

	bool expired() const;

	virtual void update(float ms);

	virtual void draw(Ripley* ripley);

	virtual void applyCollisionEvent(Ripley* ripley);
};

