#include "Enemy_Llama.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModulePlayer.h"

Enemy_Llama::Enemy_Llama(int x, int y,int direccion) : Enemy(x, y)
{
	llama.PushBack({ 0,63,15,17 });
	llama.PushBack({ 17, 64, 14, 16 });
	llama.loop = true;
	llama.speed = 0.1f;
	dire = direccion;
	typo = tipo::llama;
	currentAnim = &llama;
	estado = state::recto;
	//////
	prior1 = 0;
	contsub = 0;
	top1 = true;
	top2 = true;
	frames1 = 2;
	frames2 = 2;
	currentAnim = &llama;

	collider = App->collisions->AddCollider({ 0, 0, 24, 24 }, Collider::Type::Enemigo, (Module*)App->enemies);
	collider1 = App->collisions->AddCollider({ 0, 0, 5, 5 }, Collider::Type::top, (Module*)App->enemies);
}

void Enemy_Llama::Update()
{


	if (estado == state::recto) {
		position.x = position.x + (dire);
		
		estado = state::libre;
	}
	else if (estado == state::bajando) {
		position.y = position.y + 1;
		prior1 = 0;
	}
	else if (estado == state::subiendo) {
		if (top2 == false) {
			position.y = position.y - 1;
		}
		else {
			if (contsub < 57) {
				position.y = position.y - 1;
				contsub++;
			}
			else {
				estado = state::recto;
				top2 = true;
				contsub=0;
			}
			
		}
		
	}
	else if (estado == state::libre) {
		if (dire == 1) {
			dire = -1;
		}
		else {
			dire = 1;
		}
		estado = state::recto;
	}
	
	frames1++;
	frames2++;
	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();	
}

