#pragma once

#include <string>

#include "Drawable.h"

using namespace std;

class TextComponent : public Drawable
{
private:
	float x;
	float y;
	float size;
	string content;	
	graphics::Brush br;
public:
	TextComponent(float x, float y, float size, string content);


	string getContent();

	void setContent(string content);

	void setX(float x);

	void setY(float y);


	void draw();

	void update(float ms);

};

