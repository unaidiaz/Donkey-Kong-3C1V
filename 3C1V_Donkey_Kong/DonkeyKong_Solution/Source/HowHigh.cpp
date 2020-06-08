#include "HowHigh.h"
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

HowHigh::HowHigh(bool startEnabled) : Module(startEnabled)
{

}

HowHigh::~HowHigh()
{

}

// Load assets
bool HowHigh::Start()
{
	srand(time(NULL));

	LOG("Loading background assets");

	bool ret = true;

	App->audio->PlayMusic("Assets/5. How High Can You Get.ogg");
	background = App->textures->Load("Assets/howhigh1.png");




	return ret;
}


void HowHigh::DebugDrawGamepadInfo()
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

update_status HowHigh::Update()
{
	App->render->Blit(background, 0, 0, nullptr);
	if (App->input->keys[SDL_SCANCODE_ESCAPE] == KEY_STATE::KEY_DOWN)
	{
		exit(0);
	}
	return update_status::UPDATE_CONTINUE;
}


// Update: draw background
update_status HowHigh::PostUpdate()
{
	App->fade->FadeToBlack((Module*)App->howhigh, (Module*)App->scene1, 90);
	return update_status::UPDATE_CONTINUE;
}

bool HowHigh::CleanUp()
{
	App->textures->CleanUp();
	return true;
}