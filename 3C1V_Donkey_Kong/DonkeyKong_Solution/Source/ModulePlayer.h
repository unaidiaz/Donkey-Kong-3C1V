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
class posicion 
{
public:
	int x, y;
};
class ModulePlayer : public Module 
{
public:
	ModulePlayer(bool startEnabled);
	bool Start();
	void jump();
	void OnCollision(Collider* c1, Collider* c2);
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();
	posicion Posicion;
	Animation* lastanimation = nullptr;
	Animation* currentAnimation = nullptr;
	int tecla = 0;
	// A set of animations
	Animation parado_der_mart;
	Animation parado_izq_mart;

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

	Animation saltarder;
	Animation saltariz;
	Animation topescalera;
	bool escalera = false;
	Animation espalda;
	bool plataforma = false;
	Collider* collider = nullptr;
	Collider* collider2 = nullptr;
	Collider* salto1 = nullptr;
	Collider* mart = nullptr; Collider* mart2 = nullptr;
	SDL_Texture* mario = nullptr;
	SDL_Texture* win = nullptr;
	SDL_Texture* lose = nullptr;
	int cont = 0;
	int cont_muerte = 0;
	bool jumpact = false;
	bool canAudioJump = true;
	bool canLateralMov = true;
	bool hammerMode = false;
	int hammerCont = 0;
	int paso;
	int salto;
	int placaSound;
	int muerteMario = 0;
	int contador = 0;
	int contToFade = 0;
	int cont_win = 0;
	bool _win = false;
	bool _lose = false;
	bool destroyed = false;
	int vidas=3;
	bool debugGamepadInfo = false;
	int contvidas = 0;
	int lvl = 1;
	int contmusicamuerte = 0;
private:
	SDL_Texture* marioo = nullptr;
	// Debugdraw for gamepad data

};
#endif
