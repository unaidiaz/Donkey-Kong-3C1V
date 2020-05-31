#include "ModuleEnemies.h"

#include "Application.h"
#include"ModulePlayer.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "SceneLevel4.h"
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
			}
			break;
		}
	}
}

void ModuleEnemies::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
			if (enemies[i] != nullptr && enemies[i]->GetCollider() == c1)
			{
				if (c1->type==c1->Enemigo&&c2->type == c2->martillo) {
					enemies[i]->OnCollision(c2);
					App->audio->PlayFx(App->enemies->enemyDestroyedFx);//Notify the enemy of a collision
					enemies[i]->destr();
					break;
				}else if (c1->type == c1->Enemigo && c2->type == c2->escalera&& enemies[i]->estado != state::bajando) {
			
					if (enemies[i]->frames1 >1) {
						if (enemies[i]->estado != state::subiendo) {
							enemies[i]->estado = enemies[i]->random(enemies[i]->estado, c1);
						}
					}
					enemies[i]->frames1 = 0;
				//enemies[i]->OnCollision(c2);
					break;
			
				}else if (c1->type == c1->Enemigo && c2->type == c2->plataforma && enemies[i]->estado == state::libre) {
			
						enemies[i]->estado = state::recto;
						break;
				}
				if (c1->type == c1->Enemigo && c2->type == c2->plataforma && enemies[i]->estado == state::bajando) {
			
					if (enemies[i]->top1 == false) {
						enemies[i]->estado = state::recto;
						enemies[i]->top1 = true;
					}
					enemies[i]->prior1 = 1;
					break;
				}else if (c1->type == c1->Enemigo && c2->type == c2->escalera && enemies[i]->estado == state::bajando&& enemies[i]->prior1 != 1) {
					if (enemies[i]->top1 == true) {
						enemies[i]->top1 = false;
					}
					break;
				}
			
			}
		
	
			if (enemies[i] != nullptr && enemies[i]->collider1 == c1) {
			
				if (c1->type == c1->top && c2->type == c2->escalera && enemies[i]->estado != state::subiendo) {

					if (enemies[i]->frames2 > 1) {
						if (enemies[i]->estado != state::bajando) {
							enemies[i]->estado = enemies[i]->random(enemies[i]->estado,c1);
						}
						
					}
					enemies[i]->frames2 = 0;
					//enemies[i]->OnCollision(c2);
					break;
				}
				
				if (c1->type == c1->top && c2->type == c2->plataforma && enemies[i]->estado == state::subiendo ) {
					if (enemies[i]->top2 == false) {
						enemies[i]->top2 = true;
					}
					
					break;
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