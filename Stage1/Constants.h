#pragma once


namespace Constants {
	const bool APPLY_WORLD_BOUNDARIES = true;
	const bool APPLY_COLLISION_DETECTION_WITH_ALIENS = true;
	const bool APPLY_COLLISION_DETECTION_WITH_PICKUPS = true;	
	const bool APPLY_COLLISION_DETECTION_WITH_DOOR = true;
	const float RIPLEY_SPEED_FACTOR = 0.8f;
	const float GRAVITY_FACTOR = 3;
	const float JUMP_GRAVITY_FACTOR = 1;
	const bool PRINT_STATE = true;
	const bool GRAVITY = true;
	const bool FANS = true;

	// Normal Spawn point:
	const float RIPLEY_INITIAL_X = 53;
	const float RIPLEY_INITIAL_Y = 28.5f;

	const int SHOOT_COOLDOWN = 300; // 0 for disable (ms)
	const int SHOOT_FRAME_COOLDOWN = 300; // 0 for disable (ms)

	//
	// Time in ms
	//
	const float EASY_MAX_ALLOWED_TIME = 5*60000;
	const float MEDIUM_MAX_ALLOWED_TIME = 4*60000;
	const float HARD_MAX_ALLOWED_TIME = 3* 60000;


	const float BULLET_LIFETIME = 300;

	const float JUMP_DURATION = 400;
}