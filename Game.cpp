#include <iostream>
#include "Game.h"
#include <sstream>

Game::Game() 
    : m_moveNorthOption(Room::JoiningDirections::North,
        PlayerOptions::GoNorth,
        "Go North")
    , m_moveEastOption(Room::JoiningDirections::East,
        PlayerOptions::GoEast,
        "Go East")
    , m_moveSouthOption(Room::JoiningDirections::South,
        PlayerOptions::GoSouth,
        "Go South")
    , m_moveWestOption(Room::JoiningDirections::West,
        PlayerOptions::GoWest,
        "Go West")
    , m_quitOption("Quit")
{
    m_options[0] = dynamic_cast<Option*>(&m_moveNorthOption);
    m_options[1] = dynamic_cast<Option*>(&m_moveEastOption);
    m_options[2] = dynamic_cast<Option*>(&m_moveSouthOption);
    m_options[3] = dynamic_cast<Option*>(&m_moveWestOption);
    m_options[4] = dynamic_cast<Option*>(&m_quitOption);
}

void Game::RunGame()
{
    InitializeRooms();

    WelcomePlayer();

    bool shouldEnd = false;
    
    while (!shouldEnd) 
    {
        GivePlayerOptions();

        std::string playerInput;
        GetPlayerInput(playerInput);

        PlayerOptions selectedOption = EvaluateInput(playerInput);
        shouldEnd = selectedOption == PlayerOptions::Quit;
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

    m_player.SetCurrentRoom(&m_rooms[0]);
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
    
    for (unsigned int i = 0; i < m_numberOfOptions; ++i)
    {
        Option* pOption = m_options[i];
        const unsigned int chosenOption = i + 1;
        std::cout << chosenOption << ": " << pOption->GetOutputText() << std::endl << std::endl;

        std::ostringstream chosenOptionString;
        chosenOptionString << chosenOption;
        pOption->SetOptionText(chosenOptionString.str());
    }
}

void Game::GetPlayerInput(std::string& playerInput)
{
    std::cin >> playerInput;
}

PlayerOptions Game::EvaluateInput(std::string& playerInput)
{
    PlayerOptions chosenOption = PlayerOptions::None;
    
    for (unsigned int i = 0; i < m_numberOfOptions; ++i)
    {
        Option* pOption = m_options[i];
        bool handled = pOption->Evaluate(playerInput, m_player);
        if (handled == true)
        {
            chosenOption = pOption->GetChosenOption();
            break;
        }
    }

    if (chosenOption == PlayerOptions::None)
    {
        std::cout << "I don't recognize that option, try again!" << std::endl << std::endl;
    }

    return chosenOption;
}