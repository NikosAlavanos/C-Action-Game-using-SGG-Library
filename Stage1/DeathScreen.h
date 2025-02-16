#pragma once

#include <iostream>
#include <random>
#include <string>
#include <list>

#include <sgg/graphics.h>

#include "Screen.h"
#include "TextComponent.h"
#include "ImageComponent.h"


class DeathScreen : public Screen
{
private:
	list<Drawable*> items;

public:
	DeathScreen();

	~DeathScreen();

	virtual void draw();

	virtual void update(float ms);
};

