#include "VictoryScreen.h"
#include <iostream>

#include "Ripley.h"
using namespace std;

VictoryScreen::VictoryScreen(Ripley* ripley) : ripley(ripley)
{
	cout << "Setting up Death screen ... " << endl;
	items.push_back(new ImageComponent(50, 50, 100.0f, 100.0f, "assets\\Victory\\Victory.png"));
	items.push_back(new TextComponent(27.5f, 20.0f, 10.0f, "VICTORY"));
	items.push_back(new TextComponent(15.0f, 90.0f, 6.0f, "PRESS TAB TO GO TO THE"));
	items.push_back(new TextComponent(35.0f, 96.0f, 6.0f, "MAIN MENU"));
}

VictoryScreen :: ~VictoryScreen()
{
	cout << "Cleaning up Death screen ... " << endl;

	for (auto item : items) {
		delete item;
	}
}

void VictoryScreen::draw()
{
	for (auto item : items) {
		item->draw();
	}

	for (auto item : statistics) {
		item->draw();
	}
}

void VictoryScreen::update(float ms)
{

}

void VictoryScreen::calculateBonus()
{
	statistics.clear();

	float remaining_time_ms = ripley->remaining_time_ms;
	int remaining_time_sec = (int)(remaining_time_ms / 1000);
	int minutes = remaining_time_sec / 60;
	int seconds = remaining_time_sec % 60;
	int bonus_from_time = remaining_time_sec * 100;
	int bonus_from_bullets = ripley->gun_bullets * 10;
	int prisoners = 8 - ripley->prisoners;
	int bonus_from_prisoners = prisoners * 500;

	string timestamp = std::to_string(minutes) + ":" + std::to_string(seconds);


	statistics.push_back(new TextComponent(20.0f, 30.0f, 6.0f, "SCORE:  " + std::to_string(ripley->score)));
	statistics.push_back(new TextComponent(20.0f, 40.0f, 6.0f, "TIME: " + std::to_string(remaining_time_sec) + " x 100 = " + std::to_string(bonus_from_time)));
	statistics.push_back(new TextComponent(20.0f, 50.0f, 6.0f, "PRISONERS: " + std::to_string(prisoners) + "x 500 = " + std::to_string(bonus_from_prisoners)));
	statistics.push_back(new TextComponent(20.0f, 60.0f, 6.0f, "BULLETS: " + std::to_string(ripley->gun_bullets) + "x 10 = " + std::to_string(bonus_from_bullets)));


	ripley->score += bonus_from_time;
	ripley->score += bonus_from_bullets;
	ripley->score += bonus_from_prisoners;

	statistics.push_back(new TextComponent(25.0f, 75.0f, 6.0f, "Final Score: " + std::to_string(ripley->score)));
}
