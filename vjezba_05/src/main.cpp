#include "tressette.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    unsigned short user_mode;
    Mode mode;
    std::cout << "unesite broj igraca (game mode) [2 or 4]: ";
    std::cin >> user_mode;

    if (user_mode == 2)
        mode = Mode::oneVersusOne;
    else if (user_mode == 4)
        mode = Mode::twoVersusTwo;
    else
    {
        std::cout << "wrong mode selected, aborting..." << std::endl;
        return 1;
    }

    Tressette game(mode);

    game.deck.shuffle_cards();
    game.deck.deal_cards(game.players);

    // printing shit
    game.print_game_state();
}
