#pragma once

#include <iostream>
#include <random>
#include <string>

#include <sgg/graphics.h>

#include "Alien.h"
#include "Ripley.h"

using namespace std;

class Guardian : public Alien
{
public:
	string left_textures[10];
	string right_textures[10];


	graphics::Brush br;

	float ux = 0.01f, uy = 0.01f;
	int frame = 0;

	bool facing_left = false;
	bool facing_right = true;

	float transformX(float world_x, Ripley* ripley);
	float transformY(float world_y, Ripley* ripley);

	Guardian(float x, float y, float range_x = 0, float range_y = 0);

	void draw(Ripley* ripley);

	void reset();

	void update(float ms);

	void left(float distance);

	void right(float distance);

	void up(float distance);

	void down(float distance);

	virtual void applyCollisionEvent(Ripley* ripley);

	virtual int getScore();
	//void jump();

	//void crawl();
};

