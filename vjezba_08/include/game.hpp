#ifndef GAME_H
#define GAME_H

#include <string>
#include <iostream>

constexpr int HEALTH_DEATH_THRESHOLD = 0;
constexpr int SCORE_ON_KILL = 10;

constexpr int WARRIOR_INIT_HP = 120;
constexpr int MAGE_INIT_HP = 80;
constexpr int GNOME_INIT_HP = 90;
constexpr int BOSS_INIT_HP = 300;

constexpr int GNOME_INIT_DIFFICULTY = 3;
constexpr int BOSS_INIT_DIFFICULTY = 8;

constexpr int MAGE_SP_HEALTH_THRESHOLD = 50;
constexpr int GNOME_SP_HEALTH_THRESHOLD = 20;
constexpr int BOSS_MAX_HP_THRESHOLD = 300;

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

class Enemy : public GameCharacter
{
protected:
    unsigned int difficulty;

public:
    void attack(GameCharacter &game_char) override;
    virtual void attackPlayer(Player &player) = 0;
    Enemy(int health, std::string name, unsigned int difficulty);
};
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

// Player classes
class Warrior : public Player
{
protected:
    bool shieldActive = false;
    float shieldEffectiveness = 0.5;
    int attackDamage = 20;

public:
    Warrior(std::string name);

    void attackEnemy(Enemy &enemy) override;
    void takeDamage(int amount) override;
    void specialAbility() override;
};

class Mage : public Player
{
protected:
    int mana = 100;

    int attackDamageFireball = 40;
    int manaCostFireball = 20;
    int attackDamageStick = 20;

public:
    Mage(std::string name);

    void attackEnemy(Enemy &enemy) override;
    void specialAbility() override;
};

// Enemy classes
class Gnome : public Enemy
{
protected:
    int attackDamage = 5;

public:
    Gnome(std::string name);

    void attackPlayer(Player &player) override;
    void specialAbility() override;
};

class Boss : public Enemy
{
protected:
    int attackDamage = 10;
    int healthRegen = 50;

public:
    Boss(std::string name);

    void attackPlayer(Player &player) override;
    void specialAbility() override;
};

#endif