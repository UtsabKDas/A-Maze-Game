#pragma once

#include <iostream>

#include "SDL.h"
#include "SDL_image.h"
class MazeTexture
{

private:
	
public:
	SDL_Texture * texture;
	MazeTexture(const char* inputFileName, SDL_Renderer * renderer);
	MazeTexture();
	~MazeTexture();

	void SetTexture(SDL_Texture * assignTexture, SDL_Renderer * renderer)
	{
		texture = assignTexture;
	}

	void LoadTexture(SDL_Renderer * renderer, const char* fileName)
	{
		texture = IMG_LoadTexture(renderer, fileName);
		if (texture == NULL)
		{
			printf("SDL could not load the Texture from ");
			printf(fileName);
			return;
		}
	}
};

