#include <iostream>

#include "Audio.h"

#include "Settings.h"

using namespace std;
namespace Audio {
	Settings* settings = nullptr;
	bool enabled = true;

	void setSettings(Settings* currentSettings) {
		settings = currentSettings;
	}

	void playMusic(string filename, bool loop)
	{
		//cout << "Playing music: " << filename << endl;
		if (enabled) {
			graphics::playMusic(filename, settings->music_volume, loop);
		}
	}

	void playSound(string filename)
	{
		//cout << "Playing sound: " << filename << endl;

		if (enabled) {
			graphics::playSound(filename, settings->fx_volume);
		}
	}

	void playMainMenuMusic() {
		playMusic("assets\\music\\Beginning.mp3");
	}

	void playStage1Music() {
		playMusic("assets\\music\\Stage1.mp3");
	}

	void playDeathScreenMusic() {
		playMusic("assets\\music\\Death.wav");
	}

	void playVictoryScreenMusic() {
		playMusic("assets\\music\\Victory.mp3", true);
	}

	void playKeySound() {
		playSound("assets\\Sound Effects\\keypad\\keypad_accept.wav");
	}

	void playNoAmmoSound() {
		playSound("assets\\Sound Effects\\Gun\\NoAmmo.wav");
	}

	void playStimSound() {
		playSound("assets\\Sound Effects\\Human\\stim\\marine_stim_inject_01.wav");
	}

	void playPickUpAmmoSound() {
		playSound("assets\\Sound Effects\\Human\\pick ups\\pickup_ammo.wav");
	}

	void playShootingSound() {
		playSound("assets\\Sound Effects\\Gun\\pulse_rifle_01.wav");
	}

	void playAlienAttackSound() {//When an alien attacks
		int choice = 1 + rand() % 4;
		string str = std::to_string(choice);
		string file = "assets\\Sound Effects\\Alien\\Attack\\Attack_0" + str + ".wav";
		playSound(file);
	}

	void playPrisonersSound() {
		int choice = 1 + rand() % 12;
		string str = std::to_string(choice);
		string file = "assets\\Sound Effects\\Human\\Prisoner\\prisoner_" + str + ".wav";
		playSound(file);
	}

	void playDoorSound() {//When all prisoners are collected
		playSound("assets\\Sound Effects\\Human\\Door.wav");
	}

	void playAlienScreachSound() {//When an alien is close or going to attack
		int choice = 1 + rand() % 3;
		string str = std::to_string(choice);
		string file = "assets\\Sound Effects\\Screach\\Screach_0" + str + ".wav";
		playSound(file);
	}

	void playAlienSpawnSound() {//When an alien Spawns
		int choice = 1 + rand() % 5;
		string str = std::to_string(choice);
		string file = "assets\\Sound Effects\\Spawn\\Spawn_0" + str + ".wav";
		playSound(file);
	}

	void playAlienDeathSound() {//When an alien dies
		int choice = 1 + rand() % 9;
		string str = std::to_string(choice);
		string file = "assets\\Sound Effects\\Alien\\Death\\Death_" + str + ".wav";
		playSound(file);
	}

	void playRipleyGotHitSound() {//When Riplay gets hit 
		int choice = 1 + rand() % 8;
		string str = std::to_string(choice);
		string file = "assets\\Sound Effects\\Human\\Blood\\GotHit_0" + str + ".wav";
		playSound(file);
	}

	void playRipleyAreaSecureSound() {//When all Aliens are Dead
		int choice = 1 + rand() % 2;
		string str = std::to_string(choice);
		string file = "assets\\Sound Effects\\Ellen_Ripley\\AreaSecure_" + str + ".WAV";
		playSound(file);
	}

	void playRipleyBugsEverywhereSound() {//When the game starts
		int choice = 1 + rand() % 2;
		string str = std::to_string(choice);
		string file = "assets\\Sound Effects\\Ellen_Ripley\\BugsEverywhere" + str + ".WAV";
		playSound(file);
	}

	void playRipleyDiesSound() {
		playSound("assets\\Sound Effects\\Ellen_Ripley\\Dying.WAV");
	}

	void playRipleyGotToGetOutOfHereSound() {
		int choice = 1 + rand() % 2;
		string str = std::to_string(choice);
		string file = "assets\\Sound Effects\\Ellen_Ripley\\GotToGetOutOfHere_" + str + ".WAV";
		playSound(file);
	}
	
	void playRipleyHurrySound() {
		playSound("assets\\Sound Effects\\Ellen_Ripley\\HurryHurry.WAV");
	}
}

