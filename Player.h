#pragma once

#include "Entity.h"
#include "Item.h"
#include "Sword.h"
#include <string>
#include <vector>

class Room;

class Player : public Entity
{
private:
	std::string m_name;
	Room* m_pCurrentRoom;

	using Items = std::vector<Item*>;
	Items m_items;

public:
	std::string GetPlayerName();

	void SetPlayerName(std::string playerName);

	void SetCurrentRoom(Room* pCurrentRoom);

	Room* GetCurrentRoom() const;

	void AddItem(const Item* item);

	bool HasWeapon();
};

