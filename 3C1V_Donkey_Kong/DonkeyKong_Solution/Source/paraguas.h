#ifndef _PARAGUAS_H_
#define _PARAGUAS_H_

#include"objet.h"

class paraguas : public Objet
{
public:

	// Constructor (x y coordinates in the world)
	// Creates animation data and the collider
	paraguas(int x, int y);

	// The enemy is going to perform a sinusoidal movement
	void Update() override;

private:
	// The position (as ratio) in the wave at a specific moment


	// The original spawning position. The wave will be calculated from that

	// The enemy animation
	Animation paraguass;
};

#endif // 