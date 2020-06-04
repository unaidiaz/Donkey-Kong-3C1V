#ifndef __HOWHIGH2__H
#define __HOWHIGH2__H

#include "Module.h"
#include "Animation.h"

struct SDL_Texture;

class HowHigh2 : public Module
{
public:
	//Constructor
	HowHigh2(bool startEnabled);

	//Destructor
	~HowHigh2();
	// Called when the module is activated
	// Loads the necessary textures for the map background
	bool Start() override;

	// Called at the middle of the application loop
	// Updates the scene's background animations
	update_status Update() override;

	// Called at the end of the application loop.
	// Performs the render call of all the parts of the scene's background
	update_status PostUpdate() override;

	void DebugDrawGamepadInfo();

	// Disables the player and the enemies
	bool CleanUp();
private:

	SDL_Texture* background = nullptr;


	// Font score index
	int temp = 0;
	uint _score = 000000;
	uint _highscore = 000000;
	uint _bonus = 5000;
	int rojas = -1;
	int blancas = -1;
	int amarillas = -1;
	char _scoreText[7] = { "\0" };
	char _highscoreText[7] = { "\0" };
	char _bonusText[5] = { "\0" };
	int cont_win_lose = 0;
	int cont_music = 0;
	int cont = 0;
	bool debugGamepadInfo = false;

};
#endif