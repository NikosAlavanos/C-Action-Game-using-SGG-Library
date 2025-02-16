#include "Upright.h"
#include "Audio.h"

#define FRAME_WALKING_INDEX_MIN 0
#define FRAME_WALKING_INDEX_MAX 3

//#define FRAME_DYING_INDEX_MIN 9
//#define FRAME_DYING_INDEX_MAX 13

//#define FRAME_SPAWN_INDEX_MIN 5
//#define FRAME_SPAWN_INDEX_MAX 8

#define TOTAL_WALKING_FRAMES (FRAME_WALKING_INDEX_MAX - FRAME_WALKING_INDEX_MIN + 1)

//#define TOTAL_DYING_FRAMES (FRAME_DYING_INDEX_MAX - FRAME_DYING_INDEX_MIN + 1)
//#define TOTAL_SPAWN_FRAMES (FRAME_SPAWN_INDEX_MAX - FRAME_SPAWN_INDEX_MIN + 1)

#define FRAME_SPEED (100.0f)

float Upright::transformX(float alien_x, Ripley* ripley) {
	return alien_x - ripley->x + 50;
}

float Upright::transformY(float alien_y, Ripley* ripley) {
	return alien_y - ripley->y + 80;
}

Upright::Upright(float x, float y, float range_x, float range_y) : Alien(12,12,x,y, range_x, range_y)
{
	left_textures[0] = "assets\\Upright\\left_1.png";
	left_textures[1] = "assets\\Upright\\left_2.png";
	left_textures[2] = "assets\\Upright\\left_3.png";
	left_textures[3] = "assets\\Upright\\left_4.png";
	left_textures[4] = "assets\\Upright\\left_5.png";
	left_textures[5] = "assets\\Upright\\left_6.png";
	left_textures[6] = "assets\\Upright\\left_7.png";
	left_textures[7] = "assets\\Upright\\left_8.png";
	left_textures[8] = "assets\\Upright\\left_9.png";
	left_textures[9] = "assets\\Upright\\left_10.png";
	left_textures[10] = "assets\\Upright\\left_11.png";
	left_textures[11] = "assets\\Upright\\left_12.png";
	left_textures[12] = "assets\\Upright\\left_13.png";
	left_textures[13] = "assets\\Upright\\left_14.png";


	right_textures[0] = "assets\\Upright\\right_1.png";
	right_textures[1] = "assets\\Upright\\right_2.png";
	right_textures[2] = "assets\\Upright\\right_3.png";
	right_textures[3] = "assets\\Upright\\right_4.png";
	right_textures[4] = "assets\\Upright\\right_5.png";
	right_textures[5] = "assets\\Upright\\right_6.png";
	right_textures[6] = "assets\\Upright\\right_7.png";
	right_textures[7] = "assets\\Upright\\right_8.png";
	right_textures[8] = "assets\\Upright\\right_9.png";
	right_textures[9] = "assets\\Upright\\right_10.png";
	right_textures[10] = "assets\\Upright\\right_11.png";
	right_textures[11] = "assets\\Upright\\right_12.png";
	right_textures[12] = "assets\\Upright\\right_13.png";
	right_textures[13] = "assets\\Upright\\right_14.png";

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

void Upright::draw(Ripley* ripley)
{
	int frame = ((int)(frame_timer / FRAME_SPEED)) % (TOTAL_WALKING_FRAMES)+FRAME_WALKING_INDEX_MIN;

	if (facing_right) {
		br.texture = right_textures[frame];
	}
	else {
		br.texture = left_textures[frame];
	}

	//int dframe = ((int)(frame_timer / FRAME_SPEED)) % (TOTAL_DYING_FRAMES)+FRAME_DYING_INDEX_MIN;
	//int sframe = ((int)(frame_timer / FRAME_SPEED)) % (TOTAL_SPAWN_FRAMES)+FRAME_SPAWN_INDEX_MIN;
		
	graphics::drawRect(transformX(x, ripley), transformY(y, ripley), width, height, br);

}

void Upright::reset()
{
	frame_timer = 0;
	x = 53;
	y = 27;
}

void Upright::update(float ms)
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

void Upright::left(float distance) {
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

void Upright::right(float distance) {
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

void Upright::up(float distance) {
	y -= distance;
}

void Upright::down(float distance) {
	y += distance;
}


void Upright::applyCollisionEvent(Ripley* ripley)
{
	ripley->health = ripley->health - 0.4f;
	//ripley->health = ripley->health - 0;
	Audio::playAlienAttackSound();
}

int Upright::getScore()
{
	return 200;
}
