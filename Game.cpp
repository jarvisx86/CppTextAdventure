#include <iostream>
#include "Game.h"

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
        
        if (shouldEnd == false)
        {
            UpdateOnOption(selectedOption);
        }
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
    
    std::cout << "1: Go North" << std::endl << std::endl;
    std::cout << "2: Go East" << std::endl << std::endl;
    std::cout << "3: Go South" << std::endl << std::endl;
    std::cout << "4: Go West" << std::endl << std::endl;
    std::cout << "5: Quit" << std::endl << std::endl;
}

void Game::GetPlayerInput(std::string& playerInput)
{
    std::cin >> playerInput;
}

PlayerOptions Game::EvaluateInput(std::string& playerInput)
{
    PlayerOptions chosenOption = PlayerOptions::None;
    
    if (playerInput.compare("1") == 0)
    {
        std::cout << "You have chosen to go North!" << std::endl << std::endl;
        chosenOption = PlayerOptions::GoNorth;
    }
    else if (playerInput.compare("2") == 0)
    {
        std::cout << "You have chosen to go East!" << std::endl << std::endl;
        chosenOption = PlayerOptions::GoEast;
    }
    else if (playerInput.compare("3") == 0)
    {
        std::cout << "You have chosen to go South!" << std::endl << std::endl;
        chosenOption = PlayerOptions::GoSouth;
    }
    else if (playerInput.compare("4") == 0)
    {
        std::cout << "You have chosen to go West!" << std::endl << std::endl;
        chosenOption = PlayerOptions::GoWest;
    }
    else if (playerInput.compare("5") == 0) {
        std::cout << "You have chosen to Quit!" << std::endl << std::endl;
        chosenOption = PlayerOptions::Quit;
    }
    else 
    {
        std::cout << "I don't recognize that option, try again!" << std::endl << std::endl;
    }

    return chosenOption;
}

void Game::UpdateOnOption(PlayerOptions selectedOption)
{
    if (selectedOption == PlayerOptions::GoNorth ||
        selectedOption == PlayerOptions::GoEast ||
        selectedOption == PlayerOptions::GoSouth ||
        selectedOption == PlayerOptions::GoWest)
    {
        Room::JoiningDirections directionToMove = Room::JoiningDirections::North;

        switch (selectedOption)
        {
        case PlayerOptions::GoEast:
            directionToMove = Room::JoiningDirections::East;
            break;
        case PlayerOptions::GoSouth:
            directionToMove = Room::JoiningDirections::South;
            break;
        case PlayerOptions::GoWest:
            directionToMove = Room::JoiningDirections::West;
            break;
        default:
            break;
        }

        const Room* pPlayerCurrentRoom = m_player.GetCurrentRoom();
        const Room* pNewRoom = pPlayerCurrentRoom->GetRoom(directionToMove);

        if (pNewRoom != nullptr)
        {
            m_player.SetCurrentRoom(pNewRoom);
        }
        else
        {
            const char* strDirection = "North";
            switch (selectedOption) {
            case PlayerOptions::GoEast:
                strDirection = "East";
                break;
            case PlayerOptions::GoSouth:
                strDirection = "South";
                break;
            case PlayerOptions::GoWest:
                strDirection = "West";
                break;
            }

            std::cout << "There is no room to the "
                << strDirection << std::endl << std::endl;
        }
    }
}
