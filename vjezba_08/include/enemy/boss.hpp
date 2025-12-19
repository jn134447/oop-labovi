
#ifndef BOSS_H
#define BOSS_H

class Boss : public Enemy
{
protected:
    int attackDamage = 10;
    int healthRegen = 50;

public:
    Boss(std::string name);

    void attackPlayer(Player &player) override;
    void specialAbility() override;
};

#endif