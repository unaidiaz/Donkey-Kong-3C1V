#include"bolso.h"
#include "Application.h"
#include "ModuleCollisions.h"
#include "ModulePlayer.h"

bolso::bolso(int x, int y) : Objet(x, y)
{
	bolsoo.PushBack({ 14,5,10,10 });


	currentAnim = &bolsoo;

	_bolso = App->collisions->AddCollider({ 390, 670,25,35 }, Collider::Type::bolso, (Module*)App->objet);
}

void bolso::Update()
{


	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Objet::Update();
}