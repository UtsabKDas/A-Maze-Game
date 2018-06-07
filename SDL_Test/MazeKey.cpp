#include "MazeKey.h"


SDL_Texture * MazeKey::keyTexture;

MazeKey::MazeKey(std::shared_ptr<Room> setRoom) :
	MazeObject::MazeObject(setRoom)
{
	if(keyTexture == NULL)
		keyTexture = IMG_LoadTexture(objRenderer, IMG_MAZEKEY);
	curObjTexture = keyTexture;
}

MazeKey::~MazeKey()
{
}
