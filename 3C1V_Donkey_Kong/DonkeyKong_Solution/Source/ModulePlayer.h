#ifndef _MODULEPLAYER_H_
#define _MODULEPLAYER_H_
#include"Application.h"
#include"ModuleRender.h"
#include"ModuleTextures.h"
#include"Animation.h"
#include"Module.h"
struct SDL_Rect;
struct SDL_Texture;
struct SDL_Renderer;
struct Collider;
class posicion {
public:
	int x, y;
};
class ModulePlayer : public Module {
public:
	ModulePlayer(bool startEnabled);
	bool Start();
	void jump();
	void OnCollision(Collider* c1, Collider* c2);
	update_status Update();
	update_status PostUpdate();
	posicion Posicion;
	Animation* lastanimation = nullptr;
	Animation* currentAnimation = nullptr;
	int tecla=0;
	// A set of animations
	Animation dead_mario_l;
	Animation dead_mario_r;
	Animation mart_iz;
	Animation mart_der;
	Animation derecha;
	Animation izquierda;
	Animation arriba;
	Animation abajo;
	Animation saltar;
	Animation paradoder;
	Animation paradoizq;
	Animation paradoder_mart;
	Animation paradoizq_mart;
	Animation saltarder;
	Animation saltariz;
	Animation topescalera;
	bool escalera = false;
	Animation espalda;
	bool plataforma = false;
	Collider* collider=nullptr;
	Collider* mart = nullptr; Collider* mart2 = nullptr;
	SDL_Texture* mario = nullptr;
	int cont = 0;
	bool jumpact = false;
	bool canJump = true;
	bool canAudioJump = true;
	bool canLateralMov = true;
	int paso;
	int salto;
	int contador = 0;
	int cont_muerte = 0;
private:
	SDL_Texture* marioo=nullptr;
};
#endif
