#include"Application.h"
#include"ModulePlayer.h"
#include"ModuleRender.h"
#include"ModuleTextures.h"
#include"Module.h"
#include"Globals.h"
#include"ModuleCollisions.h"
#include"ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include"Animation.h"
#include "ModuleAudio.h"
#include "SDL/include/SDL_scancode.h"

ModulePlayer::ModulePlayer(bool startEnabled) : Module(startEnabled)
{
	dead_mario_l.PushBack({ 79,119,17,17 });
	dead_mario_l.PushBack({ 119,119,17,17 });
	dead_mario_l.PushBack({ -1,119,17,17 });
	dead_mario_l.PushBack({ 39,119,17,17 });
	dead_mario_l.PushBack({ 79,119,17,17 });
	dead_mario_l.PushBack({ 119,119,17,17 });
	dead_mario_l.PushBack({ -1,119,17,17 });
	dead_mario_l.PushBack({ 39,119,17,17 });
	dead_mario_l.PushBack({ 79,119,17,17 });
	dead_mario_l.PushBack({ 119,119,17,17 });
	dead_mario_l.PushBack({ -1,119,17,17 });
	dead_mario_l.PushBack({ 39,119,17,17 });
	dead_mario_l.PushBack({ -1,-1,17,17 });
	dead_mario_l.loop = false;
	dead_mario_l.speed = 0.1f;

	dead_mario_r.PushBack({ 79,119,17,17 });
	dead_mario_r.PushBack({ 119,119,17,17 });
	dead_mario_r.PushBack({ -1,119,17,17 });
	dead_mario_r.PushBack({ 39,119,17,17 });
	dead_mario_r.PushBack({ 79,119,17,17 });
	dead_mario_r.PushBack({ 119,119,17,17 });
	dead_mario_r.PushBack({ -1,119,17,17 });
	dead_mario_r.PushBack({ 39,119,17,17 });
	dead_mario_r.PushBack({ 79,119,17,17 });
	dead_mario_r.PushBack({ 119,119,17,17 });
	dead_mario_r.PushBack({ -1,119,17,17 });
	dead_mario_r.PushBack({ 39,119,17,17 });
	dead_mario_r.PushBack({ 279,-1,17,17 });
	dead_mario_r.loop = false;
	dead_mario_r.speed = 0.1f;
	
	mart_iz.PushBack({80,73,16,29});
	mart_iz.PushBack({35,79,26,17});
	mart_iz.loop = true;
	mart_iz.speed = 0.1f;
	
	mart_der.PushBack({ 199,73,16,29 });
	mart_der.PushBack({ 234,79,26,16 });
	mart_der.loop = true;
	mart_der.speed = 0.1f;
	
    /*izquierda.PushBack({ 310, 84, 16, 17 });
	izquierda.PushBack({ 334, 84, 16, 17 });
	izquierda.loop = true;
	izquierda.speed = 0.2f;
	espalda.PushBack({ 279,39,16,17 });*/


	topescalera.PushBack({ 200,39,15,15 });
	topescalera.PushBack({ 239,41,15,13 });
	topescalera.loop = true;
	topescalera.speed = 0.1f;

	//paradoder_mart.PushBack({ 154,79,25,17 });
	//paradoizq_mart.PushBack({ 116,79,24,17 });
	paradoder.PushBack({ 161,0,16,17 });
	paradoizq.PushBack({ 121,0,16,17 });
	// move upwards
	/*derecha.PushBack({ 354, 84, 16, 17 });
	derecha.PushBack({ 378, 84, 16, 17 });
	derecha.loop = true;
	derecha.speed = 0.2f;*/

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

	currentAnimation = &mart_der;
	// Move down
	/*downAnim.PushBack({ 33, 1, 32, 14 });
	downAnim.PushBack({ 0, 1, 32, 14 });
	downAnim.loop = false;
	downAnim.speed = 0.1f;*/
	Posicion.x = 65;
	Posicion.y = 680;
}
bool ModulePlayer::Start() {
	cont_muerte = 0;
	win = App->textures->Load("Assets/YOU_WIN.png");
	lose = App->textures->Load("Assets/GAME_OVER.png");
	collider = App->collisions->AddCollider({ Posicion.x, Posicion.y, 16, 40 }, Collider::Type::PLAYER, this);
	mart = App->collisions->AddCollider({ Posicion.x, Posicion.y, 10, 10 }, Collider::Type::martillo, this);
	mart2 = App->collisions->AddCollider({ Posicion.x, Posicion.y, 10, 10 }, Collider::Type::martillo, this);
	mario = App->textures->Load("Assets/perso.png");
	paso = App->audio->LoadFx("Assets/2. SFX (Walking).wav");
	salto = App->audio->LoadFx("Assets/3. SFX (Jump).wav");	
	muerteMario = App->audio->LoadFx("Assets/5. SFX (Fall).wav");	
	lastanimation = &topescalera;

	destroyed = false;
	//collider = App->collisions->AddCollider({ Posicion.x, Posicion.y, 16, 40 }, Collider::Type::PLAYER, this);

	return true;
}
update_status ModulePlayer::Update() 
{
	cont_muerte += 3;
	if ((cont_muerte >= 5714) && (lastanimation == &saltariz || lastanimation == &paradoizq || lastanimation == &mart_iz))
	{	
		App->audio->PlayFx(muerteMario);
		currentAnimation = &dead_mario_l;
		currentAnimation->Update();
		canLateralMov = false;
		_lose = true;

		destroyed = true;
	}
	else if ((cont_muerte >= 5714) &&( lastanimation == &topescalera||lastanimation==&arriba|| lastanimation == &abajo|| lastanimation == &saltarder|| lastanimation == &paradoder|| lastanimation == &mart_der))
	{
		App->audio->PlayFx(muerteMario);
		currentAnimation = &dead_mario_r;
		currentAnimation->Update();
		canLateralMov = false;
		_lose = true;
	}	
	if (cont_muerte >= 4235 && cont_muerte <= 4238)
	{
		App->audio->PlayMusic("Assets/11. Hurry Up!.ogg", 0.4f);
	}
	if (_lose == true || _win == true)
	{
		contToFade += 3;
		if (contToFade >= 200)
		{
			App->fade->FadeToBlack((Module*)App->scene4, (Module*)App->sceneIntro, 90);
			
		}
	}
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
		if (escalera == true) 
		{
			if (plataforma == false) 
			{
				canLateralMov = false;
				Posicion.y -= 1;
				//arriba.Reset();
				if (lastanimation == &topescalera) 
				{
					canLateralMov = true;
					currentAnimation = &espalda;
					lastanimation = &espalda;
				}
				else 
				{
					currentAnimation = &arriba;
					currentAnimation->Update();
				}
				escalera = false;

			}
			else
			{
				canLateralMov = true;
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
				canLateralMov = true;
				Posicion.y += 3;
				//abajo.Reset();
				if (lastanimation == &topescalera)
				{
					canLateralMov = true;
					currentAnimation = &arriba;
					currentAnimation->Update();
					lastanimation = &arriba;
				}
				else
				{
					currentAnimation = &arriba;
					currentAnimation->Update();

				}

				escalera = false;
			}
			else 
			{
				canLateralMov = false;
				Posicion.y += 1;
				currentAnimation = &abajo;
				currentAnimation->Update();

			}
		}
	}
	if ((App->input->keys[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT) && canLateralMov == true)
	{
		lastanimation = &mart_der;
		tecla = 0;
		Posicion.x += 2;
		if (jumpact == false) {
			contador++;
		}
		//derecha.Reset();
		currentAnimation = &mart_der;
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
	if ((App->input->keys[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT) && canLateralMov == true)
	{
		lastanimation = &mart_iz;
		tecla = 1;
		Posicion.x -= 2;
		if (jumpact == false) {
			contador++;
		}
		//izquierda.Reset();
		currentAnimation = &mart_iz;
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
	collider->SetPos(Posicion.x+4, Posicion.y-20);
	mart->SetPos(Posicion.x + 45, Posicion.y );
	mart2->SetPos(Posicion.x - 30, Posicion.y);
	return update_status::UPDATE_CONTINUE;
}
update_status ModulePlayer::PostUpdate() {
	//App->render->Blit(marioo, 0, 0, nullptr);
	SDL_Rect rect = App->player->currentAnimation->GetCurrentFrame();
	if ((rect.x == 199 && rect.y == 73 && rect.w == 16 && rect.h == 29) || (rect.x == 80 && rect.y == 73 && rect.w == 16 && rect.h == 29)) {
		App->render->Blit(mario, App->player->Posicion.x, App->player->Posicion.y - 36, &rect);
	}
	else if ((rect.x == 35 && rect.y == 79 && rect.w == 26 && rect.h == 17)) {
		App->render->Blit(mario, App->player->Posicion.x - 20, App->player->Posicion.y, &rect);
	}
	else if ((rect.x == 200 && rect.y == 39 && rect.w == 15 && rect.h == 15) || (rect.x == 239 && rect.y == 41 && rect.w == 15 && rect.h == 13)) {
		App->render->Blit(mario, App->player->Posicion.x, App->player->Posicion.y + 25, &rect);
	}
	else {
		App->render->Blit(mario, App->player->Posicion.x, App->player->Posicion.y, &rect);

	}

	SDL_Rect win_lose = { 0,0,98,20 };
	if (_win == true)
	{
		App->render->Blit(win, 200, 400, &win_lose);
	}
	else if (_lose == true)
	{
		App->render->Blit(lose, 200, 400, &win_lose);
	}

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
	if (c1 == collider && c2->type == Collider::escalera) 
	{
		Posicion.y -= 2;
		escalera = true;
	}
	else 
	{

		if (c1 == collider && c2->type == Collider::plataforma) 
		{

			Posicion.y -= 2;
			plataforma = true;

		}
		else 
		{
			plataforma = false;
		}
	}

	if (c1->type == Collider::martillo && c2->type == Collider::Enemigo)
	{
		_win = true;
		canLateralMov = false;
	}

	
}