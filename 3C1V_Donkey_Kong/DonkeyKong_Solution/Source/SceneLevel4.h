#ifndef __SCENE_LEVEL4_H__
#define __SCENE_LEVEL4_H__

#include "Module.h"
#include "Animation.h"

struct SDL_Texture;

class SceneLevel4 : public Module
{
public:
	//Constructor
	SceneLevel4(bool startEnabled);

	//Destructor
	~SceneLevel4();

	// Called when the module is activated
	// Loads the necessary textures for the map background
	bool Start() override;

	// Called at the middle of the application loop
	// Updates the scene's background animations
	update_status Update() override;

	// Called at the end of the application loop.
	// Performs the render call of all the parts of the scene's background
	update_status PostUpdate() override;

	// Disables the player and the enemies
	bool CleanUp();
private:

	SDL_Texture* testTexture = nullptr;
	SDL_Texture* martillo2 = nullptr;
	SDL_Texture* martillo = nullptr;
	SDL_Texture* kong = nullptr;
	SDL_Texture* placas = nullptr; SDL_Texture* placas2 = nullptr; SDL_Texture* placas3 = nullptr; SDL_Texture* placas4 = nullptr; SDL_Texture* placas5 = nullptr;
	SDL_Texture* placas6 = nullptr; SDL_Texture* placas7 = nullptr; SDL_Texture* placas8 = nullptr; SDL_Texture* placas9 = nullptr;
	SDL_Texture* _tanque = nullptr;
	SDL_Texture* _bolso = nullptr;
	SDL_Texture* _paraguas = nullptr;
	SDL_Texture* bgTexture = nullptr;
};
#endif