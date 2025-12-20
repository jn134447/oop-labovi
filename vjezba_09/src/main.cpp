#include "animals.hpp"
#include "zoo_keeper.hpp"
#include "zoo_section.hpp"

int main()
{
    ZooSection<Animal> section;
    ZooKeeper keeper;

    section.addAnimal(std::make_unique<Lion>("Clove", 4, 85));
    section.addAnimal(std::make_unique<Elephant>("Fluff", 9, 1000));
    section.addAnimal(std::make_unique<Dolphin>("Dayver", 3, 40));
    section.addAnimal(std::make_unique<SeaTurtle>("Shelly", 1, 8));

    // std::cout << section.getAnimal(2)->getName();
    for (std::size_t i = 0; i < section.size(); i++)
    {
        keeper.processAnimal(section.getAnimal(i));
    }
    std::cout << "\n\n"
              << "Broj nahranjenih zivotinja: " << keeper.getTotalAnimalsServed() << '\n';
    std::cout << "Broj ukupne hrane potrosene: " << keeper.getTotalFoodUsage() << '\n';
}