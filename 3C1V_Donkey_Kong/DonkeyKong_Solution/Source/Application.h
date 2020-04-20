#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 9

class Module;
class ModuleCollisions;
class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleAudio;
class ModulePlayer;
class SceneLevel4;
class ModuleEnemies;
class ModuleRender;

class Application
{

public:

	//Constructor. Creates all necessary modules for the application
	Application();

	//Destructor. Removes all module objects
	~Application();

	//Initializes all modules
	bool Init();

	//Updates all modules (PreUpdate, Update and PostUpdate)
	update_status Update();

	//Releases all the application data
	bool CleanUp();

public:

	Module* modules[NUM_MODULES];

	ModuleWindow* window = nullptr;
	ModuleInput* input = nullptr;
	ModuleTextures* textures = nullptr;
	ModuleAudio* audio = nullptr;

	SceneLevel4* scene4 = nullptr;
	ModulePlayer* player = nullptr;
	ModuleEnemies* enemies = nullptr;

	ModuleCollisions* collisions = nullptr;
	
	ModuleRender* render = nullptr;	
};

// Global var made extern for Application ---
extern Application* App;

#endif // __APPLICATION_H__