#pragma once

#pragma once

#include <iostream>
#include <random>
#include <string>
#include <list>

#include <sgg/graphics.h>

#include "Screen.h"
#include "TextComponent.h"
#include "ImageComponent.h"
#include "Ripley.h"

class VictoryScreen : public Screen
{
private:
	list<Drawable*> items;
	list<Drawable*> statistics;
	Ripley* ripley;
public:
	VictoryScreen(Ripley* ripley);

	~VictoryScreen();

	virtual void draw();

	virtual void update(float ms);

	virtual void calculateBonus();
};

