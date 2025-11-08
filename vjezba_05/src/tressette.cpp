#include "tressette.hpp"
#include <vector>

Deck::Deck() {
  std::vector<Suit> suits = {Suit::Hearts, Suit::Diamonds, Suit::Clubs,
                             Suit::Spades};
  for (Suit &suit : suits) {
    for (unsigned short i = 0; i <= 7; i++) {
      this->cards.at(i) = {i, suit};
    }
  }
}
