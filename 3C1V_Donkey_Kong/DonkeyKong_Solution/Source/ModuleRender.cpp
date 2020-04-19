#include "ModuleRender.h"
#include"ModulePlayer.h"
#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleTextures.h"
#include"ModuleCollisions.h"
#include "ModuleAudio.h"
#include "SDL/include/SDL.h"
#pragma comment( lib, "SDL/libx86/SDL2.lib")
#pragma comment( lib, "SDL/libx86/SDL2main.lib")

ModuleRender::ModuleRender() : Module()
{

}

ModuleRender::~ModuleRender()
{

}

bool ModuleRender::Init()
{
	LOG("Creating Renderer context");
	bool ret = true;
	Uint32 flags = 0;

	if (VSYNC == true)
	{
		flags |= SDL_RENDERER_PRESENTVSYNC;
	}

	renderer = SDL_CreateRenderer(App->window->window, -1, flags);

	if (renderer == nullptr)
	{
		LOG("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}

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
	App->collisions->AddCollider({ 163,500,5,90 }, Collider::Type::placas);
	App->collisions->AddCollider({ 473,500,5,90 }, Collider::Type::placas);
	App->collisions->AddCollider({ 163,377,5,90 }, Collider::Type::placas);
	App->collisions->AddCollider({ 473,377,5,90 }, Collider::Type::placas);
	App->collisions->AddCollider({ 163,257,5,90 }, Collider::Type::placas);
	App->collisions->AddCollider({ 473,257,5,90 }, Collider::Type::placas);
	App->collisions->AddCollider({ 163,137,5,90 }, Collider::Type::placas);
	App->collisions->AddCollider({ 473,137,5,90 }, Collider::Type::placas);
	//"Power-Up"
	App->collisions->AddCollider({ 390, 670,25,35 }, Collider::Type::bolso);
	App->collisions->AddCollider({ 120, 170,40,40 }, Collider::Type::paraguas);
	App->collisions->AddCollider({ 530, 553,50,20 }, Collider::Type::tanque);
	return ret;
}
// Called every draw update
update_status ModuleRender::PreUpdate()
{
	// TODO 7: Clear the screen to black before starting every frame

	//Set the color used for drawing operations
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	//Clear rendering target
	SDL_RenderClear(renderer);

	return update_status::UPDATE_CONTINUE;
}

update_status ModuleRender::PostUpdate()
{
	// TODO 10: Blit our test texture to check functionality
	Blit(testTexture, 0, 130, nullptr);
	//Blit(mario, 50, 50, nullptr);
	
	SDL_Rect dkong = { 51,155,40,33 };
	Blit(kong, 280, 153, &dkong);
	SDL_Rect mart = { 0,4,9,11 };
	Blit(martillo, 325, 280, &mart);
	Blit(martillo2, 10, 400, &mart);
	SDL_Rect taco = { 0,0,8,9 };
	Blit(placas, 480, 610, &taco);
	Blit(placas2, 170, 610, &taco);
	Blit(placas3, 480, 487, &taco);
	Blit(placas4, 168, 490, &taco);
	Blit(placas5, 480, 367, &taco);
	Blit(placas6, 168, 367, &taco);
	Blit(placas7, 480, 247, &taco);
	Blit(placas8, 168, 247, &taco);
	SDL_Rect paraguas_ = { 50,0,17,15 };
	Blit(_paraguas, 120, 200, &paraguas_);
	SDL_Rect bolso_ = { 14,5,10,10 };
	Blit(_bolso, 400, 700, &bolso_);
	SDL_Rect tanque_ = { 30,6,16,9 };
	Blit(_tanque, 540, 583, &tanque_);
	// TODO 8: Display the rendered content to the screen
	if (App->collisions->debug == true) {
		App->collisions->DebugDraw();
	}
	//Update the screen
	SDL_RenderPresent(renderer);

	return update_status::UPDATE_CONTINUE;
}

bool ModuleRender::CleanUp()
{
	LOG("Destroying renderer");

	//Destroy the rendering context
	if (renderer != nullptr)
		SDL_DestroyRenderer(renderer);

	return true;
}

// Blit to screen
bool ModuleRender::Blit(SDL_Texture* texture, int x, int y, const SDL_Rect* section)
{
	bool ret = true;
	SDL_Rect rect{ x, y, 0, 0 };

	if (section != nullptr)
	{
		rect.w = section->w;
		rect.h = section->h;
	}
	else
	{
		//Collect the texture size into rect.w and rect.h variables
		SDL_QueryTexture(texture, nullptr, nullptr, &rect.w, &rect.h);
	}
	rect.w = rect.w * 3;
	rect.h = rect.h * 3;
	if (SDL_RenderCopy(renderer, texture, section, &rect) != 0)
	{
		LOG("Cannot blit to screen. SDL_RenderCopy error: %s", SDL_GetError());
		ret = false;
	}

	return ret;
}
bool ModuleRender::DrawQuad(const SDL_Rect& rect, int r, int g, int b, int a, float speed)
{
	bool ret = true;

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(renderer, r, g, b, a);

	SDL_Rect dstRect{
		rect.x + 13 ,
		rect.y + 30 ,
		rect.w ,
		rect.h };

	if (SDL_RenderFillRect(renderer, &dstRect) != 0)
	{
		LOG("Cannot draw quad to screen. SDL_RenderFillRect error: %s", SDL_GetError());
		ret = false;
	}

	return ret;
}
