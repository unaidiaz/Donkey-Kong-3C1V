#include "ModuleCollisions.h"

#include "Application.h"

#include "ModuleRender.h"
#include "ModuleInput.h"
#include "SDL/include/SDL_Scancode.h"

ModuleCollisions::ModuleCollisions()
{
	for (uint i = 0; i < MAX_COLLIDERS; ++i)
		colliders[i] = nullptr;

	matrix[Collider::Type::plataforma][Collider::Type::plataforma] = false;
	matrix[Collider::Type::plataforma][Collider::Type::PLAYER] = true;
	matrix[Collider::Type::plataforma][Collider::Type::Enemigo] = true;
	matrix[Collider::Type::plataforma][Collider::Type::escalera] = false;

	matrix[Collider::Type::PLAYER][Collider::Type::plataforma] = true;
	matrix[Collider::Type::PLAYER][Collider::Type::PLAYER] = false;
	matrix[Collider::Type::PLAYER][Collider::Type::Enemigo] = true;
	matrix[Collider::Type::PLAYER][Collider::Type::escalera] = true;

	matrix[Collider::Type::Enemigo][Collider::Type::plataforma] = true;
	matrix[Collider::Type::Enemigo][Collider::Type::PLAYER] = true;
	matrix[Collider::Type::Enemigo][Collider::Type::Enemigo] = false;
	matrix[Collider::Type::Enemigo][Collider::Type::escalera] = true;

	matrix[Collider::Type::escalera][Collider::Type::plataforma] = false;
	matrix[Collider::Type::escalera][Collider::Type::PLAYER] = true;
	matrix[Collider::Type::escalera][Collider::Type::Enemigo] = true;
	matrix[Collider::Type::escalera][Collider::Type::escalera] = false;
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
	if (App->input->keys[SDL_SCANCODE_F1] == KEY_DOWN)
		debug = !debug;

	return update_status::UPDATE_CONTINUE;
}

update_status ModuleCollisions::PostUpdate()
{
	/*if (debug)
		DebugDraw();*/

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