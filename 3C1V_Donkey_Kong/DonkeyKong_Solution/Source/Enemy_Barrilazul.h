#ifndef __ENEMY_BARRILAZUL_H__
#define __ENEMY_BARRILAZUL_H__

#include "Enemy.h"
class Enemybarrilazul : public Enemy
{
public:

	// Constructor (x y coordinates in the world)
	// Creates animation data and the collider
	Enemybarrilazul(int x, int y, int direccion);
	// The enemy is going to perform a sinusoidal movement
	void Update() override;

private:
	// The position (as ratio) in the wave at a specific moment


	// The enemy animation
	Animation barrilarodando;
	Animation barrilacallendo;
};

#endif
