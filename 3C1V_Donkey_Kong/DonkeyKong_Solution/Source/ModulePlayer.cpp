#include"ModulePlayer.h"
#include"Application.h"
#include"ModuleRender.h"
#include"ModuleTextures.h"
#include"Module.h"
#include"Globals.h"
#include"ModuleCollisions.h"
#include"ModuleInput.h"
#include"Animation.h"
#include "ModuleAudio.h"
#include "SDL/include/SDL_scancode.h"

ModulePlayer::ModulePlayer() {
	izquierda.PushBack({ 310, 84, 16, 17 });
	izquierda.PushBack({ 334, 84, 16, 17 });
	izquierda.loop = true;
	izquierda.speed = 0.1f;
	
	paradoder.PushBack({ 161,0,16,17 });
	paradoizq.PushBack({ 121,0,16,17 });
	// move upwards
	derecha.PushBack({ 354, 84, 16, 17 });
	derecha.PushBack({ 378, 84, 16, 17 });
	derecha.loop = true;
	derecha.speed = 0.1f;

	arriba.PushBack({121,39,14,17});
	arriba.PushBack({160,39,14,17});
	arriba.loop = true;
	arriba.speed = 0.1f;

	abajo.PushBack({ 121,39,14,17 });
	abajo.PushBack({ 160,39,14,17 });
	abajo.loop = true;
	abajo.speed = 0.1f;

	saltarder.PushBack({ 199,0,16,16 });
	saltarder.PushBack({ 239,0,15,17 });
	saltarder.loop = true;
	saltarder.speed = 0.1f;

	saltariz.PushBack({ 80,0,16,16 });
	saltariz.PushBack({ 39,0,15,17 });
	saltariz.loop = true;
	saltariz.speed = 0.1f;

	currentAnimation = &paradoder;
	// Move down
	/*downAnim.PushBack({ 33, 1, 32, 14 });
	downAnim.PushBack({ 0, 1, 32, 14 });
	downAnim.loop = false;
	downAnim.speed = 0.1f;*/
	Posicion.x = 0;
	Posicion.y = 682;
	
}
bool ModulePlayer::Init() {
	collider = App->collisions->AddCollider({ Posicion.x,Posicion.y,16,17 }, Collider::Type::PLAYER, this);
	//marioo = App->textures->Load("Assets/perso.png");
	
	return true;
}
update_status ModulePlayer::Update() {
	Posicion.y += 2;
	if (App->input->keys[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
	{
		tecla = 1;
		Posicion.x -= Posicion.velo;
		if (currentAnimation != &izquierda)
		{
			izquierda.Reset();
			currentAnimation = &izquierda;
		}
	}

	if (App->input->keys[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
	{
		tecla = 0;
		Posicion.x += Posicion.velo;
		if (currentAnimation != &derecha)
		{
			derecha.Reset();
			currentAnimation = &derecha;
		}
	}
	if (escalera == true) {
		if (App->input->keys[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT)
		{
			Posicion.y -= 3;
			if (currentAnimation != &arriba)
			{
				arriba.Reset();
				currentAnimation = &arriba;
			}
		}
		escalera = false;
	}
	

	if (App->input->keys[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
	{
		Posicion.y += Posicion.velo;
		if (currentAnimation != &abajo)
		{
			abajo.Reset();
			currentAnimation = &abajo;
		}
	}

	if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
	{
		if (jumpact == false) {
			jump();
		}
	}

	/*if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
	{
		App->particles->AddParticle(App->particles->laser, position.x + 20, position.y, Collider::Type::PLAYER_SHOT);
		App->audio->PlayFx(laserFx);
	}*/

	// If no up/down movement detected, set the current animation back to idle



	if (App->input->keys[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE && App->input->keys[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE&&tecla==0 && App->input->keys[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE && App->input->keys[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE && App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_IDLE){
		currentAnimation = &paradoder;
	
	}
	else if (App->input->keys[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE && App->input->keys[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE && tecla == 1 && App->input->keys[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE && App->input->keys[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE && App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_IDLE) {
		currentAnimation = &paradoizq;
	}
	if (jumpact == true) {
		jump();
	}
	currentAnimation->Update();
	collider->SetPos(Posicion.x, Posicion.y);

	//collider->SetPos(position.x, position.y);

	

	/*if (destroyed)
	{
		destroyedCountdown--;
		if (destroyedCountdown <= 0)
			return update_status::UPDATE_STOP;
	}*/

	return update_status::UPDATE_CONTINUE;
}
update_status ModulePlayer::PostUpdate() {
	//App->render->Blit(marioo, 0, 0, nullptr);
	
	
	

	return update_status::UPDATE_CONTINUE;
}

void ModulePlayer::jump() {
	jumpact = true;
	if (cont < 22) {
		Posicion.y -= 4;
	}
	else if(cont>=(22*2)) {
		jumpact = false;
		cont = -1;
	}

	if (currentAnimation != &saltarder || currentAnimation != &saltariz)
	{
		if (tecla == 0) {
			saltarder.Reset();
			currentAnimation = &saltarder;
		}
		else {
			saltariz.Reset();
			currentAnimation = &saltariz;
		}

	}
	cont++;

}
void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{
	if (c1 == collider&&c2->type==Collider::plataforma) {
		Posicion.y -= 2;
	}
	if (c1 == collider && c2->type == Collider::escalera) {
		escalera = true;
	}
	
}