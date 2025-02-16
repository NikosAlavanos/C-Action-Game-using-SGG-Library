#pragma once

#include <iostream>
#include <random>
#include <string>

#include <sgg/graphics.h>

#include "Alien.h"
#include "Ripley.h"

using namespace std;

class Crawler : public Alien
{
public:
	string left_textures[6];
	string right_textures[6];
	string up_textures[6];
	string down_textures[6];

	graphics::Brush br;

	float ux = 0.01f, uy = 0.01f;
	int frame = 0;

	bool facing_left = false;
	bool facing_right = true;

	bool facing_down = true;
	bool facing_up = false;

	bool upside_down = false;

	float transformX(float world_x, Ripley* ripley);
	float transformY(float world_y, Ripley* ripley);

	Crawler(float x, float y, bool upside_down, float range_x = 0, float range_y = 0);

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

