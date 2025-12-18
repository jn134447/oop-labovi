#include "game.hpp"

#include <vector>
#include <memory>

int main()
{
    std::vector<std::unique_ptr<GameCharacter>> entities{
        std::make_unique<Warrior>("Conan"),
        std::make_unique<Mage>("Merlin"),
        std::make_unique<Gnome>("Gnomeo"),
        std::make_unique<Gnome>("Sneaky"),
        std::make_unique<Boss>("Dragon")};

    for (std::unique_ptr<GameCharacter>& entity: entities)
    {   
        entity.get()->displayStatus();
    }
    
}
