#include "Player.h"

std::string Player::GetPlayerName() {
	return m_name;
}

void Player::SetPlayerName(std::string playerName) {
	m_name = playerName;
}