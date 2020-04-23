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
	if (_tanque != nullptr)
		_tanque->pendingToDelete = true;
	if (_bolso != nullptr)
		_bolso->pendingToDelete = true;
	if (_paraguas != nullptr)
		_paraguas->pendingToDelete = true;
}

const Collider* Objet::GetCollider() const
{
	if (Collider::paraguas)
	{
		return _paraguas;
	}
	else if (Collider::bolso)
	{
		return _bolso;
	}
	else if (Collider::tanque)
	{
		return _tanque;
	}
	else if (Collider::placa)
	{
		return colob;
	}
	
}

void Objet::Update()
{
	if (currentAnim != nullptr)
		currentAnim->Update();

	if (colob != nullptr)
		colob->SetPos(position.x, position.y);
	if (_paraguas != nullptr)
		_paraguas->SetPos(position.x, position.y);
	if (_bolso != nullptr)
		_bolso->SetPos(position.x, position.y);
	if (_tanque != nullptr)
		_tanque->SetPos(position.x, position.y);
}

void Objet::Draw()
{
	if (currentAnim != nullptr)
	{
		App->render->Blit(placatext, position.x, position.y + 110, &(currentAnim->GetCurrentFrame()));
		App->render->Blit(tanquetext, position.x+5, position.y+30, &(currentAnim->GetCurrentFrame()));
		App->render->Blit(bolsotext, position.x+10, position.y+30, &(currentAnim->GetCurrentFrame()));
		App->render->Blit(paraguastext, position.x+5, position.y+30, &(currentAnim->GetCurrentFrame()));
	}
		
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
	if (_paraguas != nullptr) {
		pendingToDelete = true;
	}
	if (_tanque != nullptr) {
		pendingToDelete = true;
	}
	if (_bolso != nullptr) {
		pendingToDelete = true;
	}

}