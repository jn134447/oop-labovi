#include "zoo_keeper.hpp"

int ZooKeeper::total_animals_served = 0;
int ZooKeeper::total_food_usage = 0;

void ZooKeeper::processAnimal(Animal *animal)
{
    std::cout << "Species: " << animal->getSpecies() << ", "
              << "Name: " << animal->getName() << ", "
              << "Food: " << animal->getDailyFood() << "kg"
              << '\n';

    total_animals_served += 1;
    total_food_usage += animal->getDailyFood();
}

int ZooKeeper::getTotalAnimalsServed() { return total_animals_served; }
int ZooKeeper::getTotalFoodUsage() { return total_food_usage; }
