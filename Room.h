#pragma once

#include "Entity.h"

class Room : public Entity
{
public:
	enum class JoiningDirections
	{
		North = 0,
		East,
		South,
		West,
		Max
	};

private:
	Room* m_pJoiningRooms[static_cast<unsigned long long>(JoiningDirections::Max)];

public:
	void AddRoom(JoiningDirections direction, Room* pRoom);

	Room* GetRoom(JoiningDirections direction) const;

	Room();


};

