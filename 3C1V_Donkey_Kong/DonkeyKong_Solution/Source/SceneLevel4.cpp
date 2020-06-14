#include "SceneLevel4.h"
#include"ModuleObjet.h"
#include "stdio.h"
#include<time.h>
#include "Application.h"
#include "ModuleInput.h"
#include "Globals.h"
#include "Module.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"
#include "Animation.h"
#include "ModuleFonts.h"
#include "SDL/include/SDL_scancode.h"
#include "ModuleFadeToBlack.h"
#include "SDL/include/SDL.h"
#pragma comment( lib, "SDL/libx86/SDL2.lib")
#pragma comment( lib, "SDL/libx86/SDL2main.lib")

SceneLevel4::SceneLevel4(bool startEnabled) : Module(startEnabled)
{

}

SceneLevel4::~SceneLevel4()
{

}

// Load assets
bool SceneLevel4::Start()
{
	srand(time(NULL));

	LOG("Loading background assets");

	bool ret = true;
	App->player->Enable();
	_highscore = App->player->highscore;
	App->player->lvl = 4;
	App->player->Posicion.x = 120;
	App->player->Posicion.y = 656;
	App->player->hammerMode = false;
	App->player->canLateralMov = true;
	App->enemies->Enable();

	App->objet->Enable();
	App->audio->PlayMusic("Assets/8. Stage 4 BGM.ogg");
	testTexture = App->textures->Load("Assets/lvl4.png");
	lvl4_2 = App->textures->Load("Assets/ending2.png");
	princesa = App->textures->Load("Assets/sprites.png");
	highscore = App->textures->Load("Assets/carteles y mensajes.png");
	oneup = App->textures->Load("Assets/carteles y mensajes.png");
	bonus = App->textures->Load("Assets/carteles y mensajes.png");
	lvl = App->textures->Load("Assets/carteles y mensajes.png");
	four = App->textures->Load("Assets/carteles y mensajes.png");
	littlemario = App->textures->Load("Assets/letras.png");
	hearth = App->textures->Load("Assets/sprites.png");
	mario_hearth = App->textures->Load("Assets/sprites.png");
	vida3 = App->textures->Load("Assets/3vidas.png");
	contmusic = 0;
	//547
	App->collisions->AddCollider({ 0, 698, 672, 10 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 0, 699, 672, 10 }, Collider::Type::plataforma);

	App->collisions->AddCollider({ 11, 580, 627,10 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 35, 460, 579,10 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 59, 340, 531,10 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 83, 220, 483,10 }, Collider::Type::plataforma);

	App->collisions->AddCollider({ -15, 469, 40, 10 }, Collider::Type::Enemigo);
	App->collisions->AddCollider({ 625, 469, 40, 10 }, Collider::Type::Enemigo);
	App->collisions->AddCollider({ -15, 349, 60, 10 }, Collider::Type::Enemigo);
	App->collisions->AddCollider({ 600, 349, 60, 10 }, Collider::Type::Enemigo);
	App->collisions->AddCollider({ -15 , 229, 84, 10 }, Collider::Type::Enemigo);
	App->collisions->AddCollider({ 575, 229, 84, 10 }, Collider::Type::Enemigo);
	//primer piso
	App->collisions->AddCollider({ 18, 580, 10,81 }, Collider::Type::escalera);
	App->collisions->AddCollider({ 306, 580, 10,81 }, Collider::Type::escalera);
	App->collisions->AddCollider({ 618, 580, 10,81 }, Collider::Type::escalera);

	App->collisions->AddCollider({ 18, 699, 10,3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 306, 699, 10,3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 618, 699, 10,3 }, Collider::Type::plataforma);

	//segundo piso
	App->collisions->AddCollider({ 42, 460, 10,81 }, Collider::Type::escalera);
	App->collisions->AddCollider({ 210, 460, 10,81 }, Collider::Type::escalera);
	App->collisions->AddCollider({ 426, 460, 10,81 }, Collider::Type::escalera);
	App->collisions->AddCollider({ 594, 460, 10,81 }, Collider::Type::escalera);

	App->collisions->AddCollider({ 42, 580, 10,3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 210, 580, 10,3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 426, 580, 10,3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 594, 580, 10,3 }, Collider::Type::plataforma);

	App->collisions->AddCollider({ 66, 340, 10,81 }, Collider::Type::escalera);
	App->collisions->AddCollider({ 306, 340, 10,81 }, Collider::Type::escalera);
	App->collisions->AddCollider({ 570, 340, 10,81 }, Collider::Type::escalera);

	App->collisions->AddCollider({ 66, 460, 10,3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 306, 460, 10,3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 570, 460, 10,3 }, Collider::Type::plataforma);

	App->collisions->AddCollider({ 90, 220, 10,81 }, Collider::Type::escalera);
	App->collisions->AddCollider({ 186, 220, 10,81 }, Collider::Type::escalera);
	App->collisions->AddCollider({ 450, 220, 10,81 }, Collider::Type::escalera);
	App->collisions->AddCollider({ 546, 220, 10,81 }, Collider::Type::escalera);

	App->collisions->AddCollider({ 90, 340, 10,3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 186, 340, 10,3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 450, 340, 10,3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 546, 340, 10,3 }, Collider::Type::plataforma);
	//Martillo
	int direccion = 0, x;
	App->enemies->AddEnemy(Enemy_Type::KONG, 280, 153, direccion);
	


	App->objet->AddObjet(Objet_Type::placa, 165, 500);
	App->objet->AddObjet(Objet_Type::placa, 477, 500);
	App->objet->AddObjet(Objet_Type::placa, 165, 380);
	App->objet->AddObjet(Objet_Type::placa, 477, 380);
	App->objet->AddObjet(Objet_Type::placa, 165, 260);
	App->objet->AddObjet(Objet_Type::placa, 477, 260);
	App->objet->AddObjet(Objet_Type::placa, 167, 140);
	App->objet->AddObjet(Objet_Type::placa, 477, 140);
	App->objet->AddObjet(Objet_Type::tanque, 530, 553);
	App->objet->AddObjet(Objet_Type::bolso, 390, 670);
	App->objet->AddObjet(Objet_Type::paraguas, 120, 170);
	App->objet->AddObjet(Objet_Type::martillo, 325, 280);
	App->objet->AddObjet(Objet_Type::martillo, 10, 400);

	char lookupTable_r[] = { "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ.-" };
	char lookupTable_b[] = { "0123456789" };
	char lookupTable_a[] = { "0123456789" };
	//rojas = App->fonts->Load("Assets/letras_rojas.png", lookupTable_r, 1);
	blancas = App->fonts->Load("Assets/letras_blancas.png", lookupTable_b, 1);
	amarillas = App->fonts->Load("Assets/letras_amarillas.png", lookupTable_a, 1);


	return ret;
}


