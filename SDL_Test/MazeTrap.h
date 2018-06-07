

#pragma once
#include "MazeObject.h"

#define IMG_TRAP_INACTIVE "Images/SpikeTrapInactive.png"
#define IMG_TRAP_ACTIVE "Images/SpikeTrapActive.png"

class MazeTrap :
	public MazeObject
{
private:
	int maxTrapTime;
	int curTrapTime;
	bool active;
	static SDL_Texture * trapActiveTexture;
	static SDL_Texture * trapInactiveTexture;
public:
	
	MazeTrap(std::shared_ptr<Room> room);
	~MazeTrap();

	void NextCycle()
	{
		curTrapTime++;
		if (curTrapTime > maxTrapTime)
		{ 
			curTrapTime = 0;
		}
		SetTrapTexture();
	}
	
	void SetTrapTexture()
	{
		if(curTrapTime == 0)
		{
			curObjRoom->roomType = Trap;
			curObjRoom->roomTypes.push_back(Trap);

			curObjTexture = trapActiveTexture;
		}
		else 
		{
			auto roomTypeIter = std::find(begin((curObjRoom)->roomTypes), end((curObjRoom)->roomTypes), Trap);
			if (roomTypeIter != end(curObjRoom->roomTypes))
			{
				curObjRoom->roomTypes.erase(roomTypeIter);
				curObjTexture = trapInactiveTexture;
			}
			if(curObjRoom->roomType == Trap)
			{
				curObjRoom->roomType = None;
				curObjTexture = trapInactiveTexture;
			}
		}
	}
};

