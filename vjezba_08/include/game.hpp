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

#include "game_character.hpp"

#endif