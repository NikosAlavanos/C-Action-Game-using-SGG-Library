#include <iostream>

#include "MainScreen.h"

using namespace std;

MainScreen::MainScreen()
{
	cout << "Setting up main screen ... " << endl;

	image = new ImageComponent(50, 50, 100.0f, 100.0f, "assets\\main\\main.png");
	settings = new TextComponent(35.0f, 50.0f, 5.0f, "F1: settings");
	title = new TextComponent(25.0f, 60.0f, 5.0f, "Press space to start");	
	exit_app = new TextComponent(30.0f, 70.0f, 5.0f, "Press Esc to exit");
	

}

MainScreen::~MainScreen()
{
	cout << "Cleaning up main screen " << endl;

	delete title;
	delete image;
	delete settings;
	delete exit_app;
}

void MainScreen::draw()
{
	title->draw();
	image->draw();
	settings->draw();
	exit_app->draw();
}

void MainScreen::update(float ms)
{
}
