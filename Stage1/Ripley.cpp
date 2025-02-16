#include "Ripley.h"
#include "WorldBoundaries.h"
#include "Audio.h"
#include "Constants.h"

#define FRAME_SHOOTING_INDEX 0
#define FRAME_STANDING_INDEX 1

#define FRAME_WALKING_INDEX_MIN 4
#define FRAME_WALKING_INDEX_MAX 8

#define FRAME_CLIMBING_INDEX_MIN 0
#define FRAME_CLIMBING_INDEX_MAX 8

#define FRAME_CLIMBING_INDEX_MIN 0
#define FRAME_CLIMBING_INDEX_MAX 8

#define FRAME_CRAWLING_INDEX_MIN 0
#define FRAME_CRAWLING_INDEX_MAX 9

#define FRAME_SHOOTING_INDEX_MIN 0
#define FRAME_SHOOTING_INDEX_MAX 9

#define TOTAL_WALKING_FRAMES (FRAME_WALKING_INDEX_MAX - FRAME_WALKING_INDEX_MIN + 1)
#define TOTAL_CLIMBING_FRAMES (FRAME_CLIMBING_INDEX_MAX - FRAME_CLIMBING_INDEX_MIN + 1)
#define TOTAL_CRAWLING_FRAMES (FRAME_CRAWLING_INDEX_MAX - FRAME_CRAWLING_INDEX_MIN + 1)
#define TOTAL_SHOOTING_FRAMES (FRAME_SHOOTING_INDEX_MAX - FRAME_SHOOTING_INDEX_MIN + 1)
#define FRAME_SPEED (100.0f)

void Ripley::printState()
{
	//cout << x << " " << y << " clmbing:" << climbing << ", falling: " << falling << ", jumping: " << jumping <<", crawling: " << crawling << endl;
}


float Ripley::transformX(float world_x) {
	return world_x - Ripley::x + 50;
}

float Ripley::transformY(float world_y) {
	return world_y - Ripley::y + 80;
}

Ripley::Ripley() : x(0), y(0)
{
	left_textures[0] = "assets\\ripley\\left_1.png";
	left_textures[1] = "assets\\ripley\\left_2.png";
	left_textures[2] = "assets\\ripley\\left_3.png";
	left_textures[3] = "assets\\ripley\\left_4.png";
	left_textures[4] = "assets\\ripley\\left_5.png";
	left_textures[5] = "assets\\ripley\\left_6.png";
	left_textures[6] = "assets\\ripley\\left_7.png";
	left_textures[7] = "assets\\ripley\\left_8.png";
	left_textures[8] = "assets\\ripley\\left_9.png";


	right_textures[0] = "assets\\ripley\\right_1.png";
	right_textures[1] = "assets\\ripley\\right_2.png";
	right_textures[2] = "assets\\ripley\\right_3.png";
	right_textures[3] = "assets\\ripley\\right_4.png";
	right_textures[4] = "assets\\ripley\\right_5.png";
	right_textures[5] = "assets\\ripley\\right_6.png";
	right_textures[6] = "assets\\ripley\\right_7.png";
	right_textures[7] = "assets\\ripley\\right_8.png";
	right_textures[8] = "assets\\ripley\\right_9.png";


	climbing_textures[0] = "assets\\ripley\\climbing\\climbing_01.png";
	climbing_textures[1] = "assets\\ripley\\climbing\\climbing_02.png";
	climbing_textures[2] = "assets\\ripley\\climbing\\climbing_03.png";
	climbing_textures[3] = "assets\\ripley\\climbing\\climbing_04.png";
	climbing_textures[4] = "assets\\ripley\\climbing\\climbing_05.png";
	climbing_textures[5] = "assets\\ripley\\climbing\\climbing_06.png";
	climbing_textures[6] = "assets\\ripley\\climbing\\climbing_07.png";
	climbing_textures[7] = "assets\\ripley\\climbing\\climbing_08.png";
	climbing_textures[8] = "assets\\ripley\\climbing\\climbing_09.png";

	//crawling
	crawling_textures_left[0] = "assets\\ripley\\crawling\\left_1.png";
	crawling_textures_left[1] = "assets\\ripley\\crawling\\left_2.png";
	crawling_textures_left[2] = "assets\\ripley\\crawling\\left_3.png";
	crawling_textures_left[3] = "assets\\ripley\\crawling\\left_4.png";
	crawling_textures_left[4] = "assets\\ripley\\crawling\\left_5.png";
	crawling_textures_left[5] = "assets\\ripley\\crawling\\left_6.png";
	crawling_textures_left[6] = "assets\\ripley\\crawling\\left_7.png";
	crawling_textures_left[7] = "assets\\ripley\\crawling\\left_8.png";
	crawling_textures_left[8] = "assets\\ripley\\crawling\\left_9.png";
	crawling_textures_left[9] = "assets\\ripley\\crawling\\left_10.png";

	crawling_textures_right[0] = "assets\\ripley\\crawling\\right_1.png";
	crawling_textures_right[1] = "assets\\ripley\\crawling\\right_2.png";
	crawling_textures_right[2] = "assets\\ripley\\crawling\\right_3.png";
	crawling_textures_right[3] = "assets\\ripley\\crawling\\right_4.png";
	crawling_textures_right[4] = "assets\\ripley\\crawling\\right_5.png";
	crawling_textures_right[5] = "assets\\ripley\\crawling\\right_6.png";
	crawling_textures_right[6] = "assets\\ripley\\crawling\\right_7.png";
	crawling_textures_right[7] = "assets\\ripley\\crawling\\right_8.png";
	crawling_textures_right[8] = "assets\\ripley\\crawling\\right_9.png";
	crawling_textures_right[9] = "assets\\ripley\\crawling\\right_10.png";

	//shooting
	shooting_textures_left[0] = "assets\\ripley\\shooting\\left_1.png";
	shooting_textures_left[1] = "assets\\ripley\\shooting\\left_2.png";
	shooting_textures_left[2] = "assets\\ripley\\shooting\\left_3.png";
	shooting_textures_left[3] = "assets\\ripley\\shooting\\left_4.png";
	shooting_textures_left[4] = "assets\\ripley\\shooting\\left_5.png";
	shooting_textures_left[5] = "assets\\ripley\\shooting\\left_6.png";
	shooting_textures_left[6] = "assets\\ripley\\shooting\\left_7.png";
	shooting_textures_left[7] = "assets\\ripley\\shooting\\left_8.png";
	shooting_textures_left[8] = "assets\\ripley\\shooting\\left_9.png";
	shooting_textures_left[9] = "assets\\ripley\\shooting\\left_10.png";

	shooting_textures_right[0] = "assets\\ripley\\shooting\\right_1.png";
	shooting_textures_right[1] = "assets\\ripley\\shooting\\right_2.png";
	shooting_textures_right[2] = "assets\\ripley\\shooting\\right_3.png";
	shooting_textures_right[3] = "assets\\ripley\\shooting\\right_4.png";
	shooting_textures_right[4] = "assets\\ripley\\shooting\\right_5.png";
	shooting_textures_right[5] = "assets\\ripley\\shooting\\right_6.png";
	shooting_textures_right[6] = "assets\\ripley\\shooting\\right_7.png";
	shooting_textures_right[7] = "assets\\ripley\\shooting\\right_8.png";
	shooting_textures_right[8] = "assets\\ripley\\shooting\\right_9.png";
	shooting_textures_right[9] = "assets\\ripley\\shooting\\right_10.png";

	br.fill_color[0] = 1.0f;
	br.fill_color[1] = 1.0f;
	br.fill_color[2] = 1.0f;
	br.fill_secondary_color[0] = 1.0f;
	br.fill_secondary_color[1] = 1.0f;
	br.fill_secondary_color[2] = 1.0f;
	br.outline_opacity = 0.0f;
	br.texture = "";
}

