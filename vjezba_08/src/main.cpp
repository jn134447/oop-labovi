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

    std::vector<std::unique_ptr<GameCharacter>> entities;

    entities.emplace_back(std::make_unique<Warrior>("Conan"));
    entities.emplace_back(std::make_unique<Mage>("Merlin"));
    entities.emplace_back(std::make_unique<Gnome>("Gnomeo"));
    entities.emplace_back(std::make_unique<Gnome>("Sneaky"));
    entities.emplace_back(std::make_unique<Boss>("Dragon"));

    // gameplay time!!!
    auto info_about_both = [&entities](int a, int b)
    {
        entities.at(a).get()->displayStatus();
        entities.at(b).get()->displayStatus();
    };
    auto attack_another_with_info = [&entities, info_about_both](int a, int b)
    {
        entities.at(a).get()->attack(*entities.at(b).get());
        info_about_both(a, b);
        std::cout << '\n';
    };

    /*
    Conan napada Gnomea,
    Merlin napada Sneakyja,
    Gnomeo napada Conana,
    Merlin napada Gnomea,
    Dragon napada Merlina,
    Merlin napada Gnomea,
    Conan napada Dragona,
    Merlin napada Dragona).
    Nakon svakog napada ispišite status oba lika.
    */

    attack_another_with_info(CONAN, GNOMEO);
    attack_another_with_info(MERLIN, SNEAKY);
    attack_another_with_info(GNOMEO, CONAN);
    attack_another_with_info(MERLIN, GNOMEO);
    attack_another_with_info(DRAGON, MERLIN);
    attack_another_with_info(CONAN, DRAGON);
    attack_another_with_info(MERLIN, DRAGON);

    std::cout << '\n'
              << "everyone is using a special ability!" << "\n\n";
    for (auto &entity : entities)
        entity.get()->useSpecialAbility();

    std::cout << '\n'
              << "fight is over, displaying info about each character:" << "\n\n";
    for (auto &entity : entities)
        entity.get()->displayStatus();
}
