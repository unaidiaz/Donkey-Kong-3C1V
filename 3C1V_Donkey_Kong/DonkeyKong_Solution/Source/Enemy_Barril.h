#ifndef __ENEMY_BARRIL_H__
#define __ENEMY_BARRIL_H__

#include "Enemy.h"
class Enemybarril : public Enemy
{
public:

	// Constructor (x y coordinates in the world)
	// Creates animation data and the collider
	Enemybarril(int x, int y, int direccion);
	// The enemy is going to perform a sinusoidal movement
	void Update() override;

private:
	// The position (as ratio) in the wave at a specific moment


	// The enemy animation
	Animation barrilrodando;
	Animation barrilcallendo;
};

#endif
