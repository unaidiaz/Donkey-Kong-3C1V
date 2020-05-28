#include "Enemy.h"
#include"ModuleTextures.h"
#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleRender.h"

Enemy::Enemy(int x, int y) : position(x, y)
{
	estado = state::recto;
	spawnPos = position;
	srand(time(NULL));
	frames = 2;
}

Enemy::~Enemy()
{
	if (collider != nullptr)
		collider->pendingToDelete = true;
}

const Collider* Enemy::GetCollider() const
{
	return collider;
}

void Enemy::Update()
{
	if (currentAnim != nullptr)
		currentAnim->Update();

	if (collider != nullptr)
		collider->SetPos(position.x, position.y);
}

void Enemy::Draw()
{
	if (currentAnim != nullptr)
		App->render->Blit(enemigo, position.x, position.y, &(currentAnim->GetCurrentFrame()));
}

void Enemy::OnCollision(Collider* collider)
{	
	//App->audio->PlayFx(destroyedFx);
}
void Enemy::destr()
{
	if (collider != nullptr) {
		pendientedeelim = true;
	}

}
state Enemy::random(state Estado) {
	if (Estado == state::recto) {
		numerorand = 1 + rand() % 2;
		if (numerorand == 1) {
			Estado = state::bajando;
			
		}
		else if (numerorand == 2) {
			
		}
	}
	frames = 0;
	return Estado;
}