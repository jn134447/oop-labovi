#include "tressette.hpp"
#include <iostream>
#include <string>
#include <vector>

int
main()
{
  Tressette game;

  unsigned short user_mode;
  Mode mode;
  std::cout << "unesite broj igraca (game mode) [2 or 4]: ";
  // std::cin >> user_mode;
  user_mode = 4;

  if (user_mode == 2)
    mode = Mode::oneVersusOne;
  else if (user_mode == 4)
    mode = Mode::twoVersusTwo;
  else {
    std::cout << "wrong mode selected, aborting..." << std::endl;
    return 1;
  }

  std::vector<std::string> names{
    "player one", "player two", "ante", "vukodlak"
  };
  game.set_mode(mode);
  game.set_players(names);

  game.deck.shuffle_cards();
  game.deck.deal_cards(game.players);

  // printing shit
  game.print_game_state();
}
