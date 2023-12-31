#pragma once
#include "Option.h"

class Enemy;

class AttackEnemyOption :
    public Option
{
private:
    Enemy* m_enemy;

public:
    AttackEnemyOption(Enemy* enemy, const std::string& outputText);

    // Inherited via Option
    void Evaluate(Player& player) override;

};

