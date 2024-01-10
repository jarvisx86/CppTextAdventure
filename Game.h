#pragma once

#include "AttackEnemyOption.h"
#include "Chest.h"
#include "Enemy.h"
#include "EventHandler.h"
#include "MoveOption.h"
#include "OpenChestOption.h"
#include "Player.h"
#include "PlayerOptions.h"
#include "QuitOption.h"
#include "Room.h"
#include <array>

class Game
	: public EventHandler
{
private:
	static const unsigned int m_numberOfRooms = 4;
	using Rooms = std::array<Room, m_numberOfRooms>;
	Rooms m_rooms;

	Player m_player;

	AttackEnemyOption m_attackDragonOption;
	AttackEnemyOption m_attackOrcOption;
	MoveOption m_moveNorthOption;
	MoveOption m_moveEastOption;
	MoveOption m_moveSouthOption;
	MoveOption m_moveWestOption;
	OpenChestOption m_openChestOption;
	QuitOption m_quitOption;

	Sword m_sword;
	Chest m_swordChest;

	Enemy m_dragon;
	Enemy m_orc;

	bool m_playerQuit{ false };

	void InitializeRooms();
	void WelcomePlayer();
	void GivePlayerOptions() const;
	void GetPlayerInput(std::stringstream& playerInputStream) const;
	PlayerOptions EvaluateInput(std::stringstream& playerInputStream);

public:
	Game();

	void RunGame();

	// Inherited via EventHandler
	void HandleEvent(const Event* event) override;
};

