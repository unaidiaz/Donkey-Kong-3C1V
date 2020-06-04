#include "Enemy_Kong.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModulePlayer.h"

Enemy_Kong::Enemy_Kong(int x, int y, int direccion) : Enemy(x, y)
{
	kong_alive.PushBack({ 21,45,41,33 });
	kong_alive.PushBack({ 69,45,47,33 });
	kong_alive.PushBack({ 123,45,47,33 });
	kong_alive.loop = true;
	kong_alive.speed = 0.01f;

	kong_dead_1.PushBack({ 69,45,47,33 });
	kong_dead_1.PushBack({ 123,45,47,33 });
	kong_dead_1.loop = true;
	kong_dead_1.speed = 0.07f;

	kong_falling.PushBack({ 177,45,41,33 });
	kong_falling.loop = true;
	kong_alive.speed = 0.01f;

	kong_dead_2.PushBack({ 50,86,40,41 });
	kong_dead_2.PushBack({ 98,86,41,41 });
	kong_dead_2.PushBack({ 146,86,41,41 });
	kong_dead_2.loop = true;
	kong_dead_2.speed = 0.07f;

	kong_barril.PushBack({ 263,179,307 - 263,212 - 179 });
	kong_barril.PushBack({ 309,179,350 - 309,212 - 179 });
	kong_barril.PushBack({ 353,178,397 - 340,211 - 178 });
	kong_barril.loop = true;
	kong_barril.speed = 0.025f;

	currentAnim = &kong_alive;
}

void Enemy_Kong::Update()
{
	if (App->player->lvl == 4)
	{
		if (App->player->_win == true)
		{
			cont++;
			currentAnim = &kong_dead_1;
			currentAnim->Update();
			if (cont > 120 && cont < 250)
			{
				currentAnim = &kong_falling;
			}
			if (cont > 250)
			{
				currentAnim = &kong_dead_2;
			}
			if (currentAnim == &kong_falling)
			{
				position.y += 3;
			}
			if (position.y >= 535)
			{
				position.y = 535;
			}
		}
	}

	if (App->player->lvl == 1)
	{
		currentAnim = &kong_barril;
	}

	if (App->player->lvl == 3)
	{
		currentAnim = &kong_alive;
	}

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}

