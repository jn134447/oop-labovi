#include "game.hpp"

GameCharacter::GameCharacter(int health, std::string name)
    : health(health),
      name(name)
{
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

    if (health < HEALTH_DEATH_THRESHOLD)
        dead = true;
}

bool GameCharacter::isAlive() const
{
    return !dead;
}

void Player::addScore(int amount)
{
    score += amount;
    std::cout << name << "> earned " << amount << " points [" << score << "]" << '\n';
}

Player::Player(int health, std::string name)
    : GameCharacter(health, name)
{
}

Enemy::Enemy(int health, std::string name, unsigned int difficulty)
    : GameCharacter(health, name),
      difficulty(difficulty)
{
}

Warrior::Warrior(std::string name) : Player(WARRIOR_INIT_HP, name)
{
}

void Warrior::attackEnemy(Enemy &enemy)
{
    if (!enemy.isAlive())
        return;

    std::cout << name << "> slashes with his sword" << '\n';
    enemy.takeDamage(attackDamage);

    // if killed
    if (!enemy.isAlive())
    {
        addScore(SCORE_ON_KILL);
    }
}

void Warrior::takeDamage(int amount)
{
    if (shieldActive)
    {
        amount = amount * shieldEffectiveness;
        shieldActive = false;
    }

    health -= amount;
    std::cout << name << "> took " << amount << " damage [" << health << "]" << '\n';

    if (health < HEALTH_DEATH_THRESHOLD)
    {
        dead = true;
        shieldActive = false;
    }
}

void Warrior::specialAbility()
{

    std::cout << name << "> is guarding" << '\n';
    shieldActive = true;
}

Mage::Mage(std::string name) : Player(MAGE_INIT_HP, name)
{
}

void Mage::attackEnemy(Enemy &enemy)
{
    if (!enemy.isAlive())
        return;

    if (mana >= manaCostFireball)
    {
        mana -= manaCostFireball;
        std::cout << name << "> used fireball" << '\n';
        enemy.takeDamage(attackDamageFireball);
    }
    else
    {
        std::cout << name << "> used his stick to attack" << '\n';
        enemy.takeDamage(attackDamageStick);
    }

    // if killed
    if (!enemy.isAlive())
    {
        addScore(SCORE_ON_KILL);
    }
}

void Mage::specialAbility()
{
    if (health < MAGE_SP_HEALTH_THRESHOLD)
    {
        std::cout << name << "> insufficent amount of health for a teleport" << '\n';
    }
    std::cout << name << "> teleporting..." << '\n';
}

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
    std::cout << name << "> too weak to use the horn." << '\n';
}

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
    std::cout << name << "> used regeneration, now has " << health<< " health" << '\n';
}
