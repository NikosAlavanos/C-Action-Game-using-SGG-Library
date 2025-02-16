#pragma once

#include <iostream>
#include <random>
#include <string>

#include <sgg/graphics.h>

using namespace std;

enum ShootAttemptResult {
	NO_AMMO,
	CLIMBING,
	COOLDOWN,
	SUCCESS
};

class Ripley
{
private:
	void printState();
	string left_textures[9];
	string right_textures[9];
	string climbing_textures[9];
	string crawling_textures_left[10];
	string crawling_textures_right[10];
	string shooting_textures_left[10];
	string shooting_textures_right[10];
	graphics::Brush br;

	float clipDistance(float value);

	float ux = 0.1f, uy = 0.1f;
	float jump_uy = 0.02f;

	bool moving = false;      // true if player is using any arrow button
	bool shooting = false;
	bool falling = false;
	bool climbing = false;

	bool jumping = false;
	bool jumped = false;

	float t_jump_start = 0.0f;
	float next_floor_y = 28.5f;

	float frame_timer = 0;    // cumulative time from the beggining of the level

	float transformX(float world_x);
	float transformY(float world_y);

	float last_shoot = 0;

public:
	bool facing_left = false; // true if Ripley is looking left
	bool facing_right = true; // true if Ripley is looking righ
	bool crawling = false;
	bool l_lives = false;
	bool WB_door = true;
	float width = 8;
	float height = 10;
	float x;
	float y;
	float health = 100;
	int lives = 3;
	int score = 0;
	int prisoners = 8;
	int gun_bullets = 100;
	float remaining_time_ms = 0;

	Ripley();

	void draw();

	void reset(bool reset_lives = true);

	void update(float ms);

	void left(float distance);

	void right(float distance);

	void up(float distance);

	void down(float distance);

	void shoot();

	void healthIncrease();

	void healthDecrease();

	void gunBulletsIncrease();

	void gunBulletsDecrease();

	void prisonersDecrease();

	ShootAttemptResult canShoot() const;

};

