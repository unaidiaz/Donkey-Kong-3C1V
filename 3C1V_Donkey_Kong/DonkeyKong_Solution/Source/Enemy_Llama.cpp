#include "Enemy_Llama.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModulePlayer.h"

Enemy_Llama::Enemy_Llama(int x, int y,int direccion) : Enemy(x, y)
{
	llama.PushBack({ 0,63,15,17 });
	llama.PushBack({ 17, 64, 14, 16 });
	llama.PushBack({ 34, 66, 16, 13 });
	llama.loop = true;
	llama.speed = 0.1f;
	dire = direccion;
	
	currentAnim = &llama;

	collider = App->collisions->AddCollider({ 0, 0, 24, 24 }, Collider::Type::Enemigo, (Module*)App->enemies);
}

void Enemy_Llama::Update()
{
	if (estado == state::recto) {
		position.x = position.x + (dire);
		switch (position.y)
		{
		case 680:
		
			if (position.x > 640) {
				dire = -1;
			}
			else if (position.x < 0) {
				dire = 1;
			}
			break;
		case 560:
			if (position.x > 615) {
				dire = -1;
			}
			else if (position.x < 11) {
				dire = 1;
			}

			break;
		case 440:
			if (position.x > 580) {
				dire = -1;
			}
			else if (position.x < 35) {
				dire = 1;
			}

			break;
		case 320:
			if (position.x > 560) {
				dire = -1;
			}
			else if (position.x < 59) {
				dire = 1;
			}
			break;
		case 200:
			if (position.x > 535) {
				dire = -1;
			}
			else if (position.x < 83) {
				dire = 1;
			}
			break;
		case 400:
			if (position.x > 250)
			{
				dire = -1;
			}
			else if (position.x < 150)
			{
				dire = 1;
			}
			break;
		case 420:
			if (position.x > 630)
			{
				dire = -1;
			}
			else if (position.x < 530)
			{
				dire = 1;
			}
			break;
		}

	}
	else if (estado == state::bajando) {
		position.y = position.y + 2;
		if (position.y == 680 || position.y == 560 || position.y == 440 || position.y == 320 || position.y == 200 || position.y == 400 || position.y == 420) {
			estado = state::recto;
		}
	}
	
	frames++;
	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();	
}

