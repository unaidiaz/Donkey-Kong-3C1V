#include "Enemy_Barril.h"

#include "Application.h"
#include "ModuleCollisions.h"


Enemybarril::Enemybarril(int x, int y, int direccion) : Enemy(x, y)
{
	barrilrodando.PushBack({ 0,50,12,12 });
	barrilrodando.PushBack({ 16,50,13,12 });
	barrilrodando.PushBack({ 33,50,13,12 });
	barrilrodando.PushBack({ 50,50,13,12 });
	barrilrodando.loop = true;
	barrilrodando.speed = 0.1f;
	frames1 = 2;
	barrilcallendo.PushBack({ 0,35,16,11 });
	barrilcallendo.PushBack({ 20,35,16,11 });
	barrilcallendo.loop = true;
	barrilcallendo.speed = 0.1f;
	top1 = true;

	dire = direccion;
	/////
	typo = tipo::barril;
	estado = state::recto;
	contsub = 0;
	//////
	currentAnim = &barrilrodando;
	collider = App->collisions->AddCollider({ 0, 0, 25, 11 }, Collider::Type::Enemigo, (Module*)App->enemies);
	collider1 = App->collisions->AddCollider({ 0, 0, 5, 5 }, Collider::Type::top, (Module*)App->enemies);

}

void Enemybarril::Update()
{
	if (estado == state::recto) {
		position.x = (position.x + (2 * dire));
		currentAnim = &barrilrodando;
		estado = state::libre;
	}
	else if (estado == state::libre) {

		position.y = position.y + 3;
		if (contsub == 3) {
			if (dire == 1) {
				dire = -1;
			}
			else {
				dire = 1;
			}
		}
		contsub++;
		//estado == state::recto;
	}
	else if (estado == state::bajando) {
		currentAnim = &barrilcallendo;
		position.y = position.y + 2;
		if (top1 == true) {
			top1 = false;
		}
		else {

			top1 = true;
			estado = state::libre;
		}

	}
	if (position.x < -5 || position.x > 672) {
		destr();
	}
	frames1++;

	Enemy::Update();
}