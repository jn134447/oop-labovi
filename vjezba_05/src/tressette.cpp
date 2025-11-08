#include "tressette.hpp"

Deck::Deck() {
  std::array<Suit, 4> suits = {Suit::Hearts, Suit::Diamonds, Suit::Clubs,
                               Suit::Spades};
  int deck_iter = 0;
  for (Suit &suit : suits) {
    // cards go from 1 to 7, then from 11 to 13 (knave, knight, king)
    for (unsigned short i = 1; i <= 7; i++) {
      this->cards.at(deck_iter++) = {i, suit};
    }
    for (unsigned short i = 11; i <= 13; i++) {
      this->cards.at(deck_iter++) = {i, suit};
    }
  }
}
