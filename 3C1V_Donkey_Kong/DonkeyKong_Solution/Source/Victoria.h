#ifndef _PLACA_H_
#define _PLACA_H_

#include"objet.h"

class Victoria : public Objet
{
public:

	// Constructor (x y coordinates in the world)
	// Creates animation data and the collider
	Victoria(int x, int y);

	// The enemy is going to perform a sinusoidal movement
	void Update() override;

private:
	// The position (as ratio) in the wave at a specific moment


	// The original spawning position. The wave will be calculated from that

	// The enemy animation
};

#endif // __ENEMY_REDBIRD_H__