/*
	The Player class creates a player that exists within the maze and 
	can navigate through using the PlayerMove function. 
*/

#pragma once
#include "MazeObject.h"
#include "Room.h"

#define IMG_PLAYER_RIGHT "../res/Images/PlayerRight.png"
#define IMG_PLAYER_LEFT "../res/Images/PlayerLeft.png"
#define IMG_PLAYER_UP "../res/Images/PlayerUp.png"
#define IMG_PLAYER_DOWN "../res/Images/PlayerDown.png"

class Player :
	public MazeObject
{
private:
	SDL_Texture * playerUp;
	SDL_Texture * playerDown;
	SDL_Texture * playerRight;
	SDL_Texture * playerLeft;
	std::shared_ptr<Room> startRoom;
	//std::shared_ptr<int> playerLives;
public:
	int playerLives = 10;

	Player(std::shared_ptr<Room> setRoom, SDL_Renderer * renderer);
	Player();
	~Player();
	
	bool hasKey = false;

	//Sets the room the player is in
	
	void SetPlayerToStart(std::shared_ptr<Room> room)
	{
		hasKey = false;
		SetStartRoom(room);
	}

	void ResetPlayer(std::shared_ptr<Room> room, int lives)
	{
		playerLives = lives;
		SetPlayerToStart(room);
	}

	void SetStartRoom(std::shared_ptr<Room> room)
	{
		startRoom = room;
		SetObjRoom(room);
	}

	//Moves the player based off arrow inputs. Returns true if move is successful, false if move is not.
	bool PlayerMove(SDL_Keycode key, SDL_Renderer * renderer)
	{
		bool successfulMove = false;
		Coordinate testPos = objPos;
		switch (key)
		{
		case SDLK_UP:
			testPos.yPos--;
			curObjTexture = playerUp;
			break;
		case SDLK_DOWN:
			testPos.yPos++;
			curObjTexture = playerDown;
			break;
		case SDLK_LEFT:
			testPos.xPos--;
			curObjTexture = playerLeft;
			break;
		case SDLK_RIGHT:
			testPos.xPos++;
			curObjTexture = playerRight;
			break;
		default:
			std::cout << "Not a valid input!" << std::endl;
			return successfulMove;
			break;
		}
		//Check if the room the player is trying to move to is one of the connected rooms
		auto iter = std::find_if(begin(curObjRoom->connectRooms), end(curObjRoom->connectRooms), [&testPos](std::shared_ptr<Room> nextRoom) {
			return nextRoom->roomPos == testPos;
		});

		//if it is, move to that room and increase the step count
		if (iter != std::end(curObjRoom->connectRooms))
		{
			SetObjRoom(*iter);
			successfulMove = true;
		}
		else
		{
			std::cout << "Can't Move That Way" << std::endl;
			successfulMove = false;
		}
		return successfulMove;
	}

	//Checks for items in the player's position. Returns false if it is not
	//an obstacle (Trap or Guard)
	bool CheckForObjects()
	{
		//Pick Up Key
		if (std::find(begin(curObjRoom->roomTypes), end(curObjRoom->roomTypes), Key) != end(curObjRoom->roomTypes))
		{
			hasKey = true;
			std::cout << "Picked Up Key" << std::endl;
		}
		//Reset player Position and reduce lives count if it is a trap or guard
		if (std::find(begin(curObjRoom->roomTypes ), end(curObjRoom->roomTypes), Trap) != end(curObjRoom->roomTypes))
		{
			SetObjRoom(startRoom);
			std::cout << "Hit a trap" << std::endl;
			playerLives--;
			return true;
		}
		else if (std::find(begin(curObjRoom->roomTypes), end(curObjRoom->roomTypes), Guard) != end(curObjRoom->roomTypes))
		{
			SetObjRoom(startRoom);
			std::cout << "Hit a guard" << std::endl;
			playerLives--;
			return true;
		}
		return false;
	}
	
	
};

