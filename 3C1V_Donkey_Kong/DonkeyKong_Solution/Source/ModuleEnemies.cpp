#include "ModuleEnemies.h"

#include "Application.h"
#include"ModulePlayer.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "SceneLevel4.h"
#include"Enemy_Barril.h"
#include "Enemy.h"
#include "Enemy_Llama.h"
#include "Enemy_Kong.h"
#include "SDL/include/SDL.h"
#include "SDL_image/include/SDL_image.h"
#include<time.h>
#pragma comment( lib, "SDL_image/libx86/SDL2_image.lib" )

#define SPAWN_MARGIN 50


ModuleEnemies::ModuleEnemies(bool startEnabled) : Module(startEnabled)
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
		enemies[i] = nullptr;
}

ModuleEnemies::~ModuleEnemies()
{

}

bool ModuleEnemies::Start()
{
	
	enemigos = App->textures->Load("Assets/objetosanimados.png");
	kongs = App->textures->Load("Assets/sprites.png");
	enemyDestroyedFx = App->audio->LoadFx("Assets/8. SFX (Kill).wav");

	return true;
}

update_status ModuleEnemies::PreUpdate()
{
	// Remove all enemies scheduled for deletion
	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		if (enemies[i] != nullptr && enemies[i]->pendientedeelim == true)
		{
			delete enemies[i];
			enemies[i] = nullptr;
		}
	}

	return update_status::UPDATE_CONTINUE;
}

update_status ModuleEnemies::Update()
{
	HandleEnemiesSpawn();

	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
			enemies[i]->Update();
	}

	HandleEnemiesDespawn();

	return update_status::UPDATE_CONTINUE;
}

update_status ModuleEnemies::PostUpdate()
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
			enemies[i]->Draw();
	}

	return update_status::UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleEnemies::CleanUp()
{
	LOG("Freeing all enemies");

	for (int i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
		{
			
			delete enemies[i];
			enemies[i] = nullptr;
		}
	}

	return true;
}

bool ModuleEnemies::AddEnemy(Enemy_Type type, int x, int y,int direccion)
{
	bool ret = false;

	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (spawnQueue[i].type == Enemy_Type::NO_TYPE)
		{
			spawnQueue[i].type = type;
			spawnQueue[i].x = x;
			spawnQueue[i].y = y;
			spawnQueue[i].direccion = direccion;
			ret = true;
			break;
		}
	}

	return ret;
}

void ModuleEnemies::HandleEnemiesSpawn()
{
	// Iterate all the enemies queue
	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		if (spawnQueue[i].type != Enemy_Type::NO_TYPE)
		{
			SpawnEnemy(spawnQueue[i]);
			spawnQueue[i].type = Enemy_Type::NO_TYPE; // Removing the newly spawned enemy from the queue
		}
	}
}

void ModuleEnemies::HandleEnemiesDespawn()
{
	// Iterate existing enemies
	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		if (enemies[i] != nullptr&&enemies[i]->pendientedeelim==true)
		{
			delete enemies[i];
			enemies[i] = nullptr;
		}
	}
}

void ModuleEnemies::SpawnEnemy(const EnemySpawnpoint& info)
{
	// Find an empty slot in the enemies array
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] == nullptr)
		{

			switch (info.type)
			{
			case Enemy_Type::LLAMA:
				enemies[i] = new Enemy_Llama(info.x, info.y, info.direccion);
				enemies[i]->enemigo = enemigos;
				enemies[i]->destroyedFx = enemyDestroyedFx;
				break;

			case Enemy_Type::KONG:
				enemies[i] = new Enemy_Kong(info.x, info.y, info.direccion);
				enemies[i]->kong = kongs;
				enemies[i]->destroyedFx = enemyDestroyedFx;
				break;
			case Enemy_Type::barril:
				enemies[i] = new Enemybarril(info.x, info.y, info.direccion);
				enemies[i]->barriltext = enemigos;
				enemies[i]->destroyedFx = enemyDestroyedFx;
				break;
			
			}
			break;
		}
	}
}

void ModuleEnemies::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
		{
			if (c1->type == c1->Enemigo && c2->type == c2->martillo) {
				//
				App->audio->PlayFx(App->enemies->enemyDestroyedFx);//Notify the enemy of a collision
				enemies[i]->destr();
				break;
			}
			else {
				enemies[i]->OnCollision(c1, c2);

			}

		}




	}
}
bool ModuleEnemies::compene()
{
	for (int i = 0; i < MAX_ENEMIES; i++) 
	{
		if (enemies[i] != nullptr) 
		{
			return false;
		}
	}
	return true;
}