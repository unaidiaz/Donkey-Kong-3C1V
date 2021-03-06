#include "ModuleCollisions.h"

#include "Application.h"

#include "ModuleRender.h"
#include "ModuleInput.h"
#include "SDL/include/SDL_Scancode.h"

ModuleCollisions::ModuleCollisions(bool startEnabled) : Module(startEnabled)
{
	for (uint i = 0; i < MAX_COLLIDERS; ++i)
		colliders[i] = nullptr;

	matrix[Collider::Type::plataforma][Collider::Type::plataforma] = false;
	matrix[Collider::Type::plataforma][Collider::Type::PLAYER] = true;
	matrix[Collider::Type::plataforma][Collider::Type::Enemigo] = true;
	matrix[Collider::Type::plataforma][Collider::Type::escalera] = false;
	matrix[Collider::Type::plataforma][Collider::Type::martillo] = false;
	matrix[Collider::Type::plataforma][Collider::Type::objeto] = false;
	matrix[Collider::Type::plataforma][Collider::Type::placa] = false;
	matrix[Collider::Type::plataforma][Collider::Type::Victoria] = false;
	matrix[Collider::Type::plataforma][Collider::Type::top] = true;
	matrix[Collider::Type::plataforma][Collider::Type::salto] = true;
	matrix[Collider::Type::plataforma][Collider::Type::player2] = true;

	matrix[Collider::Type::PLAYER][Collider::Type::plataforma] = true;
	matrix[Collider::Type::PLAYER][Collider::Type::PLAYER] = false;
	matrix[Collider::Type::PLAYER][Collider::Type::Enemigo] = true;
	matrix[Collider::Type::PLAYER][Collider::Type::escalera] = true;
	matrix[Collider::Type::PLAYER][Collider::Type::martillo] = true;
	matrix[Collider::Type::PLAYER][Collider::Type::objeto] = true;
	matrix[Collider::Type::PLAYER][Collider::Type::placa] = true;
	matrix[Collider::Type::PLAYER][Collider::Type::Victoria] = true;
	matrix[Collider::Type::PLAYER][Collider::Type::top] = false;
	matrix[Collider::Type::PLAYER][Collider::Type::salto] = false;
	matrix[Collider::Type::PLAYER][Collider::Type::player2] = false;

	matrix[Collider::Type::Enemigo][Collider::Type::plataforma] = true;
	matrix[Collider::Type::Enemigo][Collider::Type::PLAYER] = true;
	matrix[Collider::Type::Enemigo][Collider::Type::Enemigo] = false;
	matrix[Collider::Type::Enemigo][Collider::Type::escalera] = true;
	matrix[Collider::Type::Enemigo][Collider::Type::martillo] = true;
	matrix[Collider::Type::Enemigo][Collider::Type::objeto] = false;
	matrix[Collider::Type::Enemigo][Collider::Type::placa] = false;
	matrix[Collider::Type::Enemigo][Collider::Type::Victoria] = false;
	matrix[Collider::Type::Enemigo][Collider::Type::top] = false;
	matrix[Collider::Type::Enemigo][Collider::Type::salto] = false;
	matrix[Collider::Type::Enemigo][Collider::Type::player2] = false;

	matrix[Collider::Type::escalera][Collider::Type::plataforma] = false;
	matrix[Collider::Type::escalera][Collider::Type::PLAYER] = true;
	matrix[Collider::Type::escalera][Collider::Type::Enemigo] = true;
	matrix[Collider::Type::escalera][Collider::Type::escalera] = false;
	matrix[Collider::Type::escalera][Collider::Type::martillo] = false;
	matrix[Collider::Type::escalera][Collider::Type::objeto] = false;
	matrix[Collider::Type::escalera][Collider::Type::placa] = false;
	matrix[Collider::Type::escalera][Collider::Type::Victoria] = false;
	matrix[Collider::Type::escalera][Collider::Type::top] = true;
	matrix[Collider::Type::escalera][Collider::Type::salto] = true;
	matrix[Collider::Type::escalera][Collider::Type::player2] = false;

	matrix[Collider::Type::martillo][Collider::Type::PLAYER] = true;
	matrix[Collider::Type::martillo][Collider::Type::martillo] = false;
	matrix[Collider::Type::martillo][Collider::Type::escalera] = false;
	matrix[Collider::Type::martillo][Collider::Type::Enemigo] = true;
	matrix[Collider::Type::martillo][Collider::Type::plataforma] = false;
	matrix[Collider::Type::martillo][Collider::Type::objeto] = false;
	matrix[Collider::Type::martillo][Collider::Type::placa] = false;
	matrix[Collider::Type::martillo][Collider::Type::Victoria] = false;
	matrix[Collider::Type::martillo][Collider::Type::top] = false;
	matrix[Collider::Type::martillo][Collider::Type::salto] = false;
	matrix[Collider::Type::martillo][Collider::Type::player2] = false;

	matrix[Collider::Type::objeto][Collider::Type::PLAYER] = true;
	matrix[Collider::Type::objeto][Collider::Type::martillo] = false;
	matrix[Collider::Type::objeto][Collider::Type::escalera] = false;
	matrix[Collider::Type::objeto][Collider::Type::Enemigo] = false;
	matrix[Collider::Type::objeto][Collider::Type::plataforma] = false;
	matrix[Collider::Type::objeto][Collider::Type::objeto] = false;
	matrix[Collider::Type::objeto][Collider::Type::placa] = false;
	matrix[Collider::Type::objeto][Collider::Type::Victoria] = false;
	matrix[Collider::Type::objeto][Collider::Type::top] = false;
	matrix[Collider::Type::objeto][Collider::Type::salto] = false;
	matrix[Collider::Type::objeto][Collider::Type::player2] = false;

	matrix[Collider::Type::placa][Collider::Type::PLAYER] = true;
	matrix[Collider::Type::placa][Collider::Type::martillo] = false;
	matrix[Collider::Type::placa][Collider::Type::escalera] = false;
	matrix[Collider::Type::placa][Collider::Type::Enemigo] = false;
	matrix[Collider::Type::placa][Collider::Type::plataforma] = false;
	matrix[Collider::Type::placa][Collider::Type::objeto] = false;
	matrix[Collider::Type::placa][Collider::Type::placa] = false;
	matrix[Collider::Type::placa][Collider::Type::Victoria] = false;
	matrix[Collider::Type::placa][Collider::Type::top] = false;
	matrix[Collider::Type::placa][Collider::Type::salto] = false;
	matrix[Collider::Type::placa][Collider::Type::player2] = false;

	matrix[Collider::Type::Victoria][Collider::Type::PLAYER] = true;
	matrix[Collider::Type::Victoria][Collider::Type::martillo] = false;
	matrix[Collider::Type::Victoria][Collider::Type::escalera] = false;
	matrix[Collider::Type::Victoria][Collider::Type::Enemigo] = false;
	matrix[Collider::Type::Victoria][Collider::Type::plataforma] = false;
	matrix[Collider::Type::Victoria][Collider::Type::objeto] = false;
	matrix[Collider::Type::Victoria][Collider::Type::placa] = false;
	matrix[Collider::Type::Victoria][Collider::Type::Victoria] = false;
	matrix[Collider::Type::Victoria][Collider::Type::top] = false;
	matrix[Collider::Type::Victoria][Collider::Type::salto] = false;
	matrix[Collider::Type::Victoria][Collider::Type::player2] = false;

	matrix[Collider::Type::top][Collider::Type::PLAYER] = false;
	matrix[Collider::Type::top][Collider::Type::martillo] = false;
	matrix[Collider::Type::top][Collider::Type::escalera] = true;
	matrix[Collider::Type::top][Collider::Type::Enemigo] = false;
	matrix[Collider::Type::top][Collider::Type::plataforma] = true;
	matrix[Collider::Type::top][Collider::Type::objeto] = false;
	matrix[Collider::Type::top][Collider::Type::placa] = false;
	matrix[Collider::Type::top][Collider::Type::Victoria] = false;
	matrix[Collider::Type::top][Collider::Type::top] = false;
	matrix[Collider::Type::top][Collider::Type::salto] = false;
	matrix[Collider::Type::top][Collider::Type::player2] = false;

	matrix[Collider::Type::salto][Collider::Type::PLAYER] = false;
	matrix[Collider::Type::salto][Collider::Type::martillo] = false;
	matrix[Collider::Type::salto][Collider::Type::escalera] = true;
	matrix[Collider::Type::salto][Collider::Type::Enemigo] = false;
	matrix[Collider::Type::salto][Collider::Type::plataforma] = true;
	matrix[Collider::Type::salto][Collider::Type::objeto] = false;
	matrix[Collider::Type::salto][Collider::Type::placa] = false;
	matrix[Collider::Type::salto][Collider::Type::Victoria] = false;
	matrix[Collider::Type::salto][Collider::Type::top] = false;
	matrix[Collider::Type::salto][Collider::Type::salto] = false;
	matrix[Collider::Type::salto][Collider::Type::player2] = false;

	matrix[Collider::Type::player2][Collider::Type::PLAYER] = false;
	matrix[Collider::Type::player2][Collider::Type::martillo] = false;
	matrix[Collider::Type::player2][Collider::Type::escalera] = false;
	matrix[Collider::Type::player2][Collider::Type::Enemigo] = true;
	matrix[Collider::Type::player2][Collider::Type::plataforma] = true;
	matrix[Collider::Type::player2][Collider::Type::objeto] = false;
	matrix[Collider::Type::player2][Collider::Type::placa] = false;
	matrix[Collider::Type::player2][Collider::Type::Victoria] = false;
	matrix[Collider::Type::player2][Collider::Type::top] = false;
	matrix[Collider::Type::player2][Collider::Type::salto] = false;
	matrix[Collider::Type::player2][Collider::Type::player2] = false;
}

