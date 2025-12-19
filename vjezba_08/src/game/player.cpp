#include "game.hpp"

void Player::addScore(int amount)
{
    score += amount;
    std::cout << name << "> earned " << amount << " points [" << score << "]" << '\n';
}

void Player::attack(GameCharacter &game_char)
{
    if (Enemy *enemy = dynamic_cast<Enemy *>(&game_char))
    {
        if (isAlive())
        {
            attackEnemy(*enemy);
        }
        else
        {
            std::cout << name << "> unable to attack while dead" << '\n';
        }
    }
}

Player::Player(int health, std::string name)
    : GameCharacter(health, name)
{
}
