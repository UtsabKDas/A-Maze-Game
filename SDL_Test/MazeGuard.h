/*
	The Maze Guard is a MazeObject that appears in the Maze. It is centered 
	around a point (guardCenterRoomPtr) and moves between the rooms adjacent
	to the center. It is only be created if a room has 3 or more connected 
	rooms.
	
	If the player is in the same room as a guard, the player will lose a 
	life and have to restart the level.
*/

#pragma once
#include "MazeObject.h"
#include "Room.h"

#define IMG_GUARD "Images/Guard.png"
class MazeGuard :
	public MazeObject
{
private:
	static SDL_Texture * guardTexture;
	std::shared_ptr<Room> guardCenterRoomPtr;
	std::shared_ptr<Room> guardCurRoomPtr;
	std::vector<std::shared_ptr<Room>>::iterator guardIter;
	
public:
	
	MazeGuard(std::shared_ptr<Room> setRoom);
	~MazeGuard();

	//Call after the maze is fully created to set the initial room of the enemy


	void NextCycle()
	{
		(*guardIter)->roomType = None;
		auto roomTypeIter = std::find(begin((*guardIter)->roomTypes), end((*guardIter)->roomTypes), Guard);
		
		if (roomTypeIter != end((*guardIter)->roomTypes))
			(*guardIter)->roomTypes.erase(roomTypeIter);
		
		std::advance(guardIter, 1);
		if (guardIter == std::end(guardCenterRoomPtr->connectRooms))
			guardIter = std::begin(guardCenterRoomPtr->connectRooms);
		/*
		(*guardIter)->AddRoomObject((std::static_pointer_cast<MazeObject>(std::shared_ptr<MazeGuard>(this))));
		guardCurRoomPtr->RemoveRoomObject(std::static_pointer_cast<MazeObject>(std::shared_ptr<MazeGuard>(this)));
		*/
		(*guardIter)->roomType = Guard;
		(*guardIter)->roomTypes.push_back(Guard);
		SetObjRoom(*guardIter);
		//SetObjectRect(&curObjRoom->roomRect);
	}

	void SetGuardTexture()
	{

	}
};

