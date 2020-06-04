#ifndef __ENEMY_KONG_H__
#define __ENEMY_KONG_H__

#include "Enemy.h"

class Enemy_Kong : public Enemy
{
public:

	// Constructor (x y coordinates in the world)
	// Creates animation data and the collider
	Enemy_Kong(int x, int y, int direccion);

	// The enemy is going to perform a sinusoidal movement
	void Update() override;

private:
	// The position (as ratio) in the wave at a specific moment
	float waveRatio = 0.0f;

	// The speed at which the wave ratio is increased
	float waveRatioSpeed = 0.05f;

	// The original spawning position. The wave will be calculated from that
	int spawn_y = 0;

	// The total height of the wave
	int waveHeight = 15;

	// The enemy animation
	Animation kong_dead_2;
	Animation kong_alive;
	Animation kong_falling;
	Animation kong_dead_1;
	Animation kong_barril;
	Animation kong_barril_azul;
	int cont = 0;
};

#endif // __ENEMY_REDBIRD_H__