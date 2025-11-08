#ifndef TRESSETTE
#define TRESSETTE

#include <array>
#include <string>
#include <vector>

#define HAND_SIZE 10
#define DECK_SIZE 40

enum class Suit { Hearts, Diamonds, Clubs, Spades };

enum class Mode { oneVersusOne = 2, twoVersusTwo = 4 };

class Card {
public:
  unsigned short number;
  Suit suit;
};

class Player {
  std::string name;
  std::array<Card, HAND_SIZE> hand;
  unsigned short points;

  unsigned short acquire_special_points();
};

class Deck {
  std::array<Card, DECK_SIZE> cards;

public:
  Deck();
  void shuffle_cards();
  void deal_cards();
};

class Game {
  Mode mode;
  std::vector<Player> players;
  Deck deck;

  void pick_mode();
};

#endif
