#pragma once

#include <string>

#include <sgg/graphics.h>

#include "Drawable.h"

using namespace std;

class ImageComponent : public Drawable
{
protected:
	float x;
	float y;
	float width;
	float height;
	string texture;
	graphics::Brush br;
public:
	ImageComponent(float x, float y, float width, float height, string texture);

	void draw();

	void update(float ms);

};

