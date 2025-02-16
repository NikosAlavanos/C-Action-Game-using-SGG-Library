#include "Prisoner.h"
#include "Audio.h"

#define FRAME_FREE_INDEX_MIN 0
#define FRAME_FREE_INDEX_MAX 3

#define FRAME_TRAPPED_INDEX_MIN 0
#define FRAME_TRAPPED_INDEX_MAX 4

#define TOTAL_TRAPPED_FRAMES (FRAME_TRAPPED_INDEX_MAX - FRAME_TRAPPED_INDEX_MIN + 1)
#define TOTAL_FREE_FRAMES (FRAME_FREE_INDEX_MAX - FRAME_FREE_INDEX_MIN + 1)
#define FRAME_SPEED (275.0f)


float Prisoner::transformX(float alien_x, Ripley* ripley) {
	return alien_x - ripley->x + 50;
}

float Prisoner::transformY(float alien_y, Ripley* ripley) {
	return alien_y - ripley->y + 80;
}
Prisoner::Prisoner(float x, float y) : Pickup(11, 12, x, y)
{
	free_textures[0] = "assets\\Prisoner\\free\\free_1.png";
	free_textures[1] = "assets\\Prisoner\\free\\free_2.png";
	free_textures[2] = "assets\\Prisoner\\free\\free_3.png";
	free_textures[3] = "assets\\Prisoner\\free\\free_4.png";

	trapped_textures[0] = "assets\\Prisoner\\trapped\\trapped_1.png";
	trapped_textures[1] = "assets\\Prisoner\\trapped\\trapped_2.png";
	trapped_textures[2] = "assets\\Prisoner\\trapped\\trapped_3.png";
	trapped_textures[3] = "assets\\Prisoner\\trapped\\trapped_4.png";
	trapped_textures[4] = "assets\\Prisoner\\trapped\\trapped_5.png";

	br.outline_opacity = 0.0f;
	br.texture = "";
}

void Prisoner::draw(Ripley* ripley)
{
	if (trapped) {
		int frame = ((int)(frame_timer / FRAME_SPEED)) % (TOTAL_TRAPPED_FRAMES)+FRAME_TRAPPED_INDEX_MIN;
		//cout << "frame: " << frame <<endl;
		br.texture = trapped_textures[frame];
	}
	else {
		int frame = ((int)(frame_timer / FRAME_SPEED)) % (TOTAL_FREE_FRAMES)+FRAME_FREE_INDEX_MIN;
		br.texture = free_textures[frame];
	}

	graphics::drawRect(transformX(x, ripley), transformY(y, ripley), width, height, br);
}

void Prisoner::reset()
{
	frame_timer = 0;
}


void Prisoner::update(float ms)
{

	frame_timer = frame_timer + ms;
}





void Prisoner::applyCollisionEvent(Ripley* ripley)
{
	ripley->prisonersDecrease();
	Audio::playPrisonersSound();
	trapped = false;
	free = true;
}

