#include "game.hpp"

void Enemy::attack(GameCharacter &game_char)
{
    if (Player *player = dynamic_cast<Player *>(&game_char))
    {
        if (!game_char.isAlive())
            return;

        attackPlayer(*player);
    }
}

Enemy::Enemy(int health, std::string name, unsigned int difficulty)
    : GameCharacter(health, name),
      difficulty(difficulty)
{
}
