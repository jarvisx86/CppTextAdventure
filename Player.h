#pragma once
#include <string>
#include "Entity.h"
#include "Room.h"

class Player : public Entity
{
private:
	std::string m_name;
	const Room* m_pCurrentRoom;

public:
	std::string GetPlayerName();

	void SetPlayerName(std::string playerName);

	void SetCurrentRoom(const Room* pCurrentRoom);

	const Room* GetCurrentRoom() const;
};

