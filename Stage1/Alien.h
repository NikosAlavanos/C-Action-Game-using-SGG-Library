#pragma once

#include "Ripley.h"
#include "InteractiveObject.h"

class Alien : public InteractiveObject
{	
public:
	float width;
	float height;
	float x;
	float y;
	float min_x;
	float max_x;
	float min_y;
	float max_y;
	float frame_timer = 0;
	float ux = 0.1f, uy = 0.1f;
	float health;

	Alien(float width, float height, float x, float y, float range_x = 0, float range_y = 0, float health = 3);

	void decreaseHealth();

	bool checkCollision(Ripley * ripley);

	bool checkCollision(Bullet * ripley);

	virtual void update(float ms) = 0;

	virtual void draw(Ripley* ripley) = 0;

	virtual int getScore() = 0;
};

