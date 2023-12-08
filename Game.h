#include "Player.h"
#include "PlayerOptions.h"
#include "Room.h"

#pragma once
class Game
{
private:
	static const unsigned int m_numberOfRooms = 4;
	Room m_rooms[m_numberOfRooms];

	Player m_player;

	void InitializeRooms();
	void WelcomePlayer();
	void GivePlayerOptions();
	void GetPlayerInput(std::string& playerInput);
	PlayerOptions EvaluateInput(std::string& playerInput);
	void UpdateOnOption(PlayerOptions selectedOption);

public:
	void RunGame();
};

