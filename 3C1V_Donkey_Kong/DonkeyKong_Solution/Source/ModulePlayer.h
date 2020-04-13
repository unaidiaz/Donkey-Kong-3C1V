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
	int x, y,velo=1;
};
class ModulePlayer :public Module {
public:
	ModulePlayer();
	bool Init();
	void jump();
	void OnCollision(Collider* c1, Collider* c2);
	update_status Update();
	update_status PostUpdate();
	posicion Posicion;
	Animation* currentAnimation = nullptr;
	int tecla=0;
	// A set of animations
	Animation derecha;
	Animation izquierda;
	Animation arriba;
	Animation abajo;
	Animation saltar;
	Animation paradoder;
	Animation paradoizq;
	Animation saltarder;
	Animation saltariz;
	
	bool escalera = false;
	Collider* collider=nullptr;
	int cont = 0;
	bool jumpact = false;
private:
	SDL_Texture* marioo=nullptr;
};
#endif
