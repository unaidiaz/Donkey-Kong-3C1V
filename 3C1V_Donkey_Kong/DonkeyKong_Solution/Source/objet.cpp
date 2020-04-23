#include "objet.h"
#include"ModuleTextures.h"
#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleRender.h"

Objet::Objet(int x, int y) : position(x, y)
{
	spawnPos = position;
}

Objet::~Objet()
{
	if (colob != nullptr)
		colob->pendingToDelete = true;
}

const Collider* Objet::GetCollider() const
{
	return colob;
}

void Objet::Update()
{
	if (currentAnim != nullptr)
		currentAnim->Update();

	if (colob != nullptr)
		colob->SetPos(position.x, position.y);
}

void Objet::Draw()
{
	if (currentAnim != nullptr)
		App->render->Blit(placatext, position.x, position.y+110, &(currentAnim->GetCurrentFrame()));
}

void Objet::OnCollision(Collider* collider)
{
	//App->audio->PlayFx(destroyedFx);
}
void Objet::destr()
{
	if (colob != nullptr) {
		pendingToDelete = true;
	}

}