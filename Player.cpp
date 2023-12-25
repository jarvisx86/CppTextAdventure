#include "Player.h"

std::string Player::GetPlayerName() {
	return m_name;
}

void Player::SetPlayerName(std::string playerName) {
	m_name = playerName;
}

void Player::SetCurrentRoom(Room* pCurrentRoom)
{
	m_pCurrentRoom = pCurrentRoom;
}

Room* Player::GetCurrentRoom() const
{
	return m_pCurrentRoom;
}

void Player::AddItem(const Item* item)
{
	m_items.push_back(const_cast<Item*>(item));
}

bool Player::HasWeapon()
{
	bool hasWeapon = false;
	for (const Item* item : m_items)
	{
		const Sword* sword = dynamic_cast<const Sword*>(item);
		if (sword != nullptr)
		{
			hasWeapon = true;
			break;
		}
	}

	return hasWeapon;
}
