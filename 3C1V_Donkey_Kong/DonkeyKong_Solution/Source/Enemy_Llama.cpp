#include "Enemy_Llama.h"
#include "Application.h"
#include "ModuleCollisions.h"
#include "ModulePlayer.h"
Enemy_Llama::Enemy_Llama(int x, int y, int direccion) : Enemy(x, y)
{
	llama.PushBack({ 0,63,15,17 });
	llama.PushBack({ 17, 64, 14, 16 });
	llama.loop = true;
	llama.speed = 0.1f;

	llama_azul.PushBack({ 0,81,15,17 });
	llama_azul.PushBack({ 17, 82, 14, 16 });
	llama_azul.loop = true;
	llama_azul.speed = 0.1f;
	srand(time(NULL));
	dire = direccion;
	typo = tipo::llama;
	currentAnim = &llama;
	estado = state::recto;
	//////
	cont = 0;
	prior1 = 0;
	comp = 0;
	cont2 = 0;
	contsub = 0;
	top1 = true;
	top2 = true;
	frames1 = 2;
	frames2 = 2;
	currentAnim = &llama;

	collider = App->collisions->AddCollider({ 0, 0, 24, 24 }, Collider::Type::Enemigo, (Module*)App->enemies);
	collider1 = App->collisions->AddCollider({ 0, 0, 5, 5 }, Collider::Type::top, (Module*)App->enemies);
}
void Enemy_Llama::Update()
{
	if (App->player->hammerMode == true)
	{
		currentAnim = &llama_azul;
	}
	else
	{
		currentAnim = &llama;
	}

	if (App->player->lvl != 1) {
		if (estado == state::recto) {
			position.x = position.x + (dire);

			estado = state::libre;
		}
		else if (estado == state::bajando) {
			position.y = position.y + 1;
			prior1 = 0;
		}
		else if (estado == state::subiendo) {
			if (top2 == false) {
				position.y = position.y - 1;
			}
			else {
				if (contsub < 50) {
					position.y = position.y - 1;
					contsub++;
				}
				else {
					estado = state::recto;
					top2 = true;
					contsub = 0;
				}

			}

		}
		else if (estado == state::libre) {
			if (dire == 1) {
				dire = -1;
			}
			else {
				dire = 1;
			}
			estado = state::recto;
		}
		frames1++;
		frames2++;
	}
	else {
		//primer piso
		if (position.y > 615) {

			if (position.x == 549) {

				subir_o_bajar(collider1);
				if (estado == state::recto) {

					if (cont % 14 == 0) {
						if (dire == 1) {
							position.y--;

						}
						else {
							position.y++;
						}
					}
					position.x = position.x + (dire);

				}
				else if (estado == state::bajando) {

					if (comp > 35) {
						
						position.y++;
						comp--;
						
					}
					else {
						comp = 0;
						if (cont % 14 == 0) {
							if (dire == 1) {
								position.y--;
							}
							else {
								position.y++;
							}
						}
						estado = state::recto;
						position.x = position.x + (dire);

					}
				}
			}
			else if (position.x > 0 && position.x < 318) {
				if (position.x == 40) {
					if (dire == 1) {
						dire = -1;
					}
					else {
						dire = 1;
					}
				}
				position.x = position.x + (dire);
			}
			else if (position.x >= 318 && position.x <= 672) {
				estado = state::recto;
				comp = 0;
				if ( position.x == 565) {
					if (dire == 1) {
						dire = -1;
					}
					else {
						dire = 1;
					}
				}
				if (position.x == 652) {
					if (dire == 1) {
						dire = -1;
					}
					else {
						dire = 1;
					}
				}
				position.x = position.x + (dire);
				if (cont % 14 == 0) {
					if (dire == 1) {
						position.y--;

					}
					else {
						position.y++;
					}

				}
			}
			//segundo piso
		}
		else if (position.y <= 615 && position.y >= 525) {
			//escalera
			if (position.x == 549) {/////bajar
				subir_o_bajar(collider);

				if (estado == state::recto) {
					position.x = position.x + (dire);
					if (dire == 1) {
						position.y++;

					}
					else {
						position.y--;
					}


				}
			}
			else if (position.x == 93) {////////////////////	subir	p
				subir_o_bajar(collider1);
				if (estado == state::recto) {

					if (cont % 14 == 0) {
						if (dire == 1) {
							position.y++;

						}
						else {
							position.y--;
						}

					}
					position.x = position.x + (dire);
				}
				else if (estado == state::bajando) {

					if (comp > 3) {
						if (comp != 0) {
							position.y++;
							comp--;
						}
					}
					else {
						comp = 0;
						if (cont % 14 == 0) {
							if (dire == 1) {
								position.y--;
							}
							else {
								position.y++;
							}
						}
						estado = state::recto;
						position.x = position.x + (dire);

					}
				}
			}
			else if (position.x == 285) {///////////////////////////////subir p
				subir_o_bajar(collider1);
				if (estado == state::recto) {
					if (cont % 14 == 0) {
						if (dire == 1) {
							position.y++;

						}
						else {
							position.y--;
						}

						position.x = position.x + (dire);

					}

				}
				else if (estado == state::bajando) {
					if (comp > 0) {

						position.y++;
						comp--;
					}
					else {
						comp = 0;
						if (cont % 14 == 0) {
							if (dire == 1) {
								position.y--;
							}
							else {
								position.y++;
							}
						}
						position.x = position.x + (dire);
						estado = state::recto;
					}
				}
			}
			else if (position.x >= 0 && position.x <= 597) {
				comp = 0;

				estado = state::recto;
				if (position.x == 1 || position.x == 565) {
					if (dire == 1) {
						dire = -1;
					}
					else {
						dire = 1;
					}
				}
				position.x = position.x + (dire);
				if (cont % 14 == 0) {
					if (dire == 1) {
						position.y++;

					}
					else {
						position.y--;
					}

				}
			}
		}
		//tercer piso
		else if (position.y <= 525 && position.y > 435) {

			if (position.x == 549) {//////////////////////     p
				subir_o_bajar(collider1);
				if (estado == state::recto) {


					if (dire == 1) {
						if (cont % 14 == 0) {
							position.y--;
						}
					}
					else {
						if (cont % 8 == 0) {
							position.y++;
						}
					}


					position.x = position.x + (dire);
				}
				else if (estado == state::bajando) {


					if (comp > 10) {
						if (comp != 0) {
							position.y++;
							comp--;
						}
					}
					else {
						comp = 0;
						if (cont % 14 == 0) {
							if (dire == 1) {
								position.y--;
							}
							else {
								position.y++;
							}
						}
						estado = state::recto;
						position.x = position.x + (dire);

					}
				}
			}
			else if (position.x == 333) {///////////////////////subir   p
				subir_o_bajar(collider1);
				if (estado == state::recto) {
					if (cont % 14 == 0) {
						if (dire == 1) {
							position.y--;

						}
						else {
							position.y++;
						}

					}
					position.x = position.x + (dire);
				}
				else if (estado == state::bajando) {
					if (comp > 0) {
						if (comp != 0) {
							position.y++;
							comp--;
						}
					}
					else {
						comp = 0;
						if (cont % 14 == 0) {
							if (dire == 1) {
								position.y--;
							}
							else {
								position.y++;
							}
						}
						estado = state::recto;
						position.x = position.x + (dire);

					}
				}
			}
			else if (position.x == 93) {////////////////////	bajar
				subir_o_bajar(collider);
				if (estado == state::recto) {

					if (comp == 0) {
						if (cont % 14 == 0) {
							if (dire == 1) {
								position.y--;
							}
							else {
								position.y++;
							}
						}

						position.x = position.x + (dire);
					}
					else {

						if (comp != 20) {

							position.y--;
							comp--;
						}
						else {
							comp = 0;
							if (cont % 14 == 0) {
								if (dire == 1) {
									position.y--;
								}
								else {
									position.y++;
								}
							}

							position.x = position.x + (dire);

						}
					}
				}
			}
			else if (position.x == 285) {///////////////////////////////bajar
				subir_o_bajar(collider);
				if (estado == state::recto) {

					if (comp > 0) {

						position.y--;
						comp--;
					}
					else {
						if (cont % 14 == 0) {
							if (dire == 1) {
								position.y--;
							}
							else {
								position.y++;
							}
						}
						comp = 0;
						position.x = position.x + (dire);

					}

				}



			}
			else if (position.x > 48 && position.x < 672) {
				estado = state::recto;
				comp = 0;
				if (position.x == 50 || position.x == 652) {
					if (dire == 1) {
						dire = -1;
					}
					else {
						dire = 1;
					}
				}
				position.x = position.x + (dire);
				if (dire == 1) {
					if (cont % 15 == 0) {
						position.y--;
					}
				}
				else {
					if (cont % 12 == 0) {
						position.y++;
					}
				}
			}
		}
		//cuarto piso
		else if (position.y <= 435 && position.y > 330) {
			if (position.x == 549) {//////////////////////bajar
				subir_o_bajar(collider);
				if (estado == state::recto) {

					if (comp == 0) {
						if (cont % 14 == 0) {
							if (dire == 1) {
								position.y--;
							}
							else {
								position.y++;
							}
						}

						position.x = position.x + (dire);
					}
					else {

						if (comp != 15) {

							position.y--;
							comp--;
						}
						else {
							comp = 0;
							if (cont % 14 == 0) {
								if (dire == 1) {
									position.y--;
								}
								else {
									position.y++;
								}
							}

							position.x = position.x + (dire);

						}
					}
				}

			}
			else if (position.x == 213) {/////////////////////////subir    p

				subir_o_bajar(collider1);
				if (estado == state::recto) {
					if (cont % 14 == 0) {
						if (dire == 1) {
							position.y++;

						}
						else {
							position.y--;
						}

					}
					position.x = position.x + (dire);
				}
				else if (estado == state::bajando) {
					if (comp > 15) {

						position.y++;
						comp--;
					}
					else {
						comp = 0;
						if (cont % 14 == 0) {
							if (dire == 1) {
								position.y--;
							}
							else {
								position.y++;
							}
						}
						estado = state::recto;
						position.x = position.x + (dire);

					}
				}
			}
			else if (position.x == 93) {////////////////////subir    p
				subir_o_bajar(collider1);
				if (estado == state::recto) {
					if (cont % 14 == 0) {
						if (dire == 1) {
							position.y++;

						}
						else {
							position.y--;
						}
						position.x = position.x + (dire);

					}

				}
				else if (estado == state::bajando) {
					if (comp > 10) {

						position.y++;
						comp--;
					}
					else {
						comp = 0;
						if (cont % 14 == 0) {
							if (dire == 1) {
								position.y--;
							}
							else {
								position.y++;
							}
						}
						estado = state::recto;
						position.x = position.x + (dire);

					}
				}
			}
			else if (position.x == 333) {///////////////////////bajar
				subir_o_bajar(collider);
				if (estado == state::recto) {
					if (comp != 0) {
						position.y--;
						comp--;
					}
					else {
						if (cont % 14 == 0) {
							if (dire == 1) {
								position.y--;
							}
							else {
								position.y++;
							}
						}

						position.x = position.x + (dire);

					}
				}
			}
			else if (position.x > 0 && position.x < 624) {
				if (position.x == 1 || position.x == 600) {
					if (dire == 1) {
						dire = -1;
					}
					else {
						dire = 1;
					}
				}
				position.x = position.x + (dire);
				comp = 0;
				if (dire == 1) {
					if (cont % 18 == 0) {
						position.y++;
					}

				}
				else {
					if (cont % 14 == 0) {
						position.y--;
					}
				}



			}
		}
		//quinto piso
		else if (position.y <= 330) {

			if (position.x == 213) {/////////////////////////bajar
				subir_o_bajar(collider);
				if (estado == state::recto) {
					if (comp != 0) {

						position.y--;
						comp--;
					}
					else {
						if (cont % 14 == 0) {
							if (dire == 1) {
								position.y--;
							}
							else {
								position.y++;
							}
						}

						position.x = position.x + (dire);

					}
				}

			}
			else if (position.x == 93) {////////////////////bajar
				subir_o_bajar(collider);
				if (estado == state::recto) {

					if (comp != 15 && comp != 0) {
						position.y--;
						comp--;
					}
					else {
						comp = 0;
						if (cont % 14 == 0) {
							if (dire == 1) {
								position.y--;
							}
							else {
								position.y++;
							}
						}
						position.x = position.x + (dire);

					}
				}

			}
			else if (position.x >= 48 && position.x < 672) {

				if (position.x == 50 || position.x == 652) {
					if (dire == 1) {
						dire = -1;
					}
					else {
						dire = 1;
					}
				}
				position.x = position.x + (dire);
				comp = 0;
				if (dire == 1) {
					if (cont % 14 == 0) {
						position.y--;
					}

				}
				else {
					if (cont % 10 == 0) {
						position.y++;
					}
				}


			}
		}
		if (estado != state::subiendo && estado != state::bajando) {
			cont2++;
		}

		cont++;
	}

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}
state Enemy_Llama::rando(Collider* colliderm) {
	num = 1 + rand() % 2;
	if (num == 1) {
		if (colliderm == collider1) {
			estado = state::subiendo;
		}
		else {
			estado = state::bajando;
		}
	}
	return estado;
}
void Enemy_Llama::subir_o_bajar(Collider* colliderm) {
	if (colliderm == collider1) {
		if ((estado != state::subiendo && estado != state::bajando) && cont2 > 45) {
			estado = rando(collider1);
			cont2 = 0;
		}
		if (estado == state::subiendo) {
			position.y--;
			cont2 = 0;
		}
		if (estado == state::bajando && comp == 0) {
			cont2 = 0;
			comp = 60;
		}

	}
	else {//bajar
		if ((estado != state::subiendo && estado != state::bajando) && cont2 > 45) {
			estado = rando(collider);
			cont2 = 0;


		}
		if (estado == state::bajando) {
			position.y++;
			cont2 = 0;
		}

		if (estado == state::subiendo) {
			cont2 = 0;
			estado = state::recto;
			comp = 25;
			//position.x = position.x - (dire);
		}

	}
}
