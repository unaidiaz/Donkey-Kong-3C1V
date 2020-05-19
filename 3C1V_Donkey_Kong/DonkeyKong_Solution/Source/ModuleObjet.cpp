

#include "Application.h"
#include"ModulePlayer.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "SceneLevel4.h"
#include"ModuleObjet.h"
#include"placa.h"
#include "paraguas.h"
#include "tanque.h"
#include "bolso.h"
#include "SDL/include/SDL.h"
#include "SDL_image/include/SDL_image.h"

#pragma comment( lib, "SDL_image/libx86/SDL2_image.lib" )

#define SPAWN_MARGIN 50


ModuleObjet::ModuleObjet(bool startEnabled) : Module(startEnabled)
{
	for (uint i = 0; i < MAX_OBJET; ++i)
		objetos[i] = nullptr;
}

ModuleObjet::~ModuleObjet()
{

}

bool ModuleObjet::Start()
{

	objetostex = App->textures->Load("Assets/objetosestaticos.png");
	//enemyDestroyedFx = App->audio->LoadFx("Assets/8. SFX (Kill).wav");

	return true;
}

update_status ModuleObjet::PreUpdate()
{
	// Remove all enemies scheduled for deletion
	for (int i = 0; i < MAX_OBJET; i++)
	{
		if (objetos[i] != nullptr && objetos[i]->pendingToDelete == true)
		{
			delete objetos[i];
			objetos[i] = nullptr;
		}
	}

	return update_status::UPDATE_CONTINUE;
}

update_status ModuleObjet::Update()
{
	HandleObjetSpawn();

	for (uint i = 0; i < MAX_OBJET; ++i)
	{
		if (objetos[i] != nullptr)
			objetos[i]->Update();
	}

	HandleObjetDespawn();

	return update_status::UPDATE_CONTINUE;
}

update_status ModuleObjet::PostUpdate()
{
	for (int i = 0; i < MAX_OBJET; i++)
	{
		if (objetos[i] != nullptr) {
			objetos[i]->Draw();

		}
			
	}

	return update_status::UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleObjet::CleanUp()
{
	LOG("Freeing all objects");

	for (uint i = 0; i < MAX_OBJET; ++i)
	{
		if (objetos[i] != nullptr)
		{
			delete objetos[i];
			objetos[i] = nullptr;
		}
	}

	return true;
}

bool ModuleObjet::AddObjet(Objet_Type type, int x, int y)
{
	bool ret = false;

	for (uint i = 0; i < MAX_OBJET; ++i)
	{
		if (spawnQueue[i].type == Objet_Type::NO_TYPE)
		{
			spawnQueue[i].type = type;
			spawnQueue[i].x = x;
			spawnQueue[i].y = y;
			
			ret = true;
			break;
		}
	}

	return ret;
}

void ModuleObjet::HandleObjetSpawn()
{
	// Iterate all the enemies queue
	for (int i = 0; i < MAX_OBJET; i++)
	{
		if (spawnQueue[i].type != Objet_Type::NO_TYPE)
		{
			SpawnObjet(spawnQueue[i]);
			spawnQueue[i].type = Objet_Type::NO_TYPE; // Removing the newly spawned enemy from the queue
		}
	}
}

void ModuleObjet::HandleObjetDespawn()
{
	// Iterate existing enemies
	for (int i = 0; i < MAX_OBJET; i++)
	{
		if (objetos[i] != nullptr && objetos[i]->pendingToDelete == true)
		{
			delete objetos[i];
			objetos[i] = nullptr;
		}
	}
	/*if (App->enemies->compene() == true) {
		App->player->_win = true;
		App->player->canLateralMov = false;
	}*/
}

void ModuleObjet::SpawnObjet(const objet_Spawnpoint& info)
{
	// Find an empty slot in the enemies array
	for (uint i = 0; i < MAX_OBJET; ++i)
	{
		if (objetos[i] == nullptr)
		{

			switch (info.type)
			{
			case Objet_Type::placa:
				objetos[i] = new placa(info.x,info.y);
				objetos[i]->placatext = objetostex;
				break;
			case Objet_Type::paraguas:
				objetos[i] = new paraguas(info.x, info.y);
				objetos[i]->paraguastext = objetostex;
				break;
			case Objet_Type::bolso:
				objetos[i] = new bolso(info.x, info.y);
				objetos[i]->bolsotext = objetostex;
				break;
			case Objet_Type::tanque:
				objetos[i] = new tanque(info.x, info.y);
				objetos[i]->tanquetext = objetostex;
				break;
			}
			break;
		}
		
	}
}

void ModuleObjet::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_OBJET; ++i)
	{
		if (objetos[i] != nullptr && objetos[i]->GetCollider() == c1)
		{
			if (c2->type == c2->PLAYER)
			{
				objetos[i]->OnCollision(c2);
			}
			/*else if (c2->type == c2->placa)
			{
				objetos[i]->OnCollision(c2);
			}*/
		}
	}
}