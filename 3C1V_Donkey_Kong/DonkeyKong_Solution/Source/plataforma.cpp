#include"plataforma.h"
#include "Application.h"
#include "ModuleCollisions.h"
#include "ModulePlayer.h"

plataforma::plataforma(int x, int y) : Objet(x, y)
{
	plataforma_anim.PushBack({ 31,63,17,9 });


	currentAnim = &plataforma_anim;

	obcollider = App->collisions->AddCollider({ -10, 0,51,27 }, Collider::Type::plataforma, (Module*)App->objet);
}

void plataforma::Update()
{
	position.y --;
	if (position.y<=291)
	{
		position.y = 699;
	}
	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Objet::Update();
}