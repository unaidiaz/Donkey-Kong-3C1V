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

	App->enemies->Enable();
	App->player->Enable();
	App->objet->Enable();
	App->audio->PlayMusic("Assets/8. Stage 4 BGM.ogg");
	martillo = App->textures->Load("Assets/objetosestaticos.png"); martillo2 = App->textures->Load("Assets/objetosestaticos.png");
	kong = App->textures->Load("Assets/perso.png");
	testTexture = App->textures->Load("Assets/lvl4.png");
	princesa = App->textures->Load("Assets/perso.png");
	placas = App->textures->Load("Assets/taco.png"); /*placas2 = App->textures->Load("Assets/taco.png"); placas3 = App->textures->Load("Assets/taco.png");*/
	/*placas4 = App->textures->Load("Assets/taco.png"); placas5 = App->textures->Load("Assets/taco.png"); placas6 = App->textures->Load("Assets/taco.png");
	placas7 = App->textures->Load("Assets/taco.png"); placas8 = App->textures->Load("Assets/taco.png"); placas9 = App->textures->Load("Assets/taco.png");*/
	//_bolso = App->textures->Load("Assets/objetosestaticos.png");
	//_tanque = App->textures->Load("Assets/objetosestaticos.png");
	//_paraguas = App->textures->Load("Assets/objetosestaticos.png");
	highscore = App->textures->Load("Assets/carteles y mensajes.png");
	oneup = App->textures->Load("Assets/carteles y mensajes.png");
	bonus = App->textures->Load("Assets/carteles y mensajes.png");
	lvl = App->textures->Load("Assets/carteles y mensajes.png");
	four = App->textures->Load("Assets/carteles y mensajes.png");
	littlemario = App->textures->Load("Assets/letras.png");
	//547
	App->collisions->AddCollider({ 0, 699, 672,10 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 11, 579, 627,10 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 35, 459, 579,10 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 59, 339, 531,10 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 83, 219, 483,10 }, Collider::Type::plataforma);

	//primer piso
	App->collisions->AddCollider({ 18, 580, 10,82 }, Collider::Type::escalera);
	App->collisions->AddCollider({ 306, 580, 10,82 }, Collider::Type::escalera);
	App->collisions->AddCollider({ 618, 580, 10,82 }, Collider::Type::escalera);

	//segundo piso
	App->collisions->AddCollider({ 42, 460, 10,82 }, Collider::Type::escalera);
	App->collisions->AddCollider({ 210, 460, 10,82 }, Collider::Type::escalera);
	App->collisions->AddCollider({ 426, 460, 10,82 }, Collider::Type::escalera);
	App->collisions->AddCollider({ 594, 460, 10,82 }, Collider::Type::escalera);

	App->collisions->AddCollider({ 66, 340, 10,82 }, Collider::Type::escalera);
	App->collisions->AddCollider({ 306, 340, 10,82 }, Collider::Type::escalera);
	App->collisions->AddCollider({ 570, 340, 10,82 }, Collider::Type::escalera);

	App->collisions->AddCollider({ 90, 220, 10,82 }, Collider::Type::escalera);
	App->collisions->AddCollider({ 186, 220, 10,82 }, Collider::Type::escalera);
	App->collisions->AddCollider({ 450, 220, 10,82 }, Collider::Type::escalera);
	App->collisions->AddCollider({ 546, 220, 10,82 }, Collider::Type::escalera);
	//Martillo
	App->collisions->AddCollider({ 315, 250, 23,33 }, Collider::Type::martillo);
	App->collisions->AddCollider({ -2, 370, 23,33 }, Collider::Type::martillo);
	
	//"Power-Up"
	/*bolso_col = App->collisions->AddCollider({ 390, 670,25,35 }, Collider::Type::bolso);
	paraguas_col = App->collisions->AddCollider({ 120, 170,40,40 }, Collider::Type::paraguas);
	tanque_col = App->collisions->AddCollider({ 530, 553,40,20 }, Collider::Type::tanque);*/
	//MARTILLO ATAQUE
	int direccion, x;
	for (int i = 0; i < 5;i++) {
		direccion = rand() % 2;
		if (direccion == 0) {
			direccion = -1;
		}
		switch (i)
		{
		case 0:
			App->enemies->AddEnemy(Enemy_Type::LLAMA, 50, 200,direccion);
			break;
		case 1:
			App->enemies->AddEnemy(Enemy_Type::LLAMA, 250, 320,direccion);
			break;
		case 2:
			App->enemies->AddEnemy(Enemy_Type::LLAMA, 350, 440,direccion);
			break;
		case 3:
			App->enemies->AddEnemy(Enemy_Type::LLAMA, 150, 560,direccion);
			break;
		case 4:
			App->enemies->AddEnemy(Enemy_Type::LLAMA, 600, 680,direccion);
			break;
		}
	}
	App->objet->AddObjet(Objet_Type::placa, 168, 500);
	App->objet->AddObjet(Objet_Type::placa, 480, 500);
	App->objet->AddObjet(Objet_Type::placa, 170, 377);
	App->objet->AddObjet(Objet_Type::placa, 480, 377);
	App->objet->AddObjet(Objet_Type::placa, 170, 257);
	App->objet->AddObjet(Objet_Type::placa, 480, 257);
	App->objet->AddObjet(Objet_Type::placa, 167, 137);
	App->objet->AddObjet(Objet_Type::placa, 480, 137);
	App->objet->AddObjet(Objet_Type::tanque, 530, 553);
	App->objet->AddObjet(Objet_Type::bolso, 390, 670);
	App->objet->AddObjet(Objet_Type::paraguas, 120, 170);

	char lookupTable_r[] = { "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ.-" };
	char lookupTable_b[] = { "0123456789" };
	char lookupTable_a[] = { "0123456789" };
	rojas = App->fonts->Load("Assets/letras_rojas.png", lookupTable_r, 1);
	blancas = App->fonts->Load("Assets/letras_blancas.png", lookupTable_b, 1);
	amarillas = App->fonts->Load("Assets/letras_amarillas.png", lookupTable_a, 1);

	return ret;
}

