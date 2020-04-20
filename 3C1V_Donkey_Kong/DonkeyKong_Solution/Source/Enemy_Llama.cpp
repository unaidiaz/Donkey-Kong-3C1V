#include "Enemy_Llama.h"

#include "Application.h"
#include "ModuleCollisions.h"

Enemy_Llama::Enemy_Llama(int x, int y) : Enemy(x, y)
{
	llama.PushBack({ 0,0,200,200 });
	llama.PushBack({ 38, 6, 24, 24 });
	llama.loop = true;

	currentAnim = &llama;

	collider = App->collisions->AddCollider({ 0, 0, 24, 24 }, Collider::Type::Enemigo, (Module*)App->enemies);
}

void Enemy_Llama::Update()
{
	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}