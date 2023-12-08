#include "Player.h"

std::string Player::GetPlayerName() {
	return m_name;
}

void Player::SetPlayerName(std::string playerName) {
	m_name = playerName;
}

void Player::SetCurrentRoom(const Room* pCurrentRoom)
{
	m_pCurrentRoom = pCurrentRoom;
}

const Room* Player::GetCurrentRoom() const
{
	return m_pCurrentRoom;
}