// Destructor
ModuleCollisions::~ModuleCollisions()
{

}

update_status ModuleCollisions::PreUpdate()
{
	// Remove all colliders scheduled for deletion
	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if (colliders[i] != nullptr && colliders[i]->pendingToDelete == true)
		{
			delete colliders[i];
			colliders[i] = nullptr;
		}
	}

	Collider* c1;
	Collider* c2;

	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		// skip empty colliders
		if (colliders[i] == nullptr)
			continue;

		c1 = colliders[i];

		// avoid checking collisions already checked
		for (uint k = i + 1; k < MAX_COLLIDERS; ++k)
		{
			// skip empty colliders
			if (colliders[k] == nullptr)
				continue;

			c2 = colliders[k];

			if (c1->Intersects(c2->rect))
			{
				if (matrix[c1->type][c2->type] == true && c1->listener != nullptr)
					c1->listener->OnCollision(c1, c2);

				if (matrix[c2->type][c1->type] && c2->listener != nullptr)
					c2->listener->OnCollision(c2, c1);
			}
		}
	}

	return update_status::UPDATE_CONTINUE;
}

update_status ModuleCollisions::Update()
{
	if (App->input->keys[SDL_SCANCODE_F5] == KEY_DOWN)
		debug = !debug;

	return update_status::UPDATE_CONTINUE;
}

