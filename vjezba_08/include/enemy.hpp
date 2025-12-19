#ifndef ENEMY_H
#define ENEMY_H

class Enemy : public GameCharacter
{
protected:
    unsigned int difficulty;

public:
    void attack(GameCharacter &game_char) override;
    virtual void attackPlayer(Player &player) = 0;
    Enemy(int health, std::string name, unsigned int difficulty);
};






#include "enemy/gnome.hpp"
#include "enemy/boss.hpp"

#endif