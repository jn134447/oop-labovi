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
    int age;
    double weight;
    std::string species;

protected:
    std::string getSpecies() const;
    virtual double getDailyFood() = 0;
    std::string getName() const;

    Animal(std::string name,
           int age,
           double weight,
           std::string species);
};
class Mammal;
class Aquatic;

class Mammal : virtual public Animal
{
protected:
    bool has_fur;
    bool hasFur() const;

    Mammal(
        std::string name,
        int age,
        double weight,
        std::string species,
        bool has_fur);
};

class Aquatic : virtual public Animal
{
private:
    double max_dive_depth;

protected:
    Aquatic(
        std::string name,
        int age,
        double weight,
        std::string species,
        double max_dive_depth);
};

class Lion : public Mammal
{
public:
    Lion(
        std::string name,
        int age,
        double weight);
};

class Dolphin
{
};

class SeaTurtle
{
};
#endif