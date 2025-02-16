#include <iostream>
#include <random>
#include <string>

#include <sgg/graphics.h>

#include "MainScreen.h"
#include "PlayScreen.h"
#include "SettingsScreen.h"
#include "vecmath.h"
#include "PauseScreen.h"
#include "DeathScreen.h"
#include "Ripley.h"
#include "VictoryScreen.h"
#include "Settings.h"

#include "Audio.h"

static const std::string assets_path = "assets/";

class Game {
public:
	Settings* settings;
	Ripley* ripley;

	const float canvas_width = 100.0f;
	const float canvas_height = 100.0f;

	MainScreen* main;
	PlayScreen* playScreen;
	SettingsScreen* settingsScreen;
	PauseScreen* pauseScreen;
	DeathScreen* deathScreen;
	VictoryScreen* victoryScreen;


	Screen* currentScreen;
	Screen* previousScreen;


	bool spacePressed = false;
	bool wPressed = false;
	bool sPressed = false;
	bool aPressed = false;
	bool dPressed = false;
	bool tabPressed = false;


	Game() {
		settings = new Settings();

		Audio::setSettings(settings);

		main = new MainScreen();
		ripley = new Ripley();
		playScreen = nullptr;
		settingsScreen = new SettingsScreen(settings);
		pauseScreen = new PauseScreen();
		deathScreen = new DeathScreen();
		victoryScreen = new VictoryScreen(ripley);

		currentScreen = main;
		previousScreen = nullptr;
	}

	~Game() {
		delete ripley;
		delete settings;
		delete main;
		if (playScreen != nullptr) {
			delete playScreen;
		}
		delete settingsScreen;
		delete pauseScreen;
		delete deathScreen;
		delete victoryScreen;
	}

	// Initialize variables
	void init() {
		graphics::Brush br;
		br.fill_color[0] = 0.1f;
		br.fill_color[1] = 0.1f;
		br.fill_color[2] = 0.1f;
		graphics::setWindowBackground(br);
		graphics::setFont(assets_path + "orange juice 2.0.ttf");

		std::random_device seed;
		std::default_random_engine generator(seed());
		std::uniform_real_distribution<float> distribution(-1.0, 1.0);

		Audio::playMainMenuMusic();
	}
};

void drawText() {
	Game* game = (Game*)graphics::getUserData();

	graphics::Brush br;
	br.fill_secondary_color[0] = 1.0f;
	br.fill_secondary_color[1] = 1.0f;
	br.fill_secondary_color[2] = 1.0f;
}


