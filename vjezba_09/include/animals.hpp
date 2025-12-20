#ifndef ANIMALS_H
#define ANIMALS_H

#include <string>
#include <stdexcept>
#include <iostream>

// Abstract
class Animal
{

protected:
    std::string name;
    std::string species;
    int age;
    double weight;
    double daily_intake_percentage;

    Animal(std::string name,
           int age,
           double weight,
           std::string species,
           double daily_intake_percentage = 1);

public:
    std::string getSpecies() const;
    double getDailyFood() const;
    std::string getName() const;
    virtual ~Animal() = default;
};
class Mammal;
class Aquatic;

class Mammal : virtual public Animal
{
public:
    bool hasFur() const;

protected:
    bool has_fur;

    Mammal(std::string name,
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
    Aquatic(std::string name,
            int age,
            double weight,
            std::string species,
            double max_dive_depth);
};

class Lion : public Mammal
{
public:
    Lion(std::string name,
         int age,
         double weight);
};
class Elephant : public Mammal
{
public:
    Elephant(std::string name,
             int age,
             double weight);
};

class Dolphin : public Mammal, public Aquatic
{
public:
    Dolphin(std::string name,
            int age,
            double weight);
};

class SeaTurtle : public Aquatic
{
public:
    SeaTurtle(std::string name,
              int age,
              double weight);
};

#endif