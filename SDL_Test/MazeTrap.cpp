#include "MazeTrap.h"

SDL_Texture * MazeTrap::trapActiveTexture;
SDL_Texture * MazeTrap::trapInactiveTexture;


MazeTrap::MazeTrap(std::shared_ptr<Room> room) :
	MazeObject(room), maxTrapTime(rand() % 4 + 3), curTrapTime(rand() % maxTrapTime)
{
	if(trapActiveTexture == NULL)
		trapActiveTexture = IMG_LoadTexture(objRenderer, IMG_TRAP_ACTIVE);
	if(trapInactiveTexture == NULL)
		trapInactiveTexture = IMG_LoadTexture(objRenderer, IMG_TRAP_INACTIVE);
	curObjTexture = trapInactiveTexture;
}


MazeTrap::~MazeTrap()
{


}
