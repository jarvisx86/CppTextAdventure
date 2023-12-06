#include "Room.h"

void Room::AddRoom(JoiningDirections direction, Room* pRoom)
{
	m_pJoiningRooms[static_cast<unsigned int>(direction)] = pRoom;
}

Room* Room::GetRoom(JoiningDirections direction) const
{
	return m_pJoiningRooms[static_cast<unsigned int>(direction)];
}

Room::Room()
{
	for (int i = 0; i < static_cast<unsigned int>(JoiningDirections::Max); ++i)
	{
		m_pJoiningRooms[i] = nullptr;
	}
}
