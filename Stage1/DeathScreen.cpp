#include <iostream>
#include "DeathScreen.h"

using namespace std;

DeathScreen ::DeathScreen() 
{
	cout << "Setting up Death screen ... " << endl;
	items.push_back(new ImageComponent(50, 50, 100.0f, 100.0f, "assets\\\Death\\Death.png"));
	items.push_back(new TextComponent(17.0f, 20.0f, 10.0f, "YOU JUST DIED"));
	items.push_back(new TextComponent(10.0f, 80.0f, 6.0f, "IF YOU DARE TO PLAY AGAIN"));
	items.push_back(new TextComponent(35.0f, 85.0f, 5.0f, "PRESS SPACE !"));
	items.push_back(new TextComponent(15.0f, 95.0f, 6.0f, "PRESS TAB TO GO TO THE"));
	items.push_back(new TextComponent(35.0f, 100.0f, 6.0f, "MAIN MENU"));
}

DeathScreen :: ~DeathScreen()
{
	cout << "Cleaning up Death screen ... " << endl;

	for (auto item : items) {
		delete item;
	}
}

void DeathScreen::draw()
{
	for (auto item : items) {
		item->draw();
	}
}

void DeathScreen::update(float ms)
{
}