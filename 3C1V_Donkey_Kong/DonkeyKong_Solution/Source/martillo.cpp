#include"martillo.h"
#include "Application.h"
#include "ModuleCollisions.h"
#include "ModulePlayer.h"

martillo::martillo(int x, int y) : Objet(x, y)
{
	martillo_anim.PushBack({ 0,4,9,11});


	currentAnim = &martillo_anim;

	obcollider = App->collisions->AddCollider({ 20, 20,9,11 }, Collider::Type::martillo, (Module*)App->objet);
}

void martillo::Update()
{


	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Objet::Update();
}