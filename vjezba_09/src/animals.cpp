#include "animals.hpp"

std::string Animal::getSpecies() const { return species; }
double Animal::getDailyFood() const { return daily_food_weight; }
std::string Animal::getName() const { return name; }

Animal::Animal(std::string name,
               int years,
               double daily_food_weight,
               std::string species)
    : name(name),
      years(years),
      daily_food_weight(daily_food_weight),
      species(species)
{
    if (this->name.empty())
        throw std::invalid_argument("Name is empty");
    if (this->years < 0)
        throw std::invalid_argument("Animal years cant be negative");
    if (this->daily_food_weight < 0)
        throw std::invalid_argument("Food of weight cant be negative");
}

bool Mammal::hasFur() const { return has_fur; }

Mammal::Mammal(std::string name,
               int years,
               double daily_food_weight,
               std::string species,
               bool has_fur)
try
    : Animal(name, years, daily_food_weight, species),
      has_fur(has_fur)

{ // ctor
    if (this->has_fur)
        std::cout << "Stvoren sisavac s dlakom" << '\n';
    else
        std::cout << "Stvoren sisavac s malo dlake" << '\n';
}

catch (const std::invalid_argument &e)
{
    throw std::runtime_error("Failed to init Mammal()");
}

Aquatic::Aquatic(std::string name,
                 int years,
                 double daily_food_weight,
                 std::string species,
                 double max_dive_depth)
try
    : Animal(name, years, daily_food_weight, species),
      max_dive_depth(max_dive_depth)

{ // ctor
    std::cout << "Stvorena vodena životinja koja roni do " << max_dive_depth << "m" << '\n';
}

catch (const std::invalid_argument &e)
{
    throw std::runtime_error("Failed to init Aquatic()");
}
