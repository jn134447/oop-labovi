#include "tressette.hpp"

#include <algorithm>
#include <array>
#include <cstddef>
#include <random>
#include <stdexcept>
#include <string>
#include <unordered_map>
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

    // WARN: REMOVE DEBUG HANDS
    player.hand.at(1) = {1, Suit::Clubs};
    player.hand.at(2) = {1, Suit::Hearts};
    player.hand.at(3) = {2, Suit::Clubs};
    player.hand.at(4) = {2, Suit::Hearts};
    player.hand.at(5) = {3, Suit::Clubs};
    player.hand.at(6) = {3, Suit::Hearts};

    player.calculate_special_points();
  }
}

Player::Player(std::string name) {
  this->name = name;
  this->hand.reserve(HAND_SIZE);
  this->points = ZERO_POINTS;
}

void Player::calculate_special_points() {
  points = napoli_points() + multi_of_kind_points();
}

unsigned short Player::napoli_points() {
  auto by_card_numbers = [](Card &card_1, Card &card_2) {
    return card_1.number < card_2.number;
  };
  std::sort(hand.begin(), hand.end(), by_card_numbers);

  std::unordered_map<Suit, std::vector<unsigned short>> cards_by_suit;
  for (Card &card : hand) {
    cards_by_suit[card.suit].push_back(card.number);
  }

  for (auto &[suit, numbers] : cards_by_suit) {
    bool has_ace = false, has_two = false, has_three = false;

    for (unsigned short number : numbers) {
      if (number == 1)
        has_ace = true;
      else if (number == 2)
        has_two = true;
      else if (number == 3)
        has_three = true;
    }

    if (has_ace && has_two && has_three) {
      return NAPOLI_POINTS;
    }
  }

  return ZERO_POINTS;
}

unsigned short Player::multi_of_kind_points() {
  //
  return FOUR_OF_A_KIND_POINTS;
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
