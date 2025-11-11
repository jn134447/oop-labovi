// #include <iostream>
#include "tressette.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  Tressette game(Mode::oneVersusOne);

  game.deck.shuffle_cards();
  game.deck.deal_cards(game.players);

  auto hand_cmp = [](Card &card_1, Card &card_2) {
    return card_1.number < card_2.number;
  };
  std::sort(game.players.at(PLAYER_ONE).hand.begin(),
            game.players.at(PLAYER_ONE).hand.end(), hand_cmp);
  // printing shit
  std::cout << "player one:";
  for (Card &card : game.players.at(PLAYER_ONE).hand) {
    std::cout << card.number;
    switch (card.suit) {
    case Suit::Clubs:
      std::cout << "C" << " ";
      break;
    case Suit::Hearts:
      std::cout << "H" << " ";
      break;
    case Suit::Spades:
      std::cout << "S" << " ";
      break;
    case Suit::Diamonds:
      std::cout << "D" << " ";
      break;
    }
  }
  std::cout << std::endl;
  std::cout << "player two:";
  for (Card &card : game.players.at(PLAYER_TWO).hand) {
    std::cout << card.number;
    switch (card.suit) {
    case Suit::Clubs:
      std::cout << "C" << " ";
      break;
    case Suit::Hearts:
      std::cout << "H" << " ";
      break;
    case Suit::Spades:
      std::cout << "S" << " ";
      break;
    case Suit::Diamonds:
      std::cout << "D" << " ";
      break;
    }
  }
  std::cout << std::endl;
}
