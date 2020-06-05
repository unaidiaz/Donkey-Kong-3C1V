#ifndef __SCENE_LEVEL1_H__
#define __SCENE_LEVEL1_H__

#include "Module.h"
#include "Animation.h"

struct SDL_Texture;

class SceneLevel1 : public Module
{
public:
	//Constructor
	SceneLevel1(bool startEnabled);

	//Destructor
	~SceneLevel1();

	Collider* bolso_col = nullptr;
	Collider* paraguas_col = nullptr;
	Collider* tanque_col = nullptr;

	// Called when the module is activated
	// Loads the necessary textures for the map background
	bool Start() override;

	void sum_points_300()
	{
		_score += 300;
	}
	void sum_points_100()
	{
		_score += 100;
	}
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

	SDL_Texture* testTexture = nullptr;
	SDL_Texture* martillo2 = nullptr;
	SDL_Texture* martillo = nullptr;
	SDL_Texture* kong = nullptr;
	SDL_Texture* _tanque = nullptr;
	SDL_Texture* _bolso = nullptr;
	SDL_Texture* _paraguas = nullptr;
	SDL_Texture* bgTexture = nullptr;
	SDL_Texture* princesa = nullptr;
	SDL_Texture* highscore = nullptr;
	SDL_Texture* oneup = nullptr;
	SDL_Texture* bonus = nullptr;
	SDL_Texture* lvl = nullptr;
	SDL_Texture* four = nullptr;
	SDL_Texture* littlemario = nullptr;
	SDL_Texture* barriles_4 = nullptr;
	SDL_Texture* vida3 = nullptr;

	// Font score index
	int temp = 0;
	uint _score = 000000;
	uint _highscore = 000000;
	uint _bonus = 5000;
	int rojas = -1;
	int blancas = -1;
	int azules = -1;
	char _scoreText[7] = { "\0" };
	char _highscoreText[7] = { "\0" };
	char _bonusText[5] = { "\0" };
	int cont_win_lose = 0;
	int cont_music = 0;
	int cont = 0;
	bool debugGamepadInfo = false;

};
#endif