#include "Enemy_Barrilazul.h"

#include"ModuleEnemies.h"
#include "Application.h"
#include "ModuleCollisions.h"


Enemybarrilazul::Enemybarrilazul(int x, int y, int direccion) : Enemy(x, y)
{
	barrilarodando.PushBack({ 0,14,12,12 });
	barrilarodando.PushBack({ 16,14,13,12 });
	barrilarodando.PushBack({ 33,14,13,12 });
	barrilarodando.PushBack({ 50,14,13,12 });
	barrilarodando.loop = true;
	barrilarodando.speed = 0.1f;
	frames1 = 0;
	barrilacallendo.PushBack({ 0,0,16,11 });
	barrilacallendo.PushBack({ 20,0,16,11 });
	barrilacallendo.loop = true;
	barrilacallendo.speed = 0.1f;
	top1 = true;

	dire = direccion;
	/////
	typo = tipo::barrilazul;
	estado = state::recto;
	contsub = 0;
	//////
	currentAnim = &barrilarodando;
	collider = App->collisions->AddCollider({ 0, 0, 25, 11 }, Collider::Type::Enemigo, (Module*)App->enemies);
	collider1 = App->collisions->AddCollider({ 0, 0, 5, 5 }, Collider::Type::top, (Module*)App->enemies);

}

void Enemybarrilazul::Update()
{
	if (estado == state::recto) {
		position.x = (position.x + (2 * dire));
		if (currentAnim != &barrilarodando) {
			currentAnim = &barrilarodando;
		}

		estado = state::libre;

	}
	else if (estado == state::libre) {

		position.y = position.y + 3;
		//position.x = (position.x + (1 * dire));
		if (contsub == 5) {
			
			if (dire == 1) {
				dire = -1;
			}
			else {
				dire = 1;
			}
		}
		//frames1++;
		contsub++;
		//estado == state::recto;
	}
	else if (estado == state::bajando) {
		if (currentAnim != &barrilacallendo) {
			currentAnim = &barrilacallendo;
		}

		position.y = position.y + 2;
		if (top1 == true) {
			top1 = false;
		}
		else {

			top1 = true;
			estado = state::recto;
			if (dire == 1) {
				dire = -1;
			}
			else {
				dire = 1;
			}
		}

	}
	if (position.x < 67 && position.y>645) {
		Enemy::destr();
		App->enemies->AddEnemy(Enemy_Type::LLAMA, 80, 703, 1);

	}
	frames1++;

	Enemy::Update();
}