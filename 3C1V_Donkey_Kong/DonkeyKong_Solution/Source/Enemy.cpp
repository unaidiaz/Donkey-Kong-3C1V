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
	if (collider != nullptr){
		collider->pendingToDelete = true;
	}
	if (collider1 != nullptr) {
		collider1->pendingToDelete = true;
	}
	
}

const Collider* Enemy::GetCollider() const
{
	return collider;
}

void Enemy::Update()
{
	if (currentAnim != nullptr)
		currentAnim->Update();

	if (typo == tipo::llama) {
		if (collider != nullptr && collider1 != nullptr) {
			collider->SetPos(position.x, position.y);
			collider1->SetPos(position.x + 12, position.y - 25);
		}
	}
	else if (typo == tipo::muelle) {
		if (collider != nullptr) {
			collider->SetPos(position.x, position.y);
		}
	}
	else {

		if (collider != nullptr && collider1 != nullptr) {
			collider->SetPos(position.x, position.y);
			collider1->SetPos(position.x + 8, position.y + 15);
		}

	}
}

void Enemy::Draw()
{
	if (currentAnim != nullptr) {
		if (enemigo != nullptr){
			App->render->Blit(enemigo, position.x, position.y, &(currentAnim->GetCurrentFrame()));
		}
		if (kong != nullptr) {
			App->render->Blit(kong, position.x, position.y, &(currentAnim->GetCurrentFrame()));
		}
		if (barriltext != nullptr) {
			App->render->Blit(barriltext, position.x, position.y + 10, &(currentAnim->GetCurrentFrame()));
		}
		if (muelles != nullptr) {
			App->render->Blit(muelles, position.x, position.y, &(currentAnim->GetCurrentFrame()));
		}
		

	}
		
}

void Enemy::OnCollision(Collider* collideri, Collider* collidere)
{	
	if (typo == tipo::llama) {
		if (collider == collideri) {
			if (collideri->type == collideri->Enemigo && collidere->type == collidere->escalera && estado != state::bajando) {

				if (frames1 > 1) {
					if (estado != state::subiendo) {
						estado = random(estado, collideri, typo);
					}
				}
				frames1 = 0;
				//enemies[i]->OnCollision(c2);


			}
			else if (collideri->type == collideri->Enemigo && collidere->type == collidere->plataforma && estado == state::libre) {

				estado = state::recto;

			}
			if (collideri->type == collideri->Enemigo && collidere->type == collidere->plataforma && estado == state::bajando) {

				if (top1 == false) {
					estado = state::recto;
					top1 = true;
				}
				prior1 = 1;

			}
			else if (collideri->type == collideri->Enemigo && collidere->type == collidere->escalera && estado == state::bajando && prior1 != 1) {

				if (top1 == true) {
					top1 = false;
				}

			}
		}

		if (collider1 == collideri) {

			if (collideri->type == collideri->top && collidere->type == collidere->escalera && estado != state::subiendo) {

				if (frames2 > 1) {
					if (estado != state::bajando) {
						estado = random(estado, collideri, typo);
					}

				}
				frames2 = 0;
				//enemies[i]->OnCollision(c2);

			}

			if (collideri->type == collideri->top && collidere->type == collidere->plataforma && estado == state::subiendo) {
				if (top2 == false) {
					top2 = true;
				}


			}
		}

	}
	else {
		if (collider == collideri) {
			if (collideri->type == collideri->Enemigo && collidere->type == collidere->plataforma && estado == state::libre && top1 == true) {
				estado = state::recto;
				contsub = 0;

			}

		}
		else if (collider1 == collideri) {

			if (collideri->type == collideri->top && collidere->type == collidere->escalera && (estado == state::recto || estado == state::libre)) {
				if (top1 == true) {
					if (frames1 > 1) {
						estado = random(estado, collideri, typo);
					}
				}
				if (estado == state::bajando && top1 == false) {
					top1 = true;
				}
				//frames1 = 0;
			}

		}

	}
}
void Enemy::destr()
{
	if (typo == tipo::llama || typo == tipo::barril) {
		if (collider != nullptr && collider1 != nullptr) {
			collider->pendingToDelete = true;
			collider1->pendingToDelete = true;

		}
		
	}
	if (typo == tipo::muelle) {
		if (collider != nullptr) {
			collider->pendingToDelete = true;
		}

	}
	pendientedeelim = true;

}
state Enemy::random(state Estado, Collider* colider, tipo tip) {
	if (typo == tipo::llama) {
		if (Estado == state::recto) {
			numerorand = 1 + rand() % 3;
			//numerorand = 1;
			if (numerorand == 1) {
				if (colider == collider) {
					Estado = state::bajando;

				}
				else {
					Estado = state::subiendo;
					top2 = false;
				}

			}
			else if (numerorand == 2) {
				if (colider == collider) {
					Estado = state::bajando;

				}
			}
		}
		else {

		}
		top1 = true;

		frames1 = 0;
		frames2 = 0;
		return Estado;
	}
	else {
		numerorand = 1 + rand() % 2;
		if (numerorand == 1) {
			Estado = state::bajando;
			//position.y = position.y + 1;
			top1 = false;
		}
		else {

		}
		frames1 = 0;
		return Estado;
	}
}