void Ripley::draw()
{
	if (climbing) {
		int frame = ((int)(frame_timer / FRAME_SPEED)) % (TOTAL_CLIMBING_FRAMES)+FRAME_CLIMBING_INDEX_MIN;

		br.texture = climbing_textures[frame];
	}
	else if (crawling) {
		int frame = ((int)(frame_timer / FRAME_SPEED)) % (TOTAL_CRAWLING_FRAMES)+FRAME_CRAWLING_INDEX_MIN;

		if (facing_right) {
			br.texture = crawling_textures_right[frame];
		}
		else {
			br.texture = crawling_textures_left[frame];
		}
	}
	else if (!moving && !shooting) {
		int frame = FRAME_STANDING_INDEX;
		if (facing_right) {
			br.texture = right_textures[frame];
		}
		else {
			br.texture = left_textures[frame];
		}
	}
	else if (!shooting) {
		int frame = ((int)(frame_timer / FRAME_SPEED)) % (TOTAL_WALKING_FRAMES)+FRAME_WALKING_INDEX_MIN;

		if (facing_right) {
			br.texture = right_textures[frame];
		}
		else {
			br.texture = left_textures[frame];
		}
	}
	else if (!moving && shooting && !crawling) {
		int frame = FRAME_SHOOTING_INDEX;
		if (facing_right) {
			br.texture = right_textures[frame];
		}
		else {
			br.texture = left_textures[frame];
		}
	}
	else if (moving && shooting && !crawling) {
		int frame = ((int)(frame_timer / FRAME_SPEED)) % (TOTAL_SHOOTING_FRAMES)+FRAME_SHOOTING_INDEX_MIN;
		if (facing_right) {
			br.texture = shooting_textures_right[frame];
		}
		else {
			br.texture = shooting_textures_left[frame];
		}
	}



	graphics::drawRect(transformX(x), transformY(y), width, height, br);

}

void Ripley::reset(bool reset_lives)
{
	x = Constants::RIPLEY_INITIAL_X;
	y = Constants::RIPLEY_INITIAL_Y;
	health = 100;
	gun_bullets = 100;

	frame_timer = 0;
	moving = true;
	shooting = false;
	falling = false;
	climbing = false;
	l_lives = false;
	crawling = false;
	WB_door = true;
	jumping = false;
	last_shoot = 0;


	if (reset_lives) {
		lives = 3;
		score = 0;
		prisoners = 8;
	}
}

