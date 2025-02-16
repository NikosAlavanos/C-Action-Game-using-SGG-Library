#include <iostream>

#include "Settings.h"
#include "SettingsScreen.h"

using namespace std;

SettingsScreen::SettingsScreen(Settings* settings) : settings(settings)
{
	cout << "Setting up main screen ... " << endl;

	image = new ImageComponent(50, 50, 50.0f * 2.0f, 50.0f * 4.0f, "assets\\settings\\settings.png");

	options = new TextComponent(30.0f, 20.0f, 10.0f, "OPTIONS");
	tries = new TextComponent(20.0f, 35.0f, 5.0f, "TOTAL TRIES : ");
	difficulty = new TextComponent(20.0f, 45.0f, 5.0f, "DIFFICULTY : ");
	music = new TextComponent(20.0f, 55.0f, 5.0f, "MUSIC : ");
	sound = new TextComponent(20.0f, 65.0f, 5.0f, "SOUND : ");
	exit_settings_app = new TextComponent(20.0f, 80.0f, 5.0f, "PRESS SPACE TO GO BACK");

	tries_value = new TextComponent(70.0f, 35.0f, 5.0f, "");
	difficulty_value = new TextComponent(70.0f, 45.0f, 5.0f, "");
	sound_value = new TextComponent(70.0f, 65.0f, 5.0f, "");
	music_value = new TextComponent(70.0f, 55.0f, 5.0f, "");

	selector = new TextComponent(15.0f, 35.0f, 5.0f, "*");
}

SettingsScreen :: ~SettingsScreen()
{
	cout << "cleaning up setting screen" << endl;

	delete image;
	delete options;
	delete tries;
	delete difficulty;
	delete music;
	delete sound;
	delete exit_settings_app;
	delete tries_value;
	delete difficulty_value;
	delete sound_value;
	delete music_value;
	delete selector;
}

void SettingsScreen::draw()
{
	image->draw();
	options->draw();
	tries->draw();
	difficulty->draw();
	music->draw();
	sound->draw();
	exit_settings_app->draw();

	tries_value->setContent(std::to_string(settings->tries));
	tries_value->draw();
	difficulty_value->setContent(settings->getDifficultyText());
	difficulty_value->draw();
	sound_value->setContent(std::to_string((int)(10 * settings->fx_volume)));
	sound_value->draw();
	music_value->setContent(std::to_string((int)(10 * settings->music_volume)));
	music_value->draw();

	selector->setY(35.0f + selectedOption * 10);
	selector->draw();
}

void SettingsScreen::update(float ms)
{
}

void SettingsScreen::optionUp()
{
	if (selectedOption > 0) {
		selectedOption--;
	}
}

void SettingsScreen::optionDown()
{
	if (selectedOption < 3) {
		selectedOption++;
	}
}


void SettingsScreen::difficultyIncrease()
{
	switch (settings->difficulty) {
	case EASY:
		settings->difficulty = MEDIUM;
		break;
	case MEDIUM:
		settings->difficulty = HARD;
		break;
	default:
		break;
	}

	//cout << "difficulty set to: " << settings->difficulty << " " << settings->getDifficultyText() << endl;
}

void SettingsScreen::difficultyDecrease()
{
	switch (settings->difficulty) {
	case MEDIUM:
		settings->difficulty = EASY;
		break;
	case HARD:
		settings->difficulty = MEDIUM;
		break;
	default:
		break;
	}

	cout << "difficulty set to: " << settings->difficulty << " " << settings->getDifficultyText() << endl;
}

void SettingsScreen::musicIncrease()
{
	if (settings->music_volume < 1) {
		settings->music_volume = settings->music_volume + 0.1f;
	}
}

void SettingsScreen::musicDecrease()
{
	if (settings->music_volume > 0.1) {
		settings->music_volume = settings->music_volume - 0.1f;
	}
}

void SettingsScreen::volumeIncrease()
{
	if (settings->fx_volume < 1) {
		settings->fx_volume = settings->fx_volume + 0.1f;
	}
}

void SettingsScreen::volumeDecrease()
{
	if (settings->fx_volume > 0.1) {
		settings->fx_volume = settings->fx_volume - 0.1f;
	}
}

void SettingsScreen::increase()
{
	/*if (selectedOption == 0) {
		triesIncrease();
	}*/

	if (selectedOption == 1) {
		difficultyIncrease();
	}

	if (selectedOption == 2) {
		musicIncrease();
	}

	if (selectedOption == 3) {
		volumeIncrease();
	}
}

void SettingsScreen::decrease()
{

	if (selectedOption == 1) {
		difficultyDecrease();
	}

	if (selectedOption == 2) {
		musicDecrease();
	}

	if (selectedOption == 3) {
		volumeDecrease();
	}
}
