#ifndef ZOO_KEEPER_H
#define ZOO_KEEPER_H

#include "animals.hpp"

class ZooKeeper
{
private:
    static int total_animals_served;
    static int total_food_usage;

public:
    void processAnimal(Animal *animal);
    static int getTotalAnimalsServed();
    static int getTotalFoodUsage();
};

#endif