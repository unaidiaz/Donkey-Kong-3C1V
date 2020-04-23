#include"placa.h"
#include "Application.h"
#include "ModuleCollisions.h"
#include "ModulePlayer.h"

placa::placa(int x, int y) : Objet(x, y)
{
	placaa.PushBack({ 0,0,8,8 });
	

	currentAnim = &placaa;

	colob = App->collisions->AddCollider({ 0, 0, 5,90 }, Collider::Type::objeto, (Module*)App->objet);
}

void placa::Update()
{

	
	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Objet::Update();
}