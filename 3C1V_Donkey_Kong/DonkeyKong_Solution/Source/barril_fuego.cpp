#include"barril_fuego.h"
#include "Application.h"
#include "ModuleCollisions.h"
#include "ModulePlayer.h"

barril_fuego::barril_fuego(int x, int y) : Objet(x, y)
{
	barril_fuego_anim.PushBack({ 92,71,17,25 });
	barril_fuego_anim.PushBack({ 111,71,17,25 });
	barril_fuego_anim.loop = true;
	barril_fuego_anim.speed = 0.1f;

	currentAnim = &barril_fuego_anim;

	//obcollider = App->collisions->AddCollider({ 120, 170,40,40 }, Collider::Type::objeto, (Module*)App->objet);
}

void barril_fuego::Update()
{
	currentAnim->Update();

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Objet::Update();
}