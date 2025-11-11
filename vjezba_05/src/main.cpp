#include "tressette.hpp"
#include <iostream>
#include <vector>

int main() {
  Tressette game(Mode::oneVersusOne);

  game.deck.shuffle_cards();
  game.deck.deal_cards(game.players);

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
  std::cout << "points: " << game.players.at(PLAYER_ONE).points;
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
  std::cout << "points: " << game.players.at(PLAYER_TWO).points;
  std::cout << std::endl;
}
