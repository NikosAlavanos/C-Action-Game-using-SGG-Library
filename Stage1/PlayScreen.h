#pragma once

#include <iostream>
#include <random>
#include <string>
#include <vector>

#include <sgg/graphics.h>

#include "World.h"
#include "Screen.h"
#include "TextComponent.h"
#include "Ripley.h"
#include "Bullet.h"

#include "Crawler.h"
#include "Guardian.h"
#include "Upright.h"
#include "Ammunation_icon.h"
#include "Gun_logo.h"
#include "SettingsScreen.h"
#include "Health_icon.h"
#include "Prisoner.h"
#include "Door.h"
#include "Settings.h"
#include "Pickup.h"

using namespace std;

class PlayScreen : public Screen
{
private:
	World* world;
	Ripley* ripley;
	Door* door;

	// Aliens
	vector<Alien*> aliens;

	// Pickups:
	vector<Pickup*> pickups;


	vector<Gun_logo*> gun_logo;

	TextComponent* Live;
	TextComponent* Score;
	TextComponent* Energy;
	TextComponent* Prisoners;
	TextComponent* Time;
	vector<Bullet*> bullets;


	TextComponent* gun_bullets_value;
	TextComponent* live_value;
	TextComponent* score_value;
	TextComponent* energy_value;
	TextComponent* prisoners_value;
	TextComponent* time_value;

	Settings* settings;

	float time;
	float game_starting_time = 0;
public:
	bool victory = false;
	PlayScreen(Settings* settings, Ripley* ripley);

	~PlayScreen();

	void scoreIncrease();

	void timeDecrease();

	virtual void draw();
	virtual void update(float ms);

	bool timeExpired() const;

};

