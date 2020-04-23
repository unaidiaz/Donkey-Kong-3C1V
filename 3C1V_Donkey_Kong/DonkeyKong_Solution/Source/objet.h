#pragma once
#ifndef _OBJET_H_
#define _OBJET_H_

#include "p2Point.h"
#include "Animation.h"

struct SDL_Texture;
struct Collider;

class Objet
{
public:
	// Constructor
	// Saves the spawn position for later movement calculations
	Objet(int x, int y);

	// Destructor
	virtual ~Objet();

	// Returns the enemy's collider
	const Collider* GetCollider() const;

	// Called from inhering enemies' Udpate
	// Updates animation and collider position
	virtual void Update();

	// Called from ModuleEnemies' Update
	virtual void Draw();

	// Collision response
	// Triggers an animation and a sound fx
	virtual void OnCollision(Collider* collider);

public:
	bool pendingToDelete = false;
	void destr();
	// Current Position in the world
	iPoint position;

	// The enemy's texture
	SDL_Texture* placatext = nullptr;
	SDL_Texture* tanquetext = nullptr;
	SDL_Texture* bolsotext = nullptr;
	SDL_Texture* paraguastext = nullptr;
	SDL_Texture* objetos = nullptr;
	// Sound fx when destroyed
	//int destroyedFx = 0;

protected:
	// A ptr to the current animation
	Animation* currentAnim = nullptr;

	// The enemy's collider
	Collider* obcollider = nullptr;
	// Original spawn position
	iPoint spawnPos;
};

#endif // __ENEMY_H__*/
