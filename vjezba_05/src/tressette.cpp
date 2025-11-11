#include "tressette.hpp"

#include <algorithm>
#include <array>
#include <random>
#include <stdexcept>
#include <string>
#include <vector>

Deck::Deck() {
  std::array<Suit, 4> suits = {Suit::Hearts, Suit::Diamonds, Suit::Clubs,
                               Suit::Spades};

  cards.reserve(DECK_SIZE);

  for (Suit &suit : suits) {
    // cards go from 1 to 7, then from 11 to 13 (knave, knight, king)
    for (unsigned short i = 1; i <= 7; i++) {
      this->cards.push_back({i, suit});
    }
    for (unsigned short i = 11; i <= 13; i++) {
      this->cards.push_back({i, suit});
    }
  }
}

void Deck::shuffle_cards() {
  // https://en.cppreference.com/w/cpp/algorithm/random_shuffle.html
  std::random_device rd;
  std::mt19937 g(rd());

  std::shuffle(this->cards.begin(), this->cards.end(), g);
}

void Deck::deal_cards(std::vector<Player> &players) {
  if (players.size() != TWO_PLAYERS && players.size() != FOUR_PLAYERS) {
    throw std::invalid_argument("Invalid amount of players");
  }

  for (Player &player : players) {
    player.hand.clear();
    player.hand.resize(HAND_SIZE);

    std::copy(this->cards.begin(), this->cards.begin() + HAND_SIZE,
              player.hand.begin());
    this->cards.erase(this->cards.begin(), this->cards.begin() + HAND_SIZE);
  }
}

Player::Player(std::string name) {
  this->name = name;
  this->hand.reserve(HAND_SIZE);
  this->points = DEFAULT_PLAYER_POINTS;
}

Tressette::Tressette(Mode mode) {
  if (mode != Mode::oneVersusOne && mode != Mode::twoVersusTwo) {
    throw std::invalid_argument("Invalid game mode selected");
  }

  switch (mode) {
  case Mode::oneVersusOne:
    this->players.reserve(TWO_PLAYERS);
    this->players.emplace_back("player_one");
    this->players.emplace_back("player_two");
    break;
  case Mode::twoVersusTwo:
    this->players.reserve(FOUR_PLAYERS);
    this->players.emplace_back("player_one");
    this->players.emplace_back("player_two");
    this->players.emplace_back("player_three");
    this->players.emplace_back("player_four");
    break;
  }
}
