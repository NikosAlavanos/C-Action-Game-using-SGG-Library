#pragma once
#include <iostream>
#include <random>
#include <string>

#include <sgg/graphics.h>

#include "Screen.h"
#include "TextComponent.h"

class PauseScreen : public Screen
{
private:
	TextComponent* title;
	TextComponent* play;
	TextComponent* options;
	TextComponent* main_menu;
	TextComponent* exit_app;

public:
	PauseScreen();

	~PauseScreen();

	virtual void draw();

	virtual void update(float ms);
};

