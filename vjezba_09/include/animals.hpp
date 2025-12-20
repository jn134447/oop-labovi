#ifndef ANIMALS_H
#define ANIMALS_H

#include <string>
#include <stdexcept>
#include <iostream>

// Abstract
class Animal
{
private:
    std::string name;
    int years;
    double daily_food_weight;
    std::string species;

protected:
    std::string getSpecies() const;
    double getDailyFood() const;
    std::string getName() const;

    Animal(std::string name,
           int years,
           double daily_food_weight,
           std::string species);
};
class Mammal;
class Aquatic;

class Mammal : public Animal
{
private:
    bool has_fur;

protected:
    bool hasFur() const;

    Mammal(
        std::string name,
        int years,
        double daily_food_weight,
        std::string species,
        bool has_fur);
};

class Aquatic : public Animal
{
private:
    double max_dive_depth;

protected:
    Aquatic(
        std::string name,
        int years,
        double daily_food_weight,
        std::string species,
        double max_dive_depth);
};

class Lion
{
};

class Dolphin
{
};

class SeaTurtle
{
};
#endif