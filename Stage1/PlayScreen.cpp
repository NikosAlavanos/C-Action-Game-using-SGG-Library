#include <iostream>
#include <iterator>
#include "WorldBoundaries.h"
#include "PlayScreen.h"
#include "Constants.h"
#include "Door.h"
#include "Audio.h"
using namespace std;

PlayScreen::PlayScreen(Settings* settings, Ripley* ripley) : settings(settings), ripley(ripley)
{
	//cout << "Setting up play screen ... " << endl;

	world = new World();
	door = new Door();
	Live = new TextComponent(5.0f, 10.0f, 5.0f, "LIVES");
	Energy = new TextComponent(80.0f, 90.0f, 5.0f, "HEALTH");
	Prisoners = new TextComponent(39.0f, 10.0f, 5.0f, "PRISONERS");
	Time = new TextComponent(85.0f, 10.0f, 5.0f, "TIME");



	gun_bullets_value = new TextComponent(18.0f, 93.0f, 6.0f, "");
	live_value = new TextComponent(5.0f, 15.0f, 5.0f, "");
	energy_value = new TextComponent(80.0f, 95.0f, 5.0f, "");
	prisoners_value = new TextComponent(50.0f, 15.0f, 5.0f, "");
	time_value = new TextComponent(85.0f, 15.0f, 5.0f, "");


	Gun_logo* Gl = new Gun_logo();
	Gl->x = 10;
	Gl->y = 90;

	gun_logo.push_back(Gl);

	//Crawler
	aliens.push_back(new Crawler(183, 62, true, 5, 0)); 
	aliens.push_back(new Crawler(390, 97, true, 5, 0));
	aliens.push_back(new Crawler(367, 176, true, 5, 0));
	aliens.push_back(new Crawler(121, 141, true, 5, 0));
	aliens.push_back(new Crawler(342, 199, false, 50, 0));

	//Guardian
	aliens.push_back(new Guardian(175, 26, 170, 0));
	aliens.push_back(new Guardian(274, 196, 20, 0));
	aliens.push_back(new Guardian(94, 191, 5, 0));
	aliens.push_back(new Guardian(67, 191, 5, 0));


	//Upright
	aliens.push_back(new Upright(109, 28, 40, 0));
	aliens.push_back(new Upright(205, 28, 100, 0));
	aliens.push_back(new Upright(282, 28, 90, 0));
	aliens.push_back(new Upright(328, 28, 70, 0));
	aliens.push_back(new Upright(149, 76, 10, 0));
	aliens.push_back(new Upright(240, 80, 15, 0));
	aliens.push_back(new Upright(357, 72.5f, 20, 0));
	aliens.push_back(new Upright(382, 197, 12, 0));

	

	pickups.push_back(new Ammunation_icon(68, 92));
	pickups.push_back(new Ammunation_icon(129, 32));
	pickups.push_back(new Ammunation_icon(168, 80));
	pickups.push_back(new Ammunation_icon(329, 76));

	pickups.push_back(new Health_icon(94, 92));
	pickups.push_back(new Health_icon(113, 32));
	pickups.push_back(new Health_icon(10, 92));
	pickups.push_back(new Health_icon(339, 76));

	

	pickups.push_back(new Prisoner(35, 80));
	pickups.push_back(new Prisoner(132, 75.5));
	pickups.push_back(new Prisoner(117, 124));
	pickups.push_back(new Prisoner(119, 189));
	pickups.push_back(new Prisoner(345, 101));
	pickups.push_back(new Prisoner(395, 132));
	pickups.push_back(new Prisoner(258, 196));
	pickups.push_back(new Prisoner(242, 196));
	
	time = settings->getMaxAllowedTime();

	game_starting_time = graphics::getGlobalTime();
}

PlayScreen::~PlayScreen()
{
	//cout << "Cleaning up play screen " << endl;

	delete world;
	delete Live;
	delete Energy;
	delete Prisoners;
	delete Time;
	delete door;

	delete gun_bullets_value;
	delete live_value;
	delete energy_value;
	delete prisoners_value;
	delete time_value;

	for (vector<Alien*>::iterator p = aliens.begin(); p != aliens.end(); ++p) {
		delete* p;
	}	

	for (vector<Pickup*>::iterator h = pickups.begin(); h != pickups.end(); ++h) {
		delete* h;
	}

	for (vector<Gun_logo*>::iterator g = gun_logo.begin(); g != gun_logo.end(); ++g) {
		delete* g;
	}

}

void PlayScreen::draw()
{
	float elapsed_time_ms = graphics::getGlobalTime() - game_starting_time;
	float remaining_time_ms = time - elapsed_time_ms;
	int remaining_time_sec = (int) (remaining_time_ms/1000);
	
	ripley->remaining_time_ms = remaining_time_ms;

	int minutes = remaining_time_sec / 60;
	int seconds = remaining_time_sec % 60;

	if (minutes < 1&& seconds >= 59) {
		Audio::playRipleyHurrySound();
	}
	if (minutes < 1 && seconds == 30) {
		Audio::playRipleyGotToGetOutOfHereSound();
	}


	string timestamp = std::to_string(minutes) + ":" + std::to_string(seconds);

	world->draw(ripley);	
	Live->draw();
	Energy->draw();
	Prisoners->draw();
	Time->draw();

	live_value->setContent(std::to_string(ripley->lives));
	live_value->draw();

	gun_bullets_value->setContent(std::to_string(ripley->gun_bullets));
	gun_bullets_value->draw();

	energy_value->setContent(std::to_string((int)ripley->health));
	energy_value->draw();

	prisoners_value->setContent(std::to_string(ripley->prisoners));
	prisoners_value->draw();

	time_value->setContent(timestamp);
	time_value->draw();

	for (vector<Alien*>::iterator p = aliens.begin(); p != aliens.end(); ++p) {
		(*p)->draw(ripley);
	}

	for (vector<Pickup*>::iterator h = pickups.begin(); h != pickups.end(); ++h) {
		(*h)->draw(ripley);
	}
	
	for (vector<Gun_logo*>::iterator g = gun_logo.begin(); g != gun_logo.end(); ++g) {
		(*g)->draw();
	}

	for (vector<Bullet*>::iterator p = bullets.begin(); p != bullets.end(); ++p) {
		(*p)->draw(ripley);
	}

	door->draw(ripley);
}



