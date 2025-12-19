#ifndef WARRIOR_H
#define WARRIOR_H

class Warrior : public Player
{
protected:
    bool shieldActive = false;
    float shieldEffectiveness = 0.5;
    int attackDamage = 20;

public:
    Warrior(std::string name);

    void attackEnemy(Enemy &enemy) override;
    void takeDamage(int amount) override;
    void specialAbility() override;
};

#endif