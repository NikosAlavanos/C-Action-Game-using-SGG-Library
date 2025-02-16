#include "Crawler.h"
#include "Audio.h"

#define FRAME_WALKING_INDEX_MIN 0
#define FRAME_WALKING_INDEX_MAX 3


#define TOTAL_WALKING_FRAMES (FRAME_WALKING_INDEX_MAX - FRAME_WALKING_INDEX_MIN + 1)

#define FRAME_SPEED (100.0f)

float Crawler::transformX(float alien_x, Ripley* ripley) {
	return alien_x - ripley->x + 50;
}

float Crawler::transformY(float alien_y, Ripley* ripley) {
	return alien_y - ripley->y + 80;
}

Crawler::Crawler(float x, float y, bool upside_down, float range_x, float range_y) : Alien(14, 7, x, y, range_x, range_y, 5), upside_down(upside_down)
{
	left_textures[0] = "assets\\Crawler\\left_1.png";
	left_textures[1] = "assets\\Crawler\\left_2.png";
	left_textures[2] = "assets\\Crawler\\left_3.png";
	left_textures[3] = "assets\\Crawler\\left_4.png";
	left_textures[4] = "assets\\Crawler\\left_5.png";
	left_textures[5] = "assets\\Crawler\\left_6.png";

	right_textures[0] = "assets\\Crawler\\right_1.png";
	right_textures[1] = "assets\\Crawler\\right_2.png";
	right_textures[2] = "assets\\Crawler\\right_3.png";
	right_textures[3] = "assets\\Crawler\\right_4.png";
	right_textures[4] = "assets\\Crawler\\right_5.png";
	right_textures[5] = "assets\\Crawler\\right_6.png";

	up_textures[0] = "assets\\Crawler\\up_1.png";
	up_textures[1] = "assets\\Crawler\\up_2.png";
	up_textures[2] = "assets\\Crawler\\up_3.png";
	up_textures[3] = "assets\\Crawler\\up_4.png";
	up_textures[4] = "assets\\Crawler\\up_5.png";
	up_textures[5] = "assets\\Crawler\\up_6.png";

	down_textures[0] = "assets\\Crawler\\down_1.png";
	down_textures[1] = "assets\\Crawler\\down_2.png";
	down_textures[2] = "assets\\Crawler\\down_3.png";
	down_textures[3] = "assets\\Crawler\\down_4.png";
	down_textures[4] = "assets\\Crawler\\down_5.png";
	down_textures[5] = "assets\\Crawler\\down_6.png";

	br.fill_color[0] = 1.0f;
	br.fill_color[1] = 1.0f;
	br.fill_color[2] = 1.0f;
	br.fill_secondary_color[0] = 1.0f;
	br.fill_secondary_color[1] = 1.0f;
	br.fill_secondary_color[2] = 1.0f;
	br.outline_opacity = 0.0f;
	br.texture = "";

	float speed_variance = 0.004f * (rand() % 3);
	ux += speed_variance;
	uy += speed_variance;
}

void Crawler::draw(Ripley* ripley)
{
	int frame = ((int)(frame_timer / FRAME_SPEED)) % (TOTAL_WALKING_FRAMES)+FRAME_WALKING_INDEX_MIN;
	if (!upside_down) {
		if (facing_right) {
			br.texture = right_textures[frame];
		}
		else if (facing_left) {
			br.texture = left_textures[frame];
		}
	}
	else {
		if (facing_right) {
			br.texture = left_textures[frame];
		}
		else if (facing_left) {
			br.texture = right_textures[frame];
		}

	}


	if (upside_down) {
		graphics::setOrientation(180);
	}

	graphics::drawRect(transformX(x, ripley), transformY(y, ripley), width, height, br);

	if (upside_down) {
		graphics::resetPose();
	}


}

void Crawler::reset()
{
	frame = 0;
	x = 53;
	y = 27;
}

void Crawler::update(float ms)
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

void Crawler::left(float distance) {
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

void Crawler::right(float distance) {
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

void Crawler::up(float distance) {
	y -= distance;
	if (y < min_y) {
		y = min_y;
		facing_down = false;
		facing_up = true;
	}
	else {
		facing_down = true;
		facing_up = false;
	}
}

void Crawler::down(float distance) {
	y += distance;
	if (y < min_y) {
		y = min_y;
		facing_down = true;
		facing_up = false;
	}
	else {
		facing_down = false;
		facing_up = true;
	}
}

void Crawler::applyCollisionEvent(Ripley* ripley)
{
	ripley->health = ripley->health - 0.5f;
	//ripley->health = ripley->health - 0;
	Audio::playAlienAttackSound();
}

int Crawler::getScore()
{
	return 400;
}