void PlayScreen::scoreIncrease() {
	if (graphics::getKeyState(graphics::SCANCODE_SPACE)) {
		ripley->score++;
	}
}



void PlayScreen::timeDecrease() {
	time--;
}

void PlayScreen::update(float ms)
{
	if (graphics::getKeyState(graphics::SCANCODE_V)) {
		this->victory = true;
		
	}

	if (Constants::APPLY_COLLISION_DETECTION_WITH_ALIENS) {
		for (vector<Alien*>::iterator p = aliens.begin(); p != aliens.end(); ++p) {

			Alien* alien = *p;

			alien->update(ms);

			alien->checkCollision(ripley);
		}
	}

	if (Constants::APPLY_COLLISION_DETECTION_WITH_PICKUPS) {
		for (vector<Pickup*>::iterator p = pickups.begin(); p != pickups.end(); ++p) {
			Pickup* pickup = *p;
			pickup->update(ms);
			if (pickup->checkCollision(ripley) == true) {
				pickups.erase(p);
				break;
			}
		}
	}

	if (Constants::APPLY_COLLISION_DETECTION_WITH_DOOR) {
		if (door->checkCollision(ripley)) {
			if (ripley->prisoners == 0) {
				this->victory = true;
			}
			else {
				cout << "hint: need to free more prisoners" << endl;
			}
		}

	}

	for (vector<Bullet*>::iterator p = bullets.begin(); p != bullets.end(); ++p) {
		if ((*p)->expired()) {
			bullets.erase(p);
			break;
		}
	}


	for (vector<Bullet*>::iterator p = bullets.begin(); p != bullets.end(); ++p) {
		Bullet* bullet = *p;
		bool clip = false;
		bool climbing = false;
		bool should_fall = false;
		float next_floor_y = false;
		bool l_lives = false;
		bool crawling = false;
		bool door = true;
		bool jumped = false;

		if (clipCoordinates(bullet->x, bullet->y, climbing, should_fall, next_floor_y, l_lives, crawling, door, jumped)){
			bullets.erase(p);
			break;
		}
	}
	for (vector<Bullet*>::iterator p = bullets.begin(); p != bullets.end(); ++p) {
		(*p)->update(ms);		
	}
	int alienDeathCounter = 0;
	for (vector<Bullet*>::iterator p = bullets.begin(); p != bullets.end(); ) {
		bool shouldDeleteBullet = false;

		for (vector<Alien*>::iterator q = aliens.begin(); q != aliens.end(); ++q) {
			Bullet* bullet = *p;
			Alien* alien = *q;
			

			if (alien->checkCollision(bullet)) {				
				alien->decreaseHealth();

				//cout << "Alien hit, remainig life: " << alien->health << endl;

				if (alien->health <= 0) {
					ripley->score += alien->getScore();
					Audio::playAlienDeathSound();
					alienDeathCounter++;
					cout << "Score increased to " << ripley->score << endl;
					aliens.erase(q);					
				}
				else {
					Audio::playAlienScreachSound();
				}

				shouldDeleteBullet = true;			
				break;
			}
		}
		
		if (alienDeathCounter == 5) {
			Audio::playRipleyBugsEverywhereSound();
		}
		if (alienDeathCounter == 13) {
			Audio::playRipleyAreaSecureSound();
		}

		if (shouldDeleteBullet) {
			bullets.erase(p);
			p = bullets.begin();
		}
		else {
			++p;
		}
	}




	if (ripley->health <= 0 || ripley->l_lives && Constants::FANS) {
		Audio::playRipleyDiesSound();
		ripley->lives--;
		ripley->reset(false);
		//cout << "lives: " << ripley->lives << endl;
	}

	if (!ripley->crawling) {
		if (graphics::getKeyState(graphics::SCANCODE_SPACE)) {
			ShootAttemptResult result = ripley->canShoot();

			switch (result) {
			case ShootAttemptResult::SUCCESS:
			{
				//cout << "shoot !!" << endl;
				ripley->shoot();

				float x, y;

				if (ripley->facing_left) {
					x = ripley->x - 5;
				}
				else {
					x = ripley->x + 5;
				}

				y = ripley->y - 2;

				Direction direction;

				if (ripley->facing_left) {
					direction = Direction::LEFT;
				}
				else {
					direction = Direction::RIGHT;
				}

				Bullet* bullet = new Bullet(x, y, direction);

				bullets.push_back(bullet);
				break;
			}
			case ShootAttemptResult::NO_AMMO:
				Audio::playNoAmmoSound();
				break;
			default:
				break;
			}
		}
	}
	door->update(ms);


	

}

bool PlayScreen::timeExpired() const
{

	float elapsed_time_ms = graphics::getGlobalTime() - game_starting_time;
	float remaining_time_ms = time - elapsed_time_ms;
	int remaining_time_sec = (int)(remaining_time_ms / 1000);

	return remaining_time_sec < 0;
}
