#ifndef TRESSETTE
#define TRESSETTE

#include <string>
#include <vector>

#define HAND_SIZE 10
#define DECK_SIZE 40

#define TWO_PLAYERS 2
#define FOUR_PLAYERS 4

#define PLAYER_ONE 0
#define PLAYER_TWO 1
#define PLAYER_THREE 2
#define PLAYER_FOUR 3

// #define DEFAULT_PLAYER_NAME "default_name"
#define DEFAULT_PLAYER_POINTS 0

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
