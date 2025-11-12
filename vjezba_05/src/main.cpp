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
  std::cin >> user_mode;
  // user_mode = 2;

  if (user_mode == 2)
    mode = Mode::oneVersusOne;
  else if (user_mode == 4)
    mode = Mode::twoVersusTwo;
  else {
    std::cout << "wrong mode selected, aborting..." << std::endl;
    return 1;
  }

  std::vector<std::string> names;
  std::cin.ignore();

  for (int i = 0; i < user_mode; i++) {
    std::string name;
    std::cout << "Enter name for player " << (i + 1) << ": ";
    std::getline(std::cin, name);
    names.push_back(name);
  }

  game.set_mode(mode);
  game.set_players(names);

  game.deck.shuffle_cards();
  game.deck.deal_cards(game.players);

  game.calculate_all_player_bonuses();

  game.print_game_state();
}
