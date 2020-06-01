#ifndef _MODULEOBJET_H_
#define _MODULEOBJET_H_
#include"objet.h"
#include "Module.h"

#define MAX_OBJET 100

enum class Objet_Type
{
	NO_TYPE,
	placa,
	tanque,
	bolso,
	paraguas,
	barril_fuego,
	martillo
};

struct objet_Spawnpoint
{
	Objet_Type type = Objet_Type::NO_TYPE;
	int x, y;
};

struct SDL_Texture;

class ModuleObjet : public Module
{
public:
	// Constructor
	ModuleObjet(bool startEnabled);
	update_status PreUpdate();
	// Destructor
	~ModuleObjet();

	// Called when the module is activated
	// Loads the necessary textures for the enemies
	bool Start() override;

	// Called at the beginning of the application loop
	// Removes all enemies pending to delete
	// update_status PreUpdate() override;

	// Called at the middle of the application loop
	// Handles all enemies logic and spawning/despawning
	update_status Update() override;

	// Called at the end of the application loop
	// Iterates all the enemies and draws them
	update_status PostUpdate() override;

	// Called on application exit
	// Destroys all active enemies left in the array
	bool CleanUp() override;

	// Called when an enemi collider hits another collider
	// The enemy is destroyed and an explosion particle is fired
	void OnCollision(Collider* c1, Collider* c2) override;

	// Add an enemy into the queue to be spawned later
	bool AddObjet(Objet_Type type, int x, int y);

	// Iterates the queue and checks for camera position
	void HandleObjetSpawn();

	// Destroys any enemies that have moved outside the camera limits
	void HandleObjetDespawn();
	bool compene();
private:
	// Spawns a new enemy using the data from the queue
	void SpawnObjet(const objet_Spawnpoint& info);

private:
	// A queue with all spawn points information
	objet_Spawnpoint spawnQueue[MAX_OBJET];

	// All spawned enemies in the scene

	/////
	//Enemy* enemies[MAX_ENEMIES] = { nullptr };
	//////
	Objet* objetos[MAX_OBJET] = {nullptr};
	// The enemies sprite sheet
	SDL_Texture* objetostex = nullptr;
	SDL_Texture* objetosanim = nullptr;
	// The audio fx for destroying an enemy
	//int enemyDestroyedFx = 0;
};

#endif // __MODULE_ENEMIES_H__
