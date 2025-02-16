#pragma once

#include <iostream>
#include <random>
#include <string>

#include <sgg/graphics.h>

#include "Screen.h"
#include "Settings.h"
#include "TextComponent.h"
#include "ImageComponent.h"

class SettingsScreen : public Screen
{
private:
	TextComponent* options;
	TextComponent* tries;
	TextComponent* difficulty;
	TextComponent* music;
	TextComponent* sound;
	TextComponent* exit_settings_app;

	TextComponent* tries_value;
	TextComponent* difficulty_value;
	TextComponent* sound_value;
	TextComponent* music_value;

	TextComponent* selector;

	ImageComponent* image;

	Settings* settings;

	int selectedOption = 0;
public:
	SettingsScreen(Settings* settings);

	~SettingsScreen();

	virtual void draw();

	virtual void update(float ms);

	void optionUp();

	void optionDown();

	void difficultyIncrease();

	void difficultyDecrease();

	void musicIncrease();

	void musicDecrease();

	void volumeIncrease();

	void volumeDecrease();

	void increase();

	void decrease();
};