void update(float ms)
{
	Game* game = (Game*)graphics::getUserData();


	//
	// Win and lose conditions
	//
	if (game->currentScreen == game->playScreen) {
		game->playScreen->update(ms);
		game->ripley->update(ms);

		if (game->ripley->lives == 0 || game->playScreen->timeExpired()) {
			game->currentScreen = game->deathScreen;
			Audio::playDeathScreenMusic();
			game->previousScreen = game->playScreen;
		}

		if (game->playScreen->victory) {
			game->currentScreen = game->victoryScreen;
			game->victoryScreen->calculateBonus();
			Audio::playVictoryScreenMusic();
			game->previousScreen = nullptr;
		}


	}

	if (game->currentScreen == game->deathScreen) {
		game->deathScreen->update(ms);
		if (graphics::getKeyState(graphics::SCANCODE_SPACE) && !game->spacePressed) {
			if (game->playScreen != nullptr) {
				delete game->playScreen;
			}
			game->playScreen = new PlayScreen(game->settings, game->ripley);
			Audio::playStage1Music();
			game->currentScreen = game->playScreen;
			game->previousScreen = nullptr;
			game->ripley->reset();
		}
		if (graphics::getKeyState(graphics::SCANCODE_TAB)) {
			game->currentScreen = game->main;
			Audio::playMainMenuMusic();
			game->previousScreen = nullptr;
		}
	}

	if (game->currentScreen == game->victoryScreen) {
		game->victoryScreen->update(ms);

		if (graphics::getKeyState(graphics::SCANCODE_TAB)) {
			game->currentScreen = game->main;
			Audio::playMainMenuMusic();
			game->previousScreen = nullptr;
		}
	}


	if (game->currentScreen == game->main) {
		if (graphics::getKeyState(graphics::SCANCODE_SPACE) && !game->spacePressed) {
			Audio::playKeySound();
			if (game->playScreen != nullptr) {
				delete game->playScreen;
			}
			game->playScreen = new PlayScreen(game->settings, game->ripley);
			Audio::playStage1Music();
			game->currentScreen = game->playScreen;
			game->previousScreen = game->main;
			game->ripley->reset();
		}

		if (graphics::getKeyState(graphics::SCANCODE_F1)) {
			game->currentScreen = game->settingsScreen;
			game->previousScreen = game->main;
		}

	}
	else if (game->currentScreen == game->playScreen) {
		if (graphics::getKeyState(graphics::SCANCODE_Q)) {
			Audio::playMainMenuMusic();

			game->currentScreen = game->main;
			game->previousScreen = game->playScreen;
		}

		if (graphics::getKeyState(graphics::SCANCODE_F1)) {
			game->currentScreen = game->settingsScreen;
			game->previousScreen = game->playScreen;
		}

		if (graphics::getKeyState(graphics::SCANCODE_P)) {
			game->currentScreen = game->pauseScreen;
			game->previousScreen = game->playScreen;
		}

	}
	else if (game->currentScreen == game->settingsScreen) {
		if (graphics::getKeyState(graphics::SCANCODE_SPACE) && !game->spacePressed) {
			game->currentScreen = game->previousScreen;
			game->previousScreen = nullptr;

		}

		if (graphics::getKeyState(graphics::SCANCODE_W) && !game->wPressed) {
			game->settingsScreen->optionUp();
		}

		if (graphics::getKeyState(graphics::SCANCODE_S) && !game->sPressed) {
			game->settingsScreen->optionDown();
		}

		if (graphics::getKeyState(graphics::SCANCODE_A) && !game->aPressed) {
			game->settingsScreen->decrease();
		}

		if (graphics::getKeyState(graphics::SCANCODE_D) && !game->dPressed) {
			game->settingsScreen->increase();
		}
	}
	else if (game->currentScreen == game->pauseScreen) {
		if (graphics::getKeyState(graphics::SCANCODE_B)) {
			game->currentScreen = game->playScreen;
			game->previousScreen = nullptr;
		}

		if (graphics::getKeyState(graphics::SCANCODE_O)) {
			game->currentScreen = game->settingsScreen;
			game->previousScreen = game->pauseScreen;
		}

		if (graphics::getKeyState(graphics::SCANCODE_Q)) {

			game->currentScreen = game->main;
			game->previousScreen = nullptr;
			Audio::playMainMenuMusic();
		}
	}

	if (graphics::getKeyState(graphics::SCANCODE_SPACE)) {
		game->spacePressed = true;
	}
	else {
		game->spacePressed = false;
	}

	if (graphics::getKeyState(graphics::SCANCODE_W)) {
		game->wPressed = true;
	}
	else {
		game->wPressed = false;
	}


	if (graphics::getKeyState(graphics::SCANCODE_S)) {
		game->sPressed = true;
	}
	else {
		game->sPressed = false;
	}

	if (graphics::getKeyState(graphics::SCANCODE_A)) {
		game->aPressed = true;
	}
	else {
		game->aPressed = false;
	}

	if (graphics::getKeyState(graphics::SCANCODE_D)) {
		game->dPressed = true;
	}
	else {
		game->dPressed = false;
	}

	if (graphics::getKeyState(graphics::SCANCODE_TAB)) {
		game->tabPressed = true;
	}
	else {
		game->tabPressed = false;
	}

}

void draw()
{
	drawText();

	Game* game = (Game*)graphics::getUserData();

	game->currentScreen->draw();

	if (game->currentScreen == game->playScreen) {
		game->ripley->draw();
	}
}

int main()
{
	Game game;

	graphics::createWindow(game.settings->window_width, game.settings->window_height, "C++ demo");


	game.init();

	graphics::setUserData(&game);
	graphics::setDrawFunction(draw);
	graphics::setUpdateFunction(update);

	graphics::setCanvasSize(game.canvas_width, game.canvas_height);
	graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);

	graphics::startMessageLoop();
	graphics::destroyWindow();

	return 0;
}
