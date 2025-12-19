#include "game.hpp"

Warrior::Warrior(std::string name) : Player(WARRIOR_INIT_HP, name)
{
}

void Warrior::attackEnemy(Enemy &enemy)
{
    if (!enemy.isAlive())
        return;

    std::cout << name << "> slashes with his sword" << '\n';
    enemy.takeDamage(attackDamage);

    // if killed
    if (!enemy.isAlive())
    {
        addScore(SCORE_ON_KILL);
    }
}

void Warrior::takeDamage(int amount)
{
    if (shieldActive)
    {
        amount = amount * shieldEffectiveness;
        shieldActive = false;
    }

    health -= amount;
    std::cout << name << "> took " << amount << " damage [" << health << "]" << '\n';

    if (health <= HEALTH_DEATH_THRESHOLD)
    {
        dead = true;
        std::cout << name << "> died" << '\n';
        shieldActive = false;
    }
}

void Warrior::specialAbility()
{
    std::cout << name << "> is guarding" << '\n';
    shieldActive = true;
}

Mage::Mage(std::string name) : Player(MAGE_INIT_HP, name)
{
}
