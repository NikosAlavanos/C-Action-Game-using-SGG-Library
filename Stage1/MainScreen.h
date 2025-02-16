#pragma once

#include <iostream>
#include <random>
#include <string>

#include <sgg/graphics.h>

#include "Screen.h"
#include "TextComponent.h"
#include "ImageComponent.h"

class MainScreen : public Screen
{
private:
	TextComponent* title;
	TextComponent* settings;
	TextComponent* exit_app;
	ImageComponent* image;
public:
	MainScreen();

	~MainScreen();

	virtual void draw();

	virtual void update(float ms);
};

