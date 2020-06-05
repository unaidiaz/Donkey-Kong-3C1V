#ifndef __MODULE_TEXTURES_H__
#define __MODULE_TEXTURES_H__

#include "Module.h"

#define MAX_TEXTURES 100

struct SDL_Texture;

class ModuleTextures : public Module
{
public:
	//Constructor
	ModuleTextures(bool startEnabled);
	//Destructor
	~ModuleTextures();
	SDL_Texture* load(const char* nombre);
	// Called on application start.
	// Initializes the SDL_Image library
	bool Init() override;

	// Called on application exit.
	// Frees the memory from all stored textures
	// Uninitializes the SDL_Image library
	bool CleanUp() override;

	// Loads a new SDL_Texture from a file path
	// First creates an SDL_Surface, then converts it into SDL_Texture
	// Returns nullptr if the texture could not be created
	SDL_Texture* const Load(const char* path);

	// Removes the memory from SDL_Texture and removes it from the array
	bool Unload(SDL_Texture* texture);

	// Retrieve size of a texture by modifying parameters with and height
	void GetTextureSize(const SDL_Texture* texture, uint& width, uint& height) const;

	SDL_Texture* textures[MAX_TEXTURES];
};

#endif // __ModuleTextures_H__