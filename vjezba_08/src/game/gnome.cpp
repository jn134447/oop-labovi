#include "game.hpp"

Gnome::Gnome(std::string name) : Enemy(GNOME_INIT_HP, name, GNOME_INIT_DIFFICULTY)
{
}

void Gnome::attackPlayer(Player &player)
{
    if (!player.isAlive())
        return;

    std::cout << name << "> is attacking" << '\n';
    player.takeDamage(attackDamage * difficulty);
}

void Gnome::specialAbility()
{
    if (health > GNOME_SP_HEALTH_THRESHOLD)
    {
        std::cout << name << "> used the horn." << '\n';
    }
    else
        std::cout << name << "> too weak to use the horn." << '\n';
}
