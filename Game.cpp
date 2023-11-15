#include <iostream>
#include "Game.h"

void Game::Run()
{
    Player player;
    WelcomePlayer(player);

    bool shouldEnd = false;
    
    while (!shouldEnd) 
    {
        GivePlayerOptions();

        std::string playerInput;
        GetPlayerInput(playerInput);

        shouldEnd = EvaluateInput(playerInput) == PlayerOptions::Quit;
    }
    
}

void Game::WelcomePlayer(Player& player)
{
    std::cout << "Hello! Welcome to Adventure!" << std::endl;
    std::cout << "Please enter your name: ";

    std::string playerName;
    std::cin >> playerName;

    std::cout << "Hello " << playerName << "!" << std::endl;

    player.SetPlayerName(playerName);
}

void Game::GivePlayerOptions()
{
    std::cout << "What would you like to do? (Enter a corresponding number)" << std::endl << std::endl;
    std::cout << "1: Quit" << std::endl << std::endl;
    std::cout << "2: Look Around" << std::endl << std::endl;
}

void Game::GetPlayerInput(std::string& playerInput)
{
    std::cin >> playerInput;
}

PlayerOptions Game::EvaluateInput(std::string& playerInput)
{
    PlayerOptions chosenOption = PlayerOptions::None;

    if (playerInput.compare("1") == 0) {
        std::cout << "You have chosen to quit..." << std::endl << std::endl;
        chosenOption = PlayerOptions::Quit;
    }
    else if (playerInput.compare("2") == 0)
    {
        std::cout << "You are at the end of a dark road..." << std::endl << std::endl;
        chosenOption = PlayerOptions::LookAround;
    }
    else {
        std::cout << "I don't recognize that option, try again!" << std::endl << std::endl;
    }

    return chosenOption;
}
