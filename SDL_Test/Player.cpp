#include "Player.h"

Player::Player(std::shared_ptr<Room> setRoom, SDL_Renderer * renderer) :
	MazeObject::MazeObject(setRoom), startRoom(setRoom)
{
	if(playerUp == NULL)
		playerUp = IMG_LoadTexture(objRenderer, IMG_PLAYER_UP);
	if (playerDown == NULL)
		playerDown = IMG_LoadTexture(objRenderer, IMG_PLAYER_DOWN);
	if (playerRight == NULL)
		playerRight = IMG_LoadTexture(objRenderer, IMG_PLAYER_RIGHT);
	if (playerLeft == NULL)
		playerLeft = IMG_LoadTexture(objRenderer, IMG_PLAYER_LEFT);
	curObjTexture = playerUp;
}
Player::Player()
{
}

Player::~Player()
{
}
