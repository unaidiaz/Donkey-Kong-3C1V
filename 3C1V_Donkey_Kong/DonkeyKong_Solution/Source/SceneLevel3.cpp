#include "SceneLevel3.h"
#include "ModuleObjet.h"
#include "stdio.h"
#include <time.h>
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

SceneLevel3::SceneLevel3(bool startEnabled) : Module(startEnabled)
{

}

SceneLevel3::~SceneLevel3()
{

}

// Load assets
bool SceneLevel3::Start()
{
	_highscore = App->player->highscore;
	srand(time(NULL));

	LOG("Loading background assets");

	bool ret = true;
	App->player->lvl = 3;
	App->player->canLateralMov = true;
	App->player->Posicion.x = -8;
	App->player->Posicion.y = 655;
	cont = 0;
	App->enemies->Enable();
	App->player->Enable();
	App->objet->Enable();
	kong = App->textures->Load("Assets/perso.png");
	testTexture = App->textures->Load("Assets/lvl3.png");
	princesa = App->textures->Load("Assets/perso.png");
	highscore = App->textures->Load("Assets/carteles y mensajes.png");
	oneup = App->textures->Load("Assets/carteles y mensajes.png");
	bonus = App->textures->Load("Assets/carteles y mensajes.png");
	lvl = App->textures->Load("Assets/lvl3_.png");
	four = App->textures->Load("Assets/carteles y mensajes.png");
	littlemario = App->textures->Load("Assets/letras.png");
	vida3 = App->textures->Load("Assets/3vidas.png");
	App->audio->PlayMusic("Assets/13. Muelle.wav");
	contmusic = 0;
	//547
	App->collisions->AddCollider({ -13, 722, 96, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 128, 722, 147, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 320, 722, 663, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ -13, 675, 75, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 344, 675, 75, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 440, 651, 51, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 512, 627, 51, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 584, 603, 75, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 536, 531, 51, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 464, 507, 51, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 392, 483, 51, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 464, 363, 51, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 536, 339, 51, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 608, 315, 51, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 608, 555 , 51, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 536, 435, 123, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 368, 387, 75, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 176, 603, 75, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ -13, 555, 75, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ -13, 411, 75, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 152, 411, 99, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ -13, 267, 96, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 128, 267, 147, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 320, 267, 171, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 176, 219, 75, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 248, 195, 147, 3 }, Collider::Type::plataforma);


	App->collisions->AddCollider({ 20, 555, 5,84 }, Collider::Type::escalera);
	App->collisions->AddCollider({ 45, 411, 5,107 }, Collider::Type::escalera);
	App->collisions->AddCollider({ 188, 411, 5,157 }, Collider::Type::escalera);
	App->collisions->AddCollider({ 235, 411, 5,157 }, Collider::Type::escalera);
	App->collisions->AddCollider({ 188, 102, 5,132 }, Collider::Type::escalera);
	App->collisions->AddCollider({ 235, 102, 5,132 }, Collider::Type::escalera);
	App->collisions->AddCollider({ 620, 555, 5, 22 }, Collider::Type::escalera);
	App->collisions->AddCollider({ 547, 435, 5, 52 }, Collider::Type::escalera);
	App->collisions->AddCollider({ 405, 387, 5, 67 }, Collider::Type::escalera);
	App->collisions->AddCollider({ 477, 267, 5, 67 }, Collider::Type::escalera);
	App->collisions->AddCollider({ 620, 315, 5, 87 }, Collider::Type::escalera);
	App->collisions->AddCollider({ 380, 195, 5, 37 }, Collider::Type::escalera);

	App->collisions->AddCollider({ 20, 675, 5, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 45, 555, 5, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 188, 603, 5, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 235, 603, 5, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 620, 603, 5, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 620, 435 , 5,3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 547, 530, 5, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 380, 268, 5,3 }, Collider::Type::plataforma);

	App->collisions->AddCollider({ 405, 484, 5,3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 477, 363, 5,3 }, Collider::Type::plataforma);

	App->collisions->AddCollider({ 330, 120, 70, 70 }, Collider::Type::Victoria);

	App->collisions->AddCollider({ -13, 720, 600, 3 }, Collider::Type::Enemigo);
	App->collisions->AddCollider({ 60, 267, 75, 3 }, Collider::Type::Enemigo);


	App->enemies->AddEnemy(Enemy_Type::MUELLE, -15, 250, 0);

	int direccion, x;
	for (int i = 0; i < 2; i++) {
		direccion = rand() % 2;
		if (direccion == 0) {
			direccion = -1;
		}
		switch (i)
		{
		case 0:
			App->enemies->AddEnemy(Enemy_Type::LLAMA, 153, 400, direccion);
			break;
		case 1:
			App->enemies->AddEnemy(Enemy_Type::LLAMA, 530, 420, direccion);
			break;
		}
	}
	App->objet->AddObjet(Objet_Type::tanque, 200, 575);
	App->objet->AddObjet(Objet_Type::bolso, 610, 287);
	App->objet->AddObjet(Objet_Type::paraguas, -10, 365);

	App->objet->AddObjet(Objet_Type::plataforma, 89, 292); //292
	App->objet->AddObjet(Objet_Type::plataforma, 281, 700); //700g

	App->objet->AddObjet(Objet_Type::plataforma, 89, 700); //292
	App->objet->AddObjet(Objet_Type::plataforma, 281, 292); //700

	App->objet->AddObjet(Objet_Type::plataforma, 89, 496); //292
	App->objet->AddObjet(Objet_Type::plataforma, 281, 496); //700

	App->objet->AddObjet(Objet_Type::plataforma, 89, 496); //292
	App->objet->AddObjet(Objet_Type::plataforma, 281, 496); //700

	char lookupTable_r[] = { "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ.-" };
	char lookupTable_b[] = { "0123456789" };
	char lookupTable_az[] = { "0123456789" };
	rojas = App->fonts->Load("Assets/letras_rojas.png", lookupTable_r, 1);
	blancas = App->fonts->Load("Assets/letras_blancas.png", lookupTable_b, 1);
	azules = App->fonts->Load("Assets/letras_azules.png", lookupTable_az, 1);

	return ret;
}


