#include "animals.hpp"

std::string Animal::getSpecies() const { return species; }

std::string Animal::getName() const { return name; }

Animal::Animal(std::string name,
               int age,
               double weight,
               std::string species)
    : name(name),
      age(age),
      weight(weight),
      species(species)
{
    if (this->name.empty())
        throw std::invalid_argument("Name is empty");
    if (this->age < 0)
        throw std::invalid_argument("Animal age cant be negative");
    if (this->weight < 0)
        throw std::invalid_argument("Food of weight cant be negative");
}

bool Mammal::hasFur() const { return has_fur; }

Mammal::Mammal(std::string name,
               int age,
               double weight,
               std::string species,
               bool has_fur)
try
    : Animal(name, age, weight, species),
      has_fur(has_fur)

{ // ctor
    if (this->has_fur)
        std::cout << "Stvoren sisavac s dlakom" << '\n';
    else
        std::cout << "Stvoren sisavac s malo dlake" << '\n';
}
catch (const std::invalid_argument &e)
{
    throw std::runtime_error(std::string("Failed to init Mammal(): ") + e.what());
}

Aquatic::Aquatic(std::string name,
                 int age,
                 double weight,
                 std::string species,
                 double max_dive_depth)
try
    : Animal(name, age, weight, species),
      max_dive_depth(max_dive_depth)

{ // ctor
    std::cout << "Stvorena vodena životinja koja roni do " << max_dive_depth << "m" << '\n';
}
catch (const std::invalid_argument &e)
{
    throw std::runtime_error(std::string("Failed to init Aquatic(): ") + e.what());
}

Lion::Lion(std::string name,
           int age,
           double weight)
try
    : Mammal(name, age, weight, "Lion", true)
{ // ctor
}
catch (const std::invalid_argument &e)
{
    throw std::runtime_error(std::string("Failed to init Lion(): ") + e.what());
}