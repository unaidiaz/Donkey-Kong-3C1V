#include "Muelle.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModulePlayer.h"

Muelle::Muelle(int x, int y, int direccion) : Enemy(x, y)
{
	muelle.PushBack({ 0,104,17,12 });
	muelle.PushBack({ 19,105,16,16 });
	muelle.loop = true;
	muelle.speed = 0.06f;

	currentAnim = &muelle;

	typo = tipo::muelle;

	collider = App->collisions->AddCollider({ 0, 0, 30, 30 }, Collider::Type::Enemigo, (Module*)App->enemies);
}

void Muelle::Update()
{
	position.x += 6; //4
	if (position.x >= 520) {
		position.x -= 6;
		position.y += 10;
	}

	if ((position.x >= 0 && position.x <=74) || (position.x >= 150 && position.x <= 224) || (position.x >= 300 && position.x <= 374) || (position.x >= 450 && position.x <= 524) ) {
		position.y-=2;
	}
	else if ((position.x >= 75 && position.x <= 149) || (position.x >= 225 && position.x <= 299) || (position.x >= 375 && position.x <= 449))  {
		position.y+=2;
	}


	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}

