#include "tressette.hpp"

#include <algorithm>
#include <array>
#include <iostream>
#include <random>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

Deck::Deck()
{
  std::array<Suit, 4> suits = {
    Suit::Hearts, Suit::Diamonds, Suit::Clubs, Suit::Spades
  };

  cards.reserve(DECK_SIZE);

  for (Suit& suit : suits) {
    // cards go from 1 to 7, then from 11 to 13 (knave, knight, king)
    for (unsigned short i = 1; i <= 7; i++) {
      this->cards.push_back({ i, suit });
    }
    for (unsigned short i = 11; i <= 13; i++) {
      this->cards.push_back({ i, suit });
    }
  }
}

void
Deck::shuffle_cards()
{
  // https://en.cppreference.com/w/cpp/algorithm/random_shuffle.html
  std::random_device rd;
  std::mt19937 g(rd());

  std::shuffle(this->cards.begin(), this->cards.end(), g);
}

void
Deck::deal_cards(std::vector<Player>& players)
{
  if (players.size() != TWO_PLAYERS && players.size() != FOUR_PLAYERS) {
    throw std::invalid_argument("Invalid amount of players");
  }

  for (Player& player : players) {
    player.hand.clear();
    player.hand.resize(HAND_SIZE);

    std::copy(this->cards.begin(),
              this->cards.begin() + HAND_SIZE,
              player.hand.begin());
    this->cards.erase(this->cards.begin(), this->cards.begin() + HAND_SIZE);

    // WARN: REMOVE DEBUG HANDS
    player.hand = { { 1, Suit::Clubs },    { 1, Suit::Hearts },
                    { 1, Suit::Diamonds }, { 1, Suit::Spades },
                    { 2, Suit::Clubs },    { 2, Suit::Hearts },
                    { 2, Suit::Diamonds }, { 2, Suit::Clubs },
                    { 11, Suit::Clubs },   { 13, Suit::Clubs } };

    player.calculate_special_points();
  }
}

Player::Player(std::string name)
{
  this->name = name;
  this->hand.reserve(HAND_SIZE);
  this->points = ZERO_POINTS;
}

void
Player::show_hand()
{
  for (Card& card : hand) {
    std::cout << card.to_string() << " ";
  }
}

void
Player::calculate_special_points()
{
  points = napoli_points() + multi_of_kind_points();
}

unsigned short
Player::napoli_points()
{
  auto by_card_numbers = [](Card& card_1, Card& card_2) {
    return card_1.number < card_2.number;
  };
  std::sort(hand.begin(), hand.end(), by_card_numbers);

  std::unordered_map<Suit, std::vector<unsigned short>> cards_by_suit;
  for (Card& card : hand) {
    cards_by_suit[card.suit].push_back(card.number);
  }

  for (auto& [suit, numbers] : cards_by_suit) {
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

unsigned short
Player::multi_of_kind_points()
{
  unsigned short points = ZERO_POINTS;

  for (unsigned short number : { 1, 2, 3 }) {
    int count =
      std::count_if(hand.begin(), hand.end(), [&number](const Card& c) {
        return c.number == number;
      });
    if (count == 4)
      points += FOUR_OF_A_KIND_POINTS;
    else if (count == 3)
      points += THREE_OF_A_KIND_POINTS;
  }

  return points;
}

void
Tressette::set_mode(Mode mode)
{
  if (mode != Mode::oneVersusOne && mode != Mode::twoVersusTwo) {
    throw std::invalid_argument("Invalid game mode selected");
  }

  this->mode = mode;
}

void
Tressette::set_players(std::vector<std::string> names)
{
  if (names.size() != TWO_PLAYERS && names.size() != FOUR_PLAYERS) {
    throw std::invalid_argument("Invalid amount of names given for players");
  }

  names.reserve(names.size());
  for (std::string name : names) {
    players.emplace_back(name);
  }
}

void
Tressette::print_mode()
{
  std::cout << "mode: ";
  switch (mode) {
    case Mode::oneVersusOne:
      std::cout << "oneVersusOne";
      break;
    case Mode::twoVersusTwo:
      std::cout << "twoVersusTwo";
      break;
  }
}

void
Tressette::print_players_info()
{
  for (Player& player : players) {
    std::cout << player.name << " info: " << std::endl;

    std::cout << "\thand: ";
    player.show_hand();

    std::cout << std::endl;

    std::cout << "\tpoints: " << player.points;

    std::cout << std::endl;
  }
}

void
Tressette::print_deck_contents()
{
  std::cout << "current cards in deck: ";

  if (deck.cards.empty()) {
    std::cout << "empty";
    return;
  }

  for (Card& card : deck.cards) {
    std::cout << card.to_string() << " ";
  }
}

void
Tressette::print_game_state()
{
  print_mode();
  std::cout << std::endl;

  print_players_info();
  std::cout << std::endl;

  print_deck_contents();
  std::cout << std::endl;
}

std::string
Card::to_string()
{
  std::string number_string = std::to_string(number);
  std::string suit_str;

  switch (suit) {
    case Suit::Clubs:
      suit_str = "C";
      break;
    case Suit::Hearts:
      suit_str = "H";
      break;
    case Suit::Spades:
      suit_str = "S";
      break;
    case Suit::Diamonds:
      suit_str = "D";
      break;
  }

  return (number_string + suit_str);
}