void SceneLevel4::DebugDrawGamepadInfo()
{
	GamePad& pad = App->input->pads[0];

	sprintf_s(_scoreText, 150, "pad 0 %s, press 1/2/3 for rumble", (pad.enabled) ? "plugged" : "not detected");
	App->fonts->BlitText(5, 10, blancas, _scoreText);

	sprintf_s(_scoreText, 150, "buttons %s %s %s %s %s %s %s %s %s %s %s",
		(pad.a) ? "a" : "",
		(pad.b) ? "b" : "",
		(pad.x) ? "x" : "",
		(pad.y) ? "y" : "",
		(pad.start) ? "start" : "",
		(pad.back) ? "back" : "",
		(pad.guide) ? "guide" : "",
		(pad.l1) ? "lb" : "",
		(pad.r1) ? "rb" : "",
		(pad.l3) ? "l3" : "",
		(pad.r3) ? "r3" : ""
	);
	App->fonts->BlitText(5, 20, blancas, _scoreText);

	sprintf_s(_scoreText, 150, "dpad %s %s %s %s",
		(pad.up) ? "up" : "",
		(pad.down) ? "down" : "",
		(pad.left) ? "left" : "",
		(pad.right) ? "right" : ""
	);
	App->fonts->BlitText(5, 30, blancas, _scoreText);

	sprintf_s(_scoreText, 150, "left trigger  %0.2f", pad.l2);
	App->fonts->BlitText(5, 40, blancas, _scoreText);
	sprintf_s(_scoreText, 150, "right trigger %0.2f", pad.r2);
	App->fonts->BlitText(5, 50, blancas, _scoreText);

	sprintf_s(_scoreText, 150, "left thumb    %.2fx, %0.2fy", pad.l_x, pad.l_y);
	App->fonts->BlitText(5, 60, blancas, _scoreText);

	sprintf_s(_scoreText, 150, "   deadzone   %0.2f", pad.l_dz);
	App->fonts->BlitText(5, 70, blancas, _scoreText);

	sprintf_s(_scoreText, 150, "right thumb   %.2fx, %0.2fy", pad.r_x, pad.r_y);
	App->fonts->BlitText(5, 80, blancas, _scoreText);

	sprintf_s(_scoreText, 150, "   deadzone   %0.2f", pad.r_dz);
	App->fonts->BlitText(5, 90, blancas, _scoreText);
}

