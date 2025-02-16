#include <iostream>

#include "PauseScreen.h"

using namespace std;

PauseScreen::PauseScreen()
{
	cout << "Setting up main screen ... " << endl;

	title = new TextComponent(20.0f, 30.0f, 10.0f, "PAUSE MENU");
	play = new TextComponent(25.0f, 45.0f, 5.0f, "PRESS B TO CONTINUE");
	options = new TextComponent(26.0f, 55.0f, 5.0f, "PRESS O TO OPTIONS");
	main_menu = new TextComponent(24.0f, 65.0f, 5.0f, "PRESS Q TO MAIN MENU");
	exit_app = new TextComponent(27.0f, 75.0f, 5.0f, "PRESS ESC TO EXIT");

}

PauseScreen::~PauseScreen()
{
	cout << "Cleaning up main screen " << endl;

	delete title;
	delete play;
	delete main_menu;
	delete exit_app;
	delete options;

}

void PauseScreen::draw()
{
	title->draw();
	play->draw();
	options->draw();
	main_menu->draw();
	exit_app->draw();

}

void PauseScreen ::update(float ms)
{
}
