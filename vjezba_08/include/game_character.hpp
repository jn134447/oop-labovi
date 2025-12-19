#ifndef GAME_CHARACTER_H
#define GAME_CHARACTER_H

#include "game.hpp"

class GameCharacter
{
protected:
    int health;
    std::string name;
    bool dead = false;

    virtual void specialAbility() = 0;
public:
    GameCharacter(int health, std::string name);

    virtual void attack(GameCharacter &game_char) = 0;
    void useSpecialAbility();

    virtual void displayStatus() const;
    virtual void takeDamage(int amount);
    virtual bool isAlive() const;
};

class Enemy;
class Player;




#include "enemy.hpp"
#include "player.hpp"

#endif