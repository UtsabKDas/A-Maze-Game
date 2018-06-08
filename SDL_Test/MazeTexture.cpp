#include "MazeTexture.h"



MazeTexture::MazeTexture(const char* inputFileName, SDL_Renderer * renderer)
{
	LoadTexture(renderer, inputFileName);
}

MazeTexture::MazeTexture()
{
}

MazeTexture::~MazeTexture()
{
}
