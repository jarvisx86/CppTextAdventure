#pragma once
#include <string>

class Player
{
private:
	std::string m_name;

public:
	std::string GetPlayerName();

	void SetPlayerName(std::string playerName);
};

