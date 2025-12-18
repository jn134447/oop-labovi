#ifndef GAME_H
#define GAME_H

#include <string>

enum class Difficulty
{
    EASY,
    MEDIUM,
    HARD,
    INSANE
};

class GameCharacter
{
protected:
    int health;
    std::string name;
};

class Player : public GameCharacter
{
protected:
    int score;
};

class Enemy : public GameCharacter
{
protected:
    Difficulty difficulty;
};

// Player classes

// Enemy classes

#endif