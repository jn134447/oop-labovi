#include "game.hpp"

#include <memory>
#include <vector>
/*
Implementirajte sve navedene klase s odgovarajućim konstuktorima i
destruktorima. U main funkciji · Kreirajte sljedeće likove: Conan (Warrior),
Merlin (Mage), Gnomeo (Gnome), Sneaky (Gnome), Dragon (Boss) i spremite ih u
vektor pointera na GameCharacter.

    · Simulirajte borbu (Conan napada Gnomea, Merlin napada Sneakyja, Gnomeo
napada Co- nana, Merlin napada Gnomea, Dragon napada Merlina, Merlin napada
Gnomea, Conan napada Dragona, Merlin napada Dragona). Nakon svakog napada
ispišite status oba lika.

    · Pozovite specialAbility za sve likove iz vektora.

    · Ispišite status svih preživjelih likova i ime lika sa najviše zdravlja.
*/

constexpr unsigned short CONAN = 0;
constexpr unsigned short MERLIN = 1;
constexpr unsigned short GNOMEO = 2;
constexpr unsigned short SNEAKY = 3;
constexpr unsigned short DRAGON = 4;

int main()
{

    // std::unique_ptr<GameCharacter> conan =  std::make_unique<Warrior>("Conan");
    // std::unique_ptr<GameCharacter> merlin = std::make_unique<Mage>("Merlin");
    // std::unique_ptr<GameCharacter> gnomeo = std::make_unique<Gnome>("Gnomeo");
    // std::unique_ptr<GameCharacter> sneaky = std::make_unique<Gnome>("Sneaky");
    // std::unique_ptr<GameCharacter> dragon = std::make_unique<Boss>("Dragon");

    std::vector<std::unique_ptr<GameCharacter>> entities;

    entities.emplace_back(std::make_unique<Warrior>("Conan"));
    entities.emplace_back(std::make_unique<Mage>("Merlin"));
    entities.emplace_back(std::make_unique<Gnome>("Gnomeo"));
    entities.emplace_back(std::make_unique<Gnome>("Sneaky"));
    entities.emplace_back(std::make_unique<Boss>("Dragon"));

    // GameCharacter is expected to call attackEnemy and attackPlayer 
    // even when it dosent have those functions?????????
    // this exercise contradicts itself 
    entities.at(CONAN).get()->attackEnemy(entities.at(GNOMEO));
}
