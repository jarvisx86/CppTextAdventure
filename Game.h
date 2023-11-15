#include "Player.h"
#include "PlayerOptions.h"

#pragma once
class Game
{
public:
	void Run();

private:
	void WelcomePlayer(Player& player);
	void GivePlayerOptions();
	void GetPlayerInput(std::string& playerInput);
	PlayerOptions EvaluateInput(std::string& playerInput);

};

