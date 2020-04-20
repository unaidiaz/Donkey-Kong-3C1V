#include "SceneLevel4.h"

#include"ModuleInput.h"
#include"Globals.h"
#include"Module.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"
#include"Animation.h"
#include "SDL/include/SDL_scancode.h"

SceneLevel4::SceneLevel4()
{

}

SceneLevel4::~SceneLevel4()
{

}

// Load assets
bool SceneLevel4::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	App->audio->PlayMusic("Assets/8. Stage 4 BGM.ogg");
	martillo = App->textures->Load("Assets/objetosestaticos.png"); martillo2 = App->textures->Load("Assets/objetosestaticos.png");
	kong = App->textures->Load("Assets/perso.png");
	testTexture = App->textures->Load("Assets/lvl4.png");

	placas = App->textures->Load("Assets/taco.png"); placas2 = App->textures->Load("Assets/taco.png"); placas3 = App->textures->Load("Assets/taco.png");
	placas4 = App->textures->Load("Assets/taco.png"); placas5 = App->textures->Load("Assets/taco.png"); placas6 = App->textures->Load("Assets/taco.png");
	placas7 = App->textures->Load("Assets/taco.png"); placas8 = App->textures->Load("Assets/taco.png"); placas9 = App->textures->Load("Assets/taco.png");
	_bolso = App->textures->Load("Assets/objetosestaticos.png");
	_tanque = App->textures->Load("Assets/objetosestaticos.png");
	_paraguas = App->textures->Load("Assets/objetosestaticos.png");

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
	//Placas
	App->collisions->AddCollider({ 167,500,5,90 }, Collider::Type::placas);
	App->collisions->AddCollider({ 477,500,5,90 }, Collider::Type::placas);
	App->collisions->AddCollider({ 167,377,5,90 }, Collider::Type::placas);
	App->collisions->AddCollider({ 477,377,5,90 }, Collider::Type::placas);
	App->collisions->AddCollider({ 163,257,5,90 }, Collider::Type::placas);
	App->collisions->AddCollider({ 477,257,5,90 }, Collider::Type::placas);
	App->collisions->AddCollider({ 163,137,5,90 }, Collider::Type::placas);
	App->collisions->AddCollider({ 477,137,5,90 }, Collider::Type::placas);
	//"Power-Up"
	App->collisions->AddCollider({ 390, 670,25,35 }, Collider::Type::bolso);
	App->collisions->AddCollider({ 120, 170,40,40 }, Collider::Type::paraguas);
	App->collisions->AddCollider({ 530, 553,50,20 }, Collider::Type::tanque);
	//MARTILLO ATAQUE
	
	App->enemies->AddEnemy(Enemy_Type::LLAMA, 360, 565);
	return ret;
}

update_status SceneLevel4::Update()
{
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
	SDL_Rect taco = { 0,0,8,9 };
	App->render->Blit(placas, 480, 610, &taco);
	App->render->Blit(placas2, 170, 610, &taco);
	App->render->Blit(placas3, 480, 487, &taco);
	App->render->Blit(placas4, 168, 490, &taco);
	App->render->Blit(placas5, 480, 367, &taco);
	App->render->Blit(placas6, 168, 367, &taco);
	App->render->Blit(placas7, 480, 247, &taco);
	App->render->Blit(placas8, 168, 247, &taco);
	SDL_Rect paraguas_ = { 50,0,17,15 };
	App->render->Blit(_paraguas, 120, 200, &paraguas_);
	SDL_Rect bolso_ = { 14,5,10,10 };
	App->render->Blit(_bolso, 400, 700, &bolso_);
	SDL_Rect tanque_ = { 30,6,16,9 };
	App->render->Blit(_tanque, 540, 583, &tanque_);

	return update_status::UPDATE_CONTINUE;
}

bool SceneLevel4::CleanUp()
{
	//App->player->Disable();
	//App->enemies->Disable();

	// TODO 5 (old): Remove All Memory Leaks - no solution here guys ;)

	return true;
}