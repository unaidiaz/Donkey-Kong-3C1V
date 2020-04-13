#include "ModuleRender.h"
#include"ModulePlayer.h"
#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleTextures.h"
#include"ModuleCollisions.h"
#include "ModuleAudio.h"
#include "SDL/include/SDL.h"

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

	testTexture = App->textures->Load("Assets/lvl4.png");
	mario = App->textures->Load("Assets/perso.png");

	App->collisions->AddCollider({ 0, 600, 672,27 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 21, 447, 627,27 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 45, 357, 579,27 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 69, 237, 531,27 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 93, 117, 483,27 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 165, -3, 339,27 }, Collider::Type::plataforma);

	App->collisions->AddCollider({ 21, 501, 99,27 }, Collider::Type::escalera);
	App->collisions->AddCollider({ 309, 501, 99,27 }, Collider::Type::escalera);
	App->collisions->AddCollider({ 621, 501, 99,27 }, Collider::Type::escalera);

	App->collisions->AddCollider({ 45, 381, 99,27 }, Collider::Type::escalera);
	App->collisions->AddCollider({ 213, 381, 99,27 }, Collider::Type::escalera);
	App->collisions->AddCollider({ 429, 381, 99,27 }, Collider::Type::escalera);
	App->collisions->AddCollider({ 597, 381, 99,27 }, Collider::Type::escalera);

	App->collisions->AddCollider({ 69, 261, 99,27 }, Collider::Type::escalera);
	App->collisions->AddCollider({ 309, 261, 99,27 }, Collider::Type::escalera);
	App->collisions->AddCollider({ 573, 261, 99,27 }, Collider::Type::escalera);

	App->collisions->AddCollider({ 93, 141, 99,27 }, Collider::Type::escalera);
	App->collisions->AddCollider({ 189, 141, 99,27 }, Collider::Type::escalera);
	App->collisions->AddCollider({ 453, 141, 99,27 }, Collider::Type::escalera);
	App->collisions->AddCollider({ 549, 141, 99,27 }, Collider::Type::escalera);
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
	SDL_Rect rect = App->player->currentAnimation->GetCurrentFrame();
	App->render->Blit(mario, App->player->Posicion.x, App->player->Posicion.y, &rect);
	
	// TODO 8: Display the rendered content to the screen

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
bool ModuleRender::Blit(SDL_Texture* texture, int x, int y, SDL_Rect* section)
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
