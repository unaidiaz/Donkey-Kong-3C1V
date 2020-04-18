#ifndef __MODULE_RENDER_H__
#define __MODULE_RENDER_H__

#include "Module.h"
struct SDL_Rect;
struct SDL_Texture;
struct SDL_Renderer;

class ModuleRender : public Module
{
public:
	//Constructor
	ModuleRender();

	//Destructor
	~ModuleRender();

	// Called on application start.
	// Creates the rendering context using the program's window.
	bool Init() override;

	// Called at the beginning of the application loop
	// Clears the rendering context to a background color
	update_status PreUpdate() override;

	// Called at the end of the application loop.
	// Displays a rectangle in the rendering context
	// Updates the screen with the rendered content
	update_status PostUpdate() override;

	// Called on application exit.
	// Destroys the rendering context
	bool CleanUp() override;

	// Prints a texture to the rendering context.
	// Param texture	- A valid SDL Texture, validation checks are not performed
	// Param x,y		- Position x,y in the screen (upper left axis)
	// Param section	- The portion of the texture we want to copy. nullptr for the entire texture
	bool Blit(SDL_Texture* texture, int x, int y, SDL_Rect* section = nullptr);

	bool DrawQuad(const SDL_Rect& rect, int r, int g, int b, int a, float speed = 1.0f);

public:
	
	// Rendering context used for any rendering action
	SDL_Renderer* renderer = nullptr;

private:
	SDL_Texture* mario = nullptr;
	SDL_Texture* testTexture = nullptr;
	SDL_Texture* martillo = nullptr;
};

#endif //__MODULE_RENDER_H__
