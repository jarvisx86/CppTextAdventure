#include <iostream>
#include "Game.h"

void Game::RunGame()
{
    Player player;
    WelcomePlayer();

    bool shouldEnd = false;
    
    while (!shouldEnd) 
    {
        GivePlayerOptions();

        std::string playerInput;
        GetPlayerInput(playerInput);

        shouldEnd = EvaluateInput(playerInput) == PlayerOptions::Quit;
    }
    
}

void Game::InitializeRooms()
{
    // Room visual:   
    //               
    // ROOM 2<-->ROOM 1<-->ROOM 3
    //             ^ 
    //             |
    //           ROOM 0

    // Room 0 heads North to Room 1
    m_rooms[0].AddRoom(Room::JoiningDirections::North, &m_rooms[1]);

    // Rooms 1, heads:
    //      East to Room 2
    //      South to Room 1
    //      West to Room 3
    m_rooms[1].AddRoom(Room::JoiningDirections::East, &m_rooms[2]);
    m_rooms[1].AddRoom(Room::JoiningDirections::South, &m_rooms[0]);
    m_rooms[1].AddRoom(Room::JoiningDirections::West, &m_rooms[3]);

    // Room 2 Heads West to Room 1
    m_rooms[2].AddRoom(Room::JoiningDirections::West, &m_rooms[1]);

    // Room 3 Heads East to Room 1
    m_rooms[3].AddRoom(Room::JoiningDirections::East, &m_rooms[1]);
}

void Game::WelcomePlayer()
{
    std::cout << "Hello! Welcome to Adventure!" << std::endl;
    std::cout << "Please enter your name: ";

    std::string playerName;
    std::cin >> playerName;

    std::cout << "Hello " << playerName << "!" << std::endl;

    m_player.SetPlayerName(playerName); 
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
