#include "SceneIntro.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"

SceneIntro::SceneIntro(bool startEnabled) : Module(startEnabled)
{

}

SceneIntro::~SceneIntro()
{

}

// Load assets
bool SceneIntro::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	App->player->vidas = 3;
	IntroTexture = App->textures->Load("Assets/sceneIntro.png");
	App->audio->PlayMusic("Assets/0. Main Music.wav", 1.0f);
	return ret;
}

update_status SceneIntro::Update()
{
	if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
	{
		App->fade->FadeToBlack(this, (Module*)App->howhigh, 90);
	}
	if (App->input->keys[SDL_SCANCODE_ESCAPE] == KEY_STATE::KEY_DOWN)
	{
		exit(0);
	}
	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status SceneIntro::PostUpdate()
{
	// Draw everything --------------------------------------
	App->render->Blit(IntroTexture, 0, 0, NULL);

	return update_status::UPDATE_CONTINUE;
}
bool SceneIntro::CleanUp()
{

	App->textures->Unload(IntroTexture);
	//App->audio->CleanUp();
	return true;
}