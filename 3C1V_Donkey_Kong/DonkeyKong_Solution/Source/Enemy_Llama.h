#ifndef __ENEMY_LLAMA_H__
#define __ENEMY_LLAMA_H__

#include "Enemy.h"

class Enemy_Llama : public Enemy
{
public:

	// Constructor (x y coordinates in the world)
	// Creates animation data and the collider
	Enemy_Llama(int x, int y,int direccion);

	// The enemy is going to perform a sinusoidal movement
	void Update() override;
	int cont;
	int cont2;
	int comp;
private:
	state rando(Collider* collider);
	void subir_o_bajar(Collider* collider);
	int num;
	Animation llama;
	Animation llama_azul;
};

#endif // __ENEMY_REDBIRD_H__