void Ripley::update(float ms)
{
	float distance = 0.0f;

	moving = false;

	if (shooting) {
		float  t = graphics::getGlobalTime();

		if (t - last_shoot >= Constants::SHOOT_FRAME_COOLDOWN) {
			shooting = false;
		}
	}
	if (!jumping && !climbing && !falling && !crawling && graphics::getKeyState(graphics::SCANCODE_W)) {
		if (!jumped) {
			jumping = true;
			t_jump_start = graphics::getGlobalTime();
		}
	}
	else if (!falling && !crawling && !jumping && graphics::getKeyState(graphics::SCANCODE_W)) {
		distance = uy * ms;
		up(distance);

		if (Constants::PRINT_STATE) {
			printState();
		}

		frame_timer = frame_timer + ms;
		moving = true;
	}



	if (jumping) {
		if (graphics::getGlobalTime() - t_jump_start >= Constants::JUMP_DURATION) {
			jumping = false;
		}
		else {
			distance = jump_uy * Constants::JUMP_GRAVITY_FACTOR * ms;
			up(distance);

			if (Constants::PRINT_STATE) {
				printState();
			}


		}
	}

	if (!falling && graphics::getKeyState(graphics::SCANCODE_S)) {
		distance = uy * ms;
		down(distance);

		if (Constants::PRINT_STATE) {
			printState();
		}

		frame_timer = frame_timer + ms;
		moving = true;
	}

	if (graphics::getKeyState(graphics::SCANCODE_A)) {
		distance = ux * ms;
		left(distance);

		facing_right = false;
		facing_left = true;

		if (Constants::PRINT_STATE) {
			printState();
		}

		frame_timer = frame_timer + ms;
		moving = true;
	}

	if (graphics::getKeyState(graphics::SCANCODE_D)) {
		distance = ux * ms;
		right(distance);

		facing_right = true;
		facing_left = false;

		if (Constants::PRINT_STATE) {
			printState();
		}

		frame_timer = frame_timer + ms;
		moving = true;
	}




	if (Constants::APPLY_WORLD_BOUNDARIES) {
		clipCoordinates(x, y, climbing, falling, next_floor_y, l_lives, crawling, WB_door, jumped);
	}




	if (!jumping && Constants::GRAVITY && falling) {
		y = y + jump_uy * Constants::GRAVITY_FACTOR * ms;
		if (y > next_floor_y) {
			y = next_floor_y;
		}
	}
	if (prisoners == 0 && WB_door) {
		Audio::playDoorSound();

		WB_door = false;
		cout << "bool of door: " << WB_door << endl;
	}

}

float Ripley::clipDistance(float value) {
	return value;
}

void Ripley::left(float distance) {
	x -= clipDistance(distance * Constants::RIPLEY_SPEED_FACTOR);
}

void Ripley::right(float distance) {
	x += clipDistance(distance * Constants::RIPLEY_SPEED_FACTOR);
}

void Ripley::up(float distance) {
	y -= clipDistance(distance * Constants::RIPLEY_SPEED_FACTOR);
}

void Ripley::down(float distance) {
	y += clipDistance(distance * Constants::RIPLEY_SPEED_FACTOR);
}


void Ripley::healthIncrease() {
	if (health < 90) {
		health = health + 10;
	}
	else {
		health = 100;
	}
	Audio::playStimSound();
}

void Ripley::healthDecrease() {
	if (health > 10) {
		health = health - 10;
	}
	else {
		health = 0;
	}
}

void Ripley::gunBulletsIncrease() {
	if (gun_bullets < 50) {
		gun_bullets = gun_bullets + 50;
	}
	else if (gun_bullets >= 50 && gun_bullets <= 100) {
		gun_bullets = 100;
	}
	Audio::playPickUpAmmoSound();
}

void Ripley::gunBulletsDecrease() {
	if (gun_bullets > 0) {
		gun_bullets--;
	}
}


void Ripley::prisonersDecrease() {
	if (prisoners >= 1) {
		prisoners--;
	}
	else {
		prisoners = 0;
	}
}

ShootAttemptResult Ripley::canShoot() const
{
	if (climbing) {
		return ShootAttemptResult::CLIMBING;
	}

	float  t = graphics::getGlobalTime();

	if (Constants::SHOOT_COOLDOWN != 0 && t - last_shoot < Constants::SHOOT_COOLDOWN) {
		return ShootAttemptResult::COOLDOWN;
	}

	if (gun_bullets == 0) {
		return ShootAttemptResult::NO_AMMO;
	}

	return ShootAttemptResult::SUCCESS;
}


void Ripley::shoot()
{

	float  t = graphics::getGlobalTime();
	last_shoot = t;
	if (!crawling) {
		shooting = true;
		Audio::playShootingSound();
		gunBulletsDecrease();
	}
}