#include"Victoria.h"
#include "Application.h"
#include "ModuleCollisions.h"
#include "ModulePlayer.h"

Victoria::Victoria(int x, int y) : Objet(x, y)
{
	obcollider = App->collisions->AddCollider({ 0, 0, 5,90 }, Collider::Type::Victoria, (Module*)App->objet);
}

void Victoria::Update()
{
	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Objet::Update();
}