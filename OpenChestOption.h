#pragma once
#include "Option.h"

class Chest;

class OpenChestOption :
    public Option
{
private:
    Chest* m_chest;

public:
    OpenChestOption(Chest* chest, const std::string& outputText)
        : m_chest{chest}
        , Option(PlayerOptions::OpenChest, outputText)
    {

    }

    // Inherited via Option
    void Evaluate(Player& player) override;

};

