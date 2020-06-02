#include"tanque.h"
#include "Application.h"
#include "ModuleCollisions.h"
#include "ModulePlayer.h"

tanque::tanque(int x, int y) : Objet(x, y)
{
	tanquee.PushBack({ 30,6,16,9 });


	currentAnim = &tanquee;

	p_collider = App->collisions->AddCollider({ 530, 553,40,20 }, Collider::Type::objeto, (Module*)App->objet);
}

void tanque::Update()
{


	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Objet::Update();
}