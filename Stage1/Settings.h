#pragma once

#include "Constants.h"

#include <string>
#include <stdexcept>

using namespace std;

enum Difficulty {
	EASY,
	MEDIUM,
	HARD
};

class Settings
{
public:
	int tries = 3;
	Difficulty difficulty = EASY;
	int window_width = 1024;
	int window_height = 768;
	float fx_volume = 0.2f;
	float music_volume = 0.2f;

	float getMaxAllowedTime() const {
		switch (difficulty) {
		case EASY:
			return Constants::EASY_MAX_ALLOWED_TIME;
		case MEDIUM:
			return Constants::MEDIUM_MAX_ALLOWED_TIME;			
		case HARD:
			return Constants::HARD_MAX_ALLOWED_TIME;
		}

		throw std::out_of_range("this hould never happen");
	}

	string getDifficultyText() const {
		switch (difficulty) {
		case EASY:
			return "EASY";
		case MEDIUM:
			return "MEDIUM";
		case HARD:
			return "HARD";
		}

		throw std::out_of_range("this hould never happen");
	}
};


