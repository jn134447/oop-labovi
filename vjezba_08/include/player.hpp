#ifndef PLAYER_H
#define PLAYER_H

class Player : public GameCharacter
{
protected:
    int score;

public:
    void addScore(int amount);

    void attack(GameCharacter &game_char) override;
    virtual void attackEnemy(Enemy &enemy) = 0;
    Player(int health, std::string name);
};

#include "player/warrior.hpp"
#include "player/mage.hpp"

#endif