update_status SceneLevel4::Update()
{
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
	temp++;
	if (temp % 120 == 0 && App->player->_win == false)
	{
		_bonus = _bonus - 100;
	}
	if (_score >= _highscore)
	{
		_highscore = _score;
	}
	if (_bonus<=0000)
	{
		_bonus = 0000;
	}
	if (temp==4800)
	{
		App->audio->PlayMusic("Assets/11. Hurry Up!.ogg", 0.4f);
	}
	if (App->player->_win == true)
	{
		_score += _bonus;
		_bonus = NULL;
	}

	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status SceneLevel4::PostUpdate()
{
	// Draw everything --------------------------------------
	// TODO 10: Blit our test texture to check functionality
	App->render->Blit(testTexture, 0, 130, nullptr);
	//Blit(mario, 50, 50, nullptr);

	SDL_Rect dkong = { 51,155,40,33 };
	App->render->Blit(kong, 280, 153, &dkong);
	SDL_Rect mart = { 0,4,9,11 };
	App->render->Blit(martillo, 325, 280, &mart);
	App->render->Blit(martillo2, 10, 400, &mart);
	/*SDL_Rect taco = { 0,0,8,9 };
	App->render->Blit(placas, 480, 610, &taco);
	App->render->Blit(placas2, 170, 610, &taco);
	App->render->Blit(placas3, 480, 487, &taco);
	App->render->Blit(placas4, 168, 490, &taco);
	App->render->Blit(placas5, 480, 367, &taco);
	App->render->Blit(placas6, 168, 367, &taco);
	App->render->Blit(placas7, 480, 247, &taco);
	App->render->Blit(placas8, 168, 247, &taco);*/
	SDL_Rect paraguas_ = { 50,0,17,15 };
	App->render->Blit(_paraguas, 120, 200, &paraguas_);
	SDL_Rect bolso_ = { 14,5,10,10 };
	App->render->Blit(_bolso, 400, 700, &bolso_);
	SDL_Rect tanque_ = { 30,6,16,9 };
	App->render->Blit(_tanque, 540, 583, &tanque_);
	SDL_Rect princesa_ = { 0,428,14,23 };
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
	SDL_Rect littlemario_ = { 530,51,8,10 };
	App->render->Blit(littlemario, 10, 70, &littlemario_);


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
	App->player->Posicion.x = 65;
	App->player->Posicion.y = 675;
	_score = 000000;
	_bonus = 5000;
	App->textures->CleanUp();	
	App->collisions->CleanUp();

	return true;
}