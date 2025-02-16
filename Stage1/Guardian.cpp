#include "Guardian.h"
#include "Audio.h"

#define FRAME_WALKING_INDEX_MIN 0
#define FRAME_WALKING_INDEX_MAX 6

//#define FRAME_DYING_INDEX_MIN 7
//#define FRAME_DYING_INDEX_MAX 9

#define TOTAL_WALKING_FRAMES (FRAME_WALKING_INDEX_MAX - FRAME_WALKING_INDEX_MIN + 1)

//#define TOTAL_DYING_FRAMES (FRAME_DYING_INDEX_MAX - FRAME_DYING_INDEX_MIN + 1)

#define FRAME_SPEED (100.0f)

float Guardian::transformX(float alien_x, Ripley* ripley) {
	return alien_x - ripley->x + 50;
}

float Guardian::transformY(float alien_y, Ripley* ripley) {
	return alien_y - ripley->y + 80;
}

Guardian::Guardian(float x , float y, float range_x, float range_y) : Alien(14, 14, x, y, range_x, range_y, 10)
{
	left_textures[0] = "assets\\Guardian\\left_1.png";
	left_textures[1] = "assets\\Guardian\\left_2.png";
	left_textures[2] = "assets\\Guardian\\left_3.png";
	left_textures[3] = "assets\\Guardian\\left_4.png";
	left_textures[4] = "assets\\Guardian\\left_5.png";
	left_textures[5] = "assets\\Guardian\\left_6.png";
	left_textures[6] = "assets\\Guardian\\left_7.png";
	left_textures[7] = "assets\\Guardian\\left_8.png";
	left_textures[8] = "assets\\Guardian\\left_9.png";
	left_textures[9] = "assets\\Guardian\\left_10.png";

	right_textures[0] = "assets\\Guardian\\right_1.png";
	right_textures[1] = "assets\\Guardian\\right_2.png";
	right_textures[2] = "assets\\Guardian\\right_3.png";
	right_textures[3] = "assets\\Guardian\\right_4.png";
	right_textures[4] = "assets\\Guardian\\right_5.png";
	right_textures[5] = "assets\\Guardian\\right_6.png";
	right_textures[6] = "assets\\Guardian\\right_7.png";
	right_textures[7] = "assets\\Guardian\\right_8.png";
	right_textures[8] = "assets\\Guardian\\right_9.png";
	right_textures[9] = "assets\\Guardian\\right_10.png";

	br.fill_color[0] = 1.0f;
	br.fill_color[1] = 1.0f;
	br.fill_color[2] = 1.0f;
	br.fill_secondary_color[0] = 1.0f;
	br.fill_secondary_color[1] = 1.0f;
	br.fill_secondary_color[2] = 1.0f;
	br.outline_opacity = 0.0f;
	br.texture = "";

	if (rand() % 2 == 0) {
		facing_left = true;
		facing_right = false;
	}
	else {
		facing_left = false;
		facing_right = true;
	}

	float speed_variance = 0.004f * (rand() % 3);
	ux += speed_variance;
}

void Guardian::draw(Ripley* ripley)
{
	int frame = ((int)(frame_timer / FRAME_SPEED)) % (TOTAL_WALKING_FRAMES)+FRAME_WALKING_INDEX_MIN;
	
	if (facing_right) {
		br.texture = right_textures[frame];
	}
	else {
		br.texture = left_textures[frame];
	}

	//int dframe = ((int)(frame_timer / FRAME_SPEED)) % (TOTAL_DYING_FRAMES)+FRAME_DYING_INDEX_MIN;

	graphics::drawRect(transformX(x, ripley), transformY(y, ripley), width, height, br);

}

void Guardian::reset()
{
	frame = 0;
	x = 53;
	y = 27;
}

void Guardian::update(float ms)
{
	float distance = ux * ms;

	if (facing_left) {
		left(distance);
	}
	else {
		right(distance);
	}

	frame_timer = frame_timer + ms;
}

void Guardian::left(float distance) {
	x -= distance;
	if (x < min_x) {
		x = min_x;
		facing_left = false;
		facing_right = true;
	}
	else {
		facing_left = true;
		facing_right = false;
	}
}

void Guardian::right(float distance) {
	x += distance;

	if (x > max_x) {
		x = max_x;
		facing_left = true;
		facing_right = false;
	}
	else {
		facing_left = false;
		facing_right = true;
	}
}

void Guardian::up(float distance) {
	y -= distance;
}

void Guardian::down(float distance) {
	y += distance;
}


void Guardian::applyCollisionEvent(Ripley* ripley)
{
	ripley->health = ripley->health - 0.6f;
	//ripley->health = ripley->health - 0;
	Audio::playAlienAttackSound();
}

int Guardian::getScore()
{
	return 500;
}
