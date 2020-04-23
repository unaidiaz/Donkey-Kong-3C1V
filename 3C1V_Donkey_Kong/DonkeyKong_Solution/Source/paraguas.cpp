#include"paraguas.h"
#include "Application.h"
#include "ModuleCollisions.h"
#include "ModulePlayer.h"

paraguas::paraguas(int x, int y) : Objet(x, y)
{
	paraguass.PushBack({ 50,0,17,15 });


	currentAnim = &paraguass;

	obcollider = App->collisions->AddCollider({ 120, 170,40,40 }, Collider::Type::objeto, (Module*)App->objet);
}

void paraguas::Update()
{


	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Objet::Update();
}