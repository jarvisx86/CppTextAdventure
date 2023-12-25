#include "Game.h"
#include <iostream>
#include <sstream>

Game::Game() 
    : m_attackDragonOption(&m_dragon, "Attack Dragon")
    , m_attackOrcOption(&m_orc, "Attack Orc")
    , m_moveNorthOption(Room::JoiningDirections::North, PlayerOptions::GoNorth, "Go North")
    , m_moveEastOption(Room::JoiningDirections::East, PlayerOptions::GoEast, "Go East")
    , m_moveSouthOption(Room::JoiningDirections::South, PlayerOptions::GoSouth, "Go South")
    , m_moveWestOption(Room::JoiningDirections::West, PlayerOptions::GoWest, "Go West")
    , m_openChestOption(&m_swordChest, "Open Chest")
    , m_quitOption("Quit")
    , m_swordChest(&m_sword)
    , m_dragon(Enemy::EnemyType::Dragon)
    , m_orc(Enemy::EnemyType::Orc)
{
}

void Game::RunGame()
{
    InitializeRooms();

    WelcomePlayer();

    bool playerWon = false;
    bool playerQuit = false;
    
    while (playerQuit == false && playerWon == false) 
    {
        GivePlayerOptions();

        std::stringstream playerInputStream;
        GetPlayerInput(playerInputStream);

        PlayerOptions selectedOption = EvaluateInput(playerInputStream);
        playerQuit = selectedOption == PlayerOptions::Quit;

        playerWon = m_dragon.IsAlive() == false && m_orc.IsAlive() == false;
    }

    if (playerWon == true)
    {
        std::cout << "Congratulations, you rid the dungeon of monsters!" << std::endl;
        std::cout << "Type \"goodbye\" to end" << std::endl;
        std::string input;
        std::cin >> input;
    }
    
}

void Game::InitializeRooms()
{
    // Rooms visual:   
    //               
    // ROOM 2<-->ROOM 1<-->ROOM 3
    //             ^ 
    //             |
    //           ROOM 0

    m_rooms[0].AddRoom(Room::JoiningDirections::North, &m_rooms[1]);
    m_rooms[0].AddStaticOption(&m_moveNorthOption);
    m_rooms[0].AddStaticOption(&m_quitOption);
    m_rooms[0].AddDynamicOption(&m_openChestOption);

    m_rooms[1].AddRoom(Room::JoiningDirections::East, &m_rooms[2]);
    m_rooms[1].AddStaticOption(&m_moveEastOption);
    m_rooms[1].AddRoom(Room::JoiningDirections::South, &m_rooms[0]);
    m_rooms[1].AddStaticOption(&m_moveSouthOption);
    m_rooms[1].AddRoom(Room::JoiningDirections::West, &m_rooms[3]);
    m_rooms[1].AddStaticOption(&m_moveWestOption);
    m_rooms[1].AddStaticOption(&m_quitOption);

    m_rooms[2].AddRoom(Room::JoiningDirections::West, &m_rooms[1]);
    m_rooms[2].AddStaticOption(&m_moveWestOption);
    m_rooms[2].AddStaticOption(&m_quitOption);
    m_rooms[2].AddDynamicOption(&m_attackDragonOption);

    m_rooms[3].AddRoom(Room::JoiningDirections::East, &m_rooms[1]);
    m_rooms[3].AddStaticOption(&m_moveEastOption);
    m_rooms[3].AddStaticOption(&m_quitOption);
    m_rooms[3].AddDynamicOption(&m_attackOrcOption);

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

void Game::GivePlayerOptions() const
{
    std::cout << "What would you like to do? (Enter a corresponding number)" << std::endl << std::endl;
    
    // Print the options for the room
    m_player.GetCurrentRoom()->PrintOptions();
}

void Game::GetPlayerInput(std::stringstream& playerInputStream) const
{
    std::string input;
    std::cin >> input;
    playerInputStream << input;
}

PlayerOptions Game::EvaluateInput(std::stringstream& playerInputStream)
{
    PlayerOptions chosenOption = PlayerOptions::None;
    unsigned int playerInputChoice{ 0 };
    playerInputStream >> playerInputChoice;
    
    try
    {
        Option* option = m_player.GetCurrentRoom()->EvaluateInput(playerInputChoice);
        option->Evaluate(m_player);
        chosenOption = option->GetChosenOption();
    }
    catch (const std::out_of_range&)
    {
        std::cout << "I don't recognize that option, try again!" << std::endl << std::endl;
    }

    return chosenOption;
}