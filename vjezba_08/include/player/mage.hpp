
#ifndef MAGE_H
#define MAGE_H

class Mage : public Player
{
protected:
    int mana = 100;

    int attackDamageFireball = 40;
    int manaCostFireball = 20;
    int attackDamageStick = 20;

public:
    Mage(std::string name);

    void attackEnemy(Enemy &enemy) override;
    void specialAbility() override;
};

#endif