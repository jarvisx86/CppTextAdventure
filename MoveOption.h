#pragma once
#include "Option.h"
#include "Room.h"

class Player;

class MoveOption :
    public Option
{
private:
    Room::JoiningDirections m_directionToMove;

public:
    MoveOption(Room::JoiningDirections joiningDirection,
        PlayerOptions chosenOption,
        const std::string& outputText) 
        : Option(chosenOption, outputText)
        , m_directionToMove(joiningDirection)
    {
    }

    void Evaluate(Player& player) override;
};

