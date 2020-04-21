#include "Enemy_Llama.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModulePlayer.h"

Enemy_Llama::Enemy_Llama(int x, int y) : Enemy(x, y)
{
	llama.PushBack({ 0,63,15,17 });
	llama.PushBack({ 17, 64, 14, 16 });
	llama.PushBack({ 34, 66, 16, 13 });
	llama.loop = true;
	llama.speed = 0.1f;

	currentAnim = &llama;

	collider = App->collisions->AddCollider({ 0, 0, 24, 24 }, Collider::Type::Enemigo, (Module*)App->enemies);
}

void Enemy_Llama::Update()
{
	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();	
}

