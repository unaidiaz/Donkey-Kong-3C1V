#include"plataforma.h"
#include "Application.h"
#include "ModuleCollisions.h"
#include "ModulePlayer.h"

plataforma::plataforma(int x, int y) : Objet(x, y)
{
	plataforma_anim.PushBack({ 31,63,17,9 });


	currentAnim = &plataforma_anim;

	p_collider = App->collisions->AddCollider({ -10, 0,51,27 }, Collider::Type::plataforma, (Module*)App->objet);
}

void plataforma::Update()
{
	if (position.x==88)
	{
		position.y-=2;
		if (position.y <= 291)
		{
			position.y = 699;
		}
	}
	else
	{
		position.y+=2;
		if (position.y >= 700)
		{
			position.y = 292;
		}
	}
	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Objet::Update();
}