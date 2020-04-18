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
	/*
	mart_iz.PushBack({80,73,16,29});
	mart_iz.PushBack({35,79,26,17});
	mart_iz.PushBack({1,72,14,30 });
	mart_iz.loop = true;
	mart_iz.speed = 0.2f;
	
	mart_iz.PushBack({ 80,73,16,29 });
	mart_iz.PushBack({ 35,79,26,17 });
	mart_iz.PushBack({ 1,72,14,30 });
	mart_iz.loop = true;
	mart_iz.speed = 0.2f;
	*/
    izquierda.PushBack({ 310, 84, 16, 17 });
	izquierda.PushBack({ 334, 84, 16, 17 });
	izquierda.loop = true;
	izquierda.speed = 0.2f;
	espalda.PushBack({ 279,39,16,17 });


	topescalera.PushBack({ 200,39,15,15 });
	topescalera.PushBack({ 239,41,15,13 });
	topescalera.loop = true;
	topescalera.speed = 0.1f;

	//paradoder_mart.PushBack({ 154,79,25,17 });
	//paradoizq_mart.PushBack({ 116,79,24,17 });
	paradoder.PushBack({ 161,0,16,17 });
	paradoizq.PushBack({ 121,0,16,17 });
	// move upwards
	derecha.PushBack({ 354, 84, 16, 17 });
	derecha.PushBack({ 378, 84, 16, 17 });
	derecha.loop = true;
	derecha.speed = 0.2f;

	arriba.PushBack({ 121,39,14,17 });
	arriba.PushBack({ 160,39,14,17 });
	arriba.loop = true;
	arriba.speed = 0.1f;

	abajo.PushBack({ 121,39,14,17 });
	abajo.PushBack({ 160,39,14,17 });
	abajo.loop = true;
	abajo.speed = 0.1f;

	saltarder.PushBack({ 199,0,16,16 });
	//saltarder.PushBack({ 239,0,15,17 });
	/*saltarder.loop = true;
	saltarder.speed = 0.1f;*/

	saltariz.PushBack({ 80,0,16,16 });
	//saltariz.PushBack({ 39,0,15,17 });
	/*saltariz.loop = true;
	saltariz.speed = 0.1f;*/

	currentAnimation = &derecha;
	// Move down
	/*downAnim.PushBack({ 33, 1, 32, 14 });
	downAnim.PushBack({ 0, 1, 32, 14 });
	downAnim.loop = false;
	downAnim.speed = 0.1f;*/
	Posicion.x = 65;
	Posicion.y = 680;

}
bool ModulePlayer::Init() {
	collider = App->collisions->AddCollider({ Posicion.x,Posicion.y,16,17 }, Collider::Type::PLAYER, this);
	//marioo = App->textures->Load("Assets/perso.png");
	paso = App->audio->LoadFx("Assets/2. SFX (Walking).wav");
	salto = App->audio->LoadFx("Assets/3. SFX (Jump).wav");
	lastanimation = &topescalera;
	return true;
}
update_status ModulePlayer::Update() 
{
	if (jumpact == false) 
	{
		Posicion.y += 2;
	}
	if (plataforma == true && escalera == true) 
	{
		Posicion.y += 2;
	}
	//plataforma == false &&
	if (App->input->keys[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT)
	{
		if (escalera == true) {
			if (plataforma == false) {
				Posicion.y -= 1;
				//arriba.Reset();
				if (lastanimation == &topescalera) {
					currentAnimation = &espalda;
					lastanimation = &espalda;
				}
				else {
					currentAnimation = &arriba;
					currentAnimation->Update();

				}

				escalera = false;

			}
			else {
				Posicion.y -= 3;
				currentAnimation = &topescalera;
				lastanimation = &topescalera;
				currentAnimation->Update();
				escalera = false;
			}
			escalera = false;
		}

	}


	if (App->input->keys[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
	{
		if (escalera == true) 
		{
			if (plataforma == true) 
			{
				Posicion.y += 3;
				//abajo.Reset();
				if (lastanimation == &topescalera) 
				{
					currentAnimation = &espalda;
					currentAnimation->Update();
					lastanimation = &espalda;
				}
				else 
				{
					currentAnimation = &topescalera;
					currentAnimation->Update();

				}

				escalera = false;
			}
			else 
			{
				Posicion.y += 1;
				currentAnimation = &abajo;
				currentAnimation->Update();

			}
		}
	}
	if (App->input->keys[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
	{

		tecla = 0;
		Posicion.x += 2;
		contador++;
		//derecha.Reset();
		currentAnimation = &derecha;
		currentAnimation->Update();
		if (escalera == true) 
		{
			escalera = false;
		}
		if (plataforma == true) 
		{
			Posicion.y -= 1;
		}


	}
	if (App->input->keys[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
	{
		tecla = 1;
		Posicion.x -= 2;
		contador++;
		//izquierda.Reset();
		currentAnimation = &izquierda;
		currentAnimation->Update();
		if (escalera == true) {
			escalera = false;
		}
		if (plataforma == true) {
			Posicion.y -= 1;
		}
	}
	if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
	{
		if (escalera == true && plataforma == true || plataforma == true) 
		{
			plataforma = false;
			if (jumpact == false) 
			{
				if (canAudioJump)
				{
					App->audio->PlayFx(salto);
					canAudioJump = false;
				}				
				jump();
			}
		}
	}
	if (jumpact == true) 
	{
		jump();
	}
	if (contador == 30 || contador == 60 || contador == 15 || contador == 45) {
		App->audio->PlayFx(paso);
	}
	if (contador > 60) {
		contador = 0;
	}


	//LIMITES LATERALES
	if (Posicion.x < 0)
	{
		Posicion.x = 0;
	}
	if (Posicion.x > 624)
	{
		Posicion.x = 624;
	}
	//LIMITES VERTICALES
	if (Posicion.y > 700)
	{
		Posicion.y = 700;
	}
	plataforma = false;
	collider->SetPos(Posicion.x, Posicion.y);
	return update_status::UPDATE_CONTINUE;
}
update_status ModulePlayer::PostUpdate() {
	//App->render->Blit(marioo, 0, 0, nullptr);


	return update_status::UPDATE_CONTINUE;
}

void ModulePlayer::jump() 
{	
	jumpact = true;
	
	if (cont < 20) 
	{
		Posicion.y -= 2;
	}
	else 
	{
		Posicion.y += 2;
		if (plataforma == true) 
		{
			cont = -1;
			jumpact = false;
			canAudioJump = true;
			//currentAnimation = &paradoder;
		}

	}

	cont++;
	if (currentAnimation != &saltarder || currentAnimation != &saltariz)
	{
		if (tecla == 0) {
			if (currentAnimation != &saltarder) {
				//saltarder.Reset();
				currentAnimation = &saltarder;
			}
		}
		else {
			if (currentAnimation != &saltarder) {
				//saltariz.Reset();
				currentAnimation = &saltariz;


			}
		}
	}
	currentAnimation->Update();

}
void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{
	if (c1 == collider && c2->type == Collider::escalera) {
		Posicion.y -= 2;
		escalera = true;
	}
	else {

		if (c1 == collider && c2->type == Collider::plataforma) {

			Posicion.y -= 2;
			plataforma = true;

		}
		else {
			plataforma = false;
		}
	}
}