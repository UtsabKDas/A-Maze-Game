#include "MazeGuard.h"

SDL_Texture * MazeGuard::guardTexture;

MazeGuard::MazeGuard(std::shared_ptr<Room> setRoom) :
	guardCenterRoomPtr(setRoom),
	guardIter(begin(setRoom->connectRooms)),
	guardCurRoomPtr(*(begin(setRoom->connectRooms))),
	MazeObject(*(begin(setRoom->connectRooms)))
{
	if (guardTexture == NULL)
	{
		guardTexture = IMG_LoadTexture(objRenderer, IMG_GUARD);
	}
	curObjTexture = guardTexture;
}


MazeGuard::~MazeGuard()
{
}