update_status SceneLevel4::Update()
{
	cont++;
	int direccion = -1;
	if (cont == 300)
	{
		App->enemies->AddEnemy(Enemy_Type::LLAMA, 70, 200, direccion);
	}
	if (cont == 600)
	{
		App->enemies->AddEnemy(Enemy_Type::LLAMA, 250, 320, direccion);
	}
	if (cont == 900)
	{
		App->enemies->AddEnemy(Enemy_Type::LLAMA, 350, 440, direccion);
	}
	if (cont == 1200)
	{
		App->enemies->AddEnemy(Enemy_Type::LLAMA, 150, 560, direccion);
	}
	if (cont == 1500)
	{
		App->enemies->AddEnemy(Enemy_Type::LLAMA, 70, 200, direccion);
		cont = 0;
	}


	if (App->input->keys[SDL_SCANCODE_F6] == KEY_STATE::KEY_DOWN)
	{
		App->fade->FadeToBlack(this, (Module*)App->sceneIntro, 90);
	}
	if (App->input->keys[SDL_SCANCODE_F7] == KEY_STATE::KEY_DOWN)
	{
		App->player->_win = true;
	}
	if (App->input->keys[SDL_SCANCODE_F8] == KEY_STATE::KEY_DOWN)
	{
		App->player->_lose = true;
	}
	if (App->input->keys[SDL_SCANCODE_F9] == KEY_STATE::KEY_DOWN) {
		if (App->player->godmode == false) {
			App->player->godmode = true;
			App->collisions->debug = true;
		}
		else {
			App->player->godmode = false;
			App->collisions->debug = false;
		}
	}
	temp++;
	if (temp % 120 == 0 && App->player->_win == false)
	{
		_bonus = _bonus - 100;
	}
	if (_score >= _highscore)
	{
		_highscore = _score;
	}
	if (_bonus <= 0000)
	{
		_bonus = 0000;
	}
	if (temp == 4800)
	{
		App->audio->PlayMusic("Assets/11. Hurry Up!.ogg", 0.4f);
	}
	if (App->player->_win == true)
	{
		SDL_DestroyTexture(App->player->mario);
		SDL_Rect _heart = { 56,188,16,14 };
		App->render->Blit(hearth, 380, 65, &_heart);
		SDL_Rect _mheart = { 33,194,13,17 };
		App->render->Blit(mario_hearth, 440, 70, &_mheart);
		_score += _bonus;
		_bonus = NULL;
	}

	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status SceneLevel4::PostUpdate()
{
	if (App->player->_lose == true)
	{
		if (App->player->vidas <= 0)
		{
			App->fade->FadeToBlack((Module*)App->scene4, (Module*)App->sceneIntro, 180);
		}
		else if (App->player->vidas > 0)
		{
			App->fade->FadeToBlack((Module*)App->scene4, (Module*)App->howhigh3, 180);
		}
	}
	if (App->player->_win == true)
	{
		App->fade->FadeToBlack((Module*)App->scene4, (Module*)App->sceneIntro, 540);
	}
	// Draw everything --------------------------------------
	// TODO 10: Blit our test texture to check functionality
	App->render->Blit(testTexture, 0, 130, nullptr);
	int direccion = 0;
	if (App->player->_win == true)
	{
		if (contmusic==0)
		{
			App->audio->PlayMusic("Assets/14. Ending lvl4.wav");
			contmusic = 1;
		}
		App->objet->CleanUp();
		SDL_DestroyTexture(testTexture);
		App->render->Blit(lvl4_2, -40, -20, nullptr);
	}
	SDL_Rect princesa_ = { 8,188,15,23 };
	App->render->Blit(princesa, 320, 60, &princesa_);
	SDL_Rect highscore_ = { 63,36,80,8 };
	App->render->Blit(highscore, 225, 0, &highscore_);
	SDL_Rect oneup_ = { 16,36,27,8 };
	App->render->Blit(oneup, 70, 0, &oneup_);
	SDL_Rect bonus_ = { 146,64,45,30 };
	App->render->Blit(bonus, 510, 80, &bonus_);
	SDL_Rect lvl_ = { 0,58,22,8 };
	App->render->Blit(bonus, 510, 70, &lvl_);
	SDL_Rect four_ = { 63,23,8,8 };
	App->render->Blit(four, 578, 70, &four_);
//	SDL_Rect littlemario_ = { 530,51,8,10 };
	//App->render->Blit(littlemario, 10, 70, &littlemario_);
	SDL_Rect rect_1vida = { 2, -1, 8, 9 };
	SDL_Rect rect_2vidas = { 2, -1, 17, 9 };
	SDL_Rect rect_3vidas = { 2, -1, 27, 9 };
	if (App->player->vidas == 3)
	{
		App->render->Blit(vida3, 30, 60, &rect_3vidas);
	}
	if (App->player->vidas == 2)
	{
		App->render->Blit(vida3, 40, 60, &rect_2vidas);
	}
	if (App->player->vidas == 1)
	{
		App->render->Blit(vida3, 40, 60, &rect_1vida);
	}

	sprintf_s(_scoreText, 10, "%6d", _score);
	sprintf_s(_highscoreText, 10, "%6d", _highscore);
	sprintf_s(_bonusText, 10, "%4d", _bonus);

	// TODO 3: Blit the text of the score in at the bottom of the screen
	App->fonts->BlitText(29, 27, blancas, _scoreText);
	App->fonts->BlitText(270, 27, blancas, _highscoreText);
	App->fonts->BlitText(527, 134, amarillas, _bonusText);

	return update_status::UPDATE_CONTINUE;
}

bool SceneLevel4::CleanUp()
{
	App->player->highscore = _highscore;
	temp = 0;
	App->player->cont_muerte = 0;
	App->player->cont_win = 0;
	App->player->Disable();
	App->enemies->Disable();
	App->objet->Disable();

	App->player->_lose = false;
	App->player->_win = false;
	App->player->canLateralMov = true;
	App->player->contToFade = 0;
	App->player->Posicion.x = 120;
	App->player->Posicion.y = 656;
	_score = 000000;
	_bonus = 5000;
	App->textures->Unload(kong);
	App->textures->Unload(martillo);
	App->textures->Unload(martillo2);
	App->textures->Unload(testTexture);
	//App->audio->CleanUp();
	App->textures->Unload(lvl4_2);
	App->textures->Unload(princesa);
	App->textures->Unload(highscore);
	App->textures->Unload(oneup);
	App->textures->Unload(bonus);
	App->textures->Unload(lvl);
	App->textures->Unload(four);
	App->textures->Unload(littlemario);
	App->textures->Unload(hearth);
	App->textures->Unload(mario_hearth);
	App->fonts->UnLoad(rojas);
	App->fonts->UnLoad(blancas);
	
	App->textures->Disable();
	App->player->Disable();
	App->collisions->CleanUp();

	


	return true;
}