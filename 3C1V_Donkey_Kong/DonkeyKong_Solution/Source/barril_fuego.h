#ifndef _BARRIL_FUEGO_H_
#define _BARRIL_FUEGO_H_

#include"objet.h"

class barril_fuego : public Objet
{
public:

	// Constructor (x y coordinates in the world)
	// Creates animation data and the collider
	barril_fuego(int x, int y);

	// The enemy is going to perform a sinusoidal movement
	void Update() override;

private:
	// The position (as ratio) in the wave at a specific moment


	// The original spawning position. The wave will be calculated from that

	// The enemy animation
	Animation barril_fuego_anim;
};

#endif // 