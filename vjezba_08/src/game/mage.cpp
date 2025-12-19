#include "game.hpp"

Mage::Mage(std::string name) : Player(MAGE_INIT_HP, name)
{
}

void Mage::attackEnemy(Enemy &enemy)
{
    if (!enemy.isAlive())
        return;

    if (mana >= manaCostFireball)
    {
        mana -= manaCostFireball;
        std::cout << name << "> used fireball" << '\n';
        enemy.takeDamage(attackDamageFireball);
    }
    else
    {
        std::cout << name << "> used his stick to attack" << '\n';
        enemy.takeDamage(attackDamageStick);
    }

    // if killed
    if (!enemy.isAlive())
    {
        addScore(SCORE_ON_KILL);
    }
}

void Mage::specialAbility()
{
    if (health < MAGE_SP_HEALTH_THRESHOLD)
    {
        std::cout << name << "> insufficent amount of health for a teleport" << '\n';
    }
    else
        std::cout << name << "> teleporting..." << '\n';
}