update_status ModuleCollisions::PostUpdate()
{

	return update_status::UPDATE_CONTINUE;
}


// Called before quitting
bool ModuleCollisions::CleanUp()
{
	LOG("Freeing all colliders");

	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if (colliders[i] != nullptr)
		{
			delete colliders[i];
			colliders[i] = nullptr;
		}
	}

	return true;
}

Collider* ModuleCollisions::AddCollider(SDL_Rect rect, Collider::Type type, Module* listener)
{
	Collider* ret = nullptr;

	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if (colliders[i] == nullptr)
		{
			ret = colliders[i] = new Collider(rect, type, listener);
			break;
		}
	}

	return ret;
}
void ModuleCollisions::DebugDraw()
{
	Uint8 alpha = 80;
	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if (colliders[i] == nullptr)
			continue;

		switch (colliders[i]->type)
		{
		case Collider::Type::NONE:
			App->render->DrawQuad(colliders[i]->rect, 255, 255, 255, alpha);
			break;
		case Collider::Type::plataforma:
			App->render->DrawQuad(colliders[i]->rect, 0, 0, 255, alpha);
			break;
		case Collider::Type::PLAYER:
			App->render->DrawQuad(colliders[i]->rect, 0, 255, 0, alpha);
			break;
		case Collider::Type::escalera:
			App->render->DrawQuad(colliders[i]->rect, 255, 0, 0, alpha);
			break;
		case Collider::Type::Enemigo:
			App->render->DrawQuad(colliders[i]->rect, 255, 255, 0, alpha);
			break;
		case Collider::Type::martillo:
			App->render->DrawQuad(colliders[i]->rect, 0, 0, 255, alpha);
			break;
		case Collider::Type::objeto:
			App->render->DrawQuad(colliders[i]->rect, 0, 255, 255, alpha);
			break;
		case Collider::Type::placa:
			App->render->DrawQuad(colliders[i]->rect, 0, 255, 255, alpha);
			break;
		case Collider::Type::Victoria:
			App->render->DrawQuad(colliders[i]->rect, 0, 255, 255, alpha);
			break;
		case Collider::Type::top:
			App->render->DrawQuad(colliders[i]->rect, 255, 0, 255, alpha);
			break;
		case Collider::Type::salto:
			App->render->DrawQuad(colliders[i]->rect, 255, 0, 0, alpha);
			break;
		case Collider::Type::player2:
			App->render->DrawQuad(colliders[i]->rect, 255, 0, 0, 255);
			break;
		}
	}
}