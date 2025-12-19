#include "game.hpp"

GameCharacter::GameCharacter(int health, std::string name)
    : health(health),
      name(name)
{
}

void GameCharacter::useSpecialAbility()
{
    if (isAlive())
        specialAbility();
}

void GameCharacter::displayStatus() const
{
    std::cout << "displayStatus(): "
              << health << '\t'
              << name << '\t'
              << dead << '\n';
}

void GameCharacter::takeDamage(int amount)
{
    health -= amount;
    std::cout << name << "> took " << amount << " damage [" << health << "]" << '\n';

    if (health <= HEALTH_DEATH_THRESHOLD)
    {
        dead = true;
        std::cout << name << "> died" << '\n';
    }
}

bool GameCharacter::isAlive() const
{
    return !dead;
}