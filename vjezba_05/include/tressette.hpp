#ifndef TRESSETTE
#define TRESSETTE

#include <string>
#include <vector>

constexpr unsigned short HAND_SIZE = 10;
constexpr unsigned short DECK_SIZE = 40;

constexpr unsigned short TWO_PLAYERS = 2;
constexpr unsigned short FOUR_PLAYERS = 4;

constexpr unsigned short PLAYER_ONE = 0;
constexpr unsigned short PLAYER_TWO = 1;
constexpr unsigned short PLAYER_THREE = 2;
constexpr unsigned short PLAYER_FOUR = 3;

constexpr unsigned short DEFAULT_PLAYER_POINTS = 0;
constexpr unsigned short NAPOLI_POINTS = 0;
constexpr unsigned short THREE_OF_A_KIND_POINTS = 0;
constexpr unsigned short FOUR_OF_A_KIND_POINTS = 0;

enum class Suit { Hearts, Diamonds, Clubs, Spades };

enum class Mode { oneVersusOne, twoVersusTwo };

class Card {
public:
  unsigned short number;
  Suit suit;
};

class Player {

public:
  std::vector<Card> hand;
  Player(std::string);
  std::string name;
  unsigned short points;

  unsigned short acquire_special_points();
};

class Deck {
  std::vector<Card> cards;

public:
  Deck();
  void shuffle_cards();
  void deal_cards(std::vector<Player> &);
};

class Tressette {
public:
  std::vector<Player> players;
  Tressette(Mode);
  Deck deck;
};

#endif
