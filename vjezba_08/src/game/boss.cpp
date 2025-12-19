#include "game.hpp"

Boss::Boss(std::string name) : Enemy(BOSS_INIT_HP, name, BOSS_INIT_DIFFICULTY)
{
}

void Boss::attackPlayer(Player &player)
{
    if (!player.isAlive())
        return;

    std::cout << name << "> is attacking, watch out!" << '\n';
    player.takeDamage(attackDamage * difficulty);
}

void Boss::specialAbility()
{
    if (health + healthRegen >= BOSS_MAX_HP_THRESHOLD)
    {
        health = BOSS_MAX_HP_THRESHOLD;
    }
    else
    {
        health += healthRegen;
    }
    std::cout << name << "> used regeneration, now has " << health << " health" << '\n';
}
