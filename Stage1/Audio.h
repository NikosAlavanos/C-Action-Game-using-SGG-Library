#pragma once

#include <string>
#include <sgg/graphics.h>
#include "Settings.h"

using namespace std;


namespace Audio {
	void playMusic(string filename, bool loop = false);

	
	void setSettings(Settings* currentSettings);


	//Music
	void playMainMenuMusic();
	void playStage1Music();
	void playDeathScreenMusic();
	void playVictoryScreenMusic();
	
	//Sfx
	void playKeySound();//1 use
	void playNoAmmoSound();//used
	void playStimSound();//used
	void playPickUpAmmoSound();//used
	void playShootingSound();
	void playAlienAttackSound();//used (When an alien attacks)
	void playPrisonersSound();//used
	void playDoorSound();//used (When all prisoners are collected)
	void playAlienScreachSound();//used (When an alien is close or going to attack)
	void playAlienSpawnSound();//not used (When an alien Spawns)
	void playAlienDeathSound();//used (When an alien dies)
	void playRipleyGotHitSound();//not used (When Riplay gets hit )
	void playRipleyAreaSecureSound();//kinda used (When all Aliens are Dead)
	void playRipleyBugsEverywhereSound();//kinda used (When the game starts 50%)
	void playRipleyDiesSound();//used (when Ripley Dies! not from time)
	void playRipleyGotToGetOutOfHereSound();//kinda used (When sinartisi with time)
	void playRipleyHurrySound();//kinda used (When < than 1 min)
};