void SceneLevel3::DebugDrawGamepadInfo()
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

update_status SceneLevel3::Update()
{

	cont++;
	if (cont % 145 == 0)
	{
		App->enemies->AddEnemy(Enemy_Type::MUELLE, -15, 250, 0);

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
			App->collisions->debug = false;
			App->player->godmode = false;
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
	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status SceneLevel3::PostUpdate()
{
	if (App->player->_lose == true)
	{
		if (App->player->vidas == 0)
		{
			App->fade->FadeToBlack((Module*)App->scene3, (Module*)App->sceneIntro, 90);
		}
		else if (App->player->vidas != 0)
		{
			App->fade->FadeToBlack((Module*)App->scene3, (Module*)App->howhigh2, 180);
		}
	}
	if (App->player->_win == true)
	{
		if (contmusic == 0)
		{
			App->audio->PlayMusic("Assets/4. Stage 1 CLEAR.ogg");
			contmusic = 1;
		}
		App->objet->CleanUp();
		App->enemies->CleanUp();
		_score += _bonus;
		_bonus = NULL;
		App->fade->FadeToBlack((Module*)App->scene3, (Module*)App->howhigh3, 180);

	}
	// Draw everything --------------------------------------
	// TODO 10: Blit our test texture to check functionality
	App->render->Blit(testTexture, 0, 130, nullptr);
	//Blit(mario, 50, 50, nullptr);

	SDL_Rect dkong = { 51,155,40,33 };
	App->render->Blit(kong, 50, 200, &dkong);
	SDL_Rect princesa_ = { 0,428,14,23 };
	App->render->Blit(princesa, 270, 160, &princesa_);
	SDL_Rect highscore_ = { 63,36,80,8 };
	App->render->Blit(highscore, 225, 0, &highscore_);
	SDL_Rect oneup_ = { 16,36,27,8 };
	App->render->Blit(oneup, 70, 0, &oneup_);
	SDL_Rect bonus_ = { 0,74,44,20 };
	App->render->Blit(bonus, 510, 110, &bonus_);
	SDL_Rect lvl_ = { 0,0,31,8 };
	App->render->Blit(lvl, 510, 70, &lvl_);
	//SDL_Rect littlemario_ = { 530,51,8,10 };
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
	App->fonts->BlitText(527, 134, azules, _bonusText);

	return update_status::UPDATE_CONTINUE;
}

bool SceneLevel3::CleanUp()
{
	App->player->highscore = _highscore;
	temp = 0;
	App->player->cont_muerte = 0;
	App->player->cont_win = 0;
	App->player->Disable();
	App->enemies->Disable();
	App->objet->Disable();
	//App->audio->CleanUp();
	App->player->_lose = false;
	App->player->_win = false;
	App->player->canLateralMov = true;
	App->player->contToFade = 0;
	App->player->Posicion.x = 65;
	App->player->Posicion.y = 675;
	_score = 000000;
	_bonus = 5000;


	App->textures->Unload(kong);
	//App->textures->Unload(martillo);
	//App->textures->Unload(martillo2);
	App->textures->Unload(testTexture);
	//App->audio->CleanUp();

	App->textures->Unload(princesa);
	App->textures->Unload(highscore);
	App->textures->Unload(oneup);
	App->textures->Unload(bonus);
	App->textures->Unload(lvl);
	App->textures->Unload(four);
	App->textures->Unload(littlemario);
	App->fonts->UnLoad(rojas);
	App->fonts->UnLoad(blancas);
	App->fonts->UnLoad(azules);
	App->textures->CleanUp();
	App->collisions->CleanUp();




	


	return true;
}