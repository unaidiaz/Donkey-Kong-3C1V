#include "Enemy.h"
#include"ModuleTextures.h"
#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleRender.h"

Enemy::Enemy(int x, int y) : position(x, y)
{
	prior1 = 0;
	contsub = 0;
	top1 = true;
	top2 = true;
	estado = state::recto;
	spawnPos = position;
	srand(time(NULL));
	frames1 = 2;
	frames2 = 2;
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

	if (collider != nullptr&& collider1!=nullptr) {
		collider->SetPos(position.x, position.y);
		collider1->SetPos(position.x+12, position.y-25);
	}
}

void Enemy::Draw()
{
	if (currentAnim != nullptr)
		App->render->Blit(enemigo, position.x, position.y, &(currentAnim->GetCurrentFrame()));
		App->render->Blit(kong, position.x, position.y, &(currentAnim->GetCurrentFrame()));
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
state Enemy::random(state Estado,Collider* colider) {
	if (Estado == state::recto) {
		numerorand = 1 + rand() % 3;
		//numerorand = 1;
		if (numerorand == 1) {
			if (colider==collider) {
			Estado = state::bajando;
			
			}
			else {
				Estado = state::subiendo;
				top2 = false;
			}

		}
		else if(numerorand == 2){
			if (colider == collider) {
				Estado = state::bajando;

			}
		}
		else {

		}
		
		
	}
	top1 = true;
	
	frames1 = 0;
	frames2 = 0;
	return Estado;
}