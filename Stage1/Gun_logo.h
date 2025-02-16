#pragma once

#include <iostream>
#include <random>
#include <string>

#include <sgg/graphics.h>

using namespace std;

class Gun_logo
{
public:
	float width = 8;
	float height = 7;
	string textures;

	graphics::Brush br;

	float x;
	float y;

	Gun_logo();

	void draw();

};