#pragma once
#include <string>
#include "Entity.h"

class Player : public Entity
{
private:
	std::string m_name;

public:
	std::string GetPlayerName();

	void SetPlayerName(std::string playerName);
};

