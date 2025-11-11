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

constexpr unsigned short ZERO_POINTS = 0;
constexpr unsigned short NAPOLI_POINTS = 3;
constexpr unsigned short THREE_OF_A_KIND_POINTS = 3;
constexpr unsigned short FOUR_OF_A_KIND_POINTS = 4;

// Hearts → Cuori (Italian) / Copas (Spanish)
// Diamonds → Denari (Italian) / Oros (Spanish)
// Clubs → Bastoni (Italian) / Bastos (Spanish)
// Spades → Spade (Italian) / Espadas (Spanish)
enum class Suit
{
    Hearts,
    Diamonds,
    Clubs,
    Spades
};

enum class Mode
{
    oneVersusOne,
    twoVersusTwo
};

class Card
{
  public:
    unsigned short number;
    Suit suit;
    std::string to_string();
};

class Player
{
    unsigned short napoli_points();
    unsigned short multi_of_kind_points();

  public:
    std::vector<Card> hand;
    std::string name;
    unsigned short points;

    Player(std::string);
    void show_hand();
    void calculate_special_points();
};

class Deck
{
  public:
    std::vector<Card> cards;
    Deck();
    void shuffle_cards();
    void deal_cards(std::vector<Player> &);
};

class Tressette
{
  public:
    Mode mode;
    std::vector<Player> players;
    Tressette(Mode);
    Deck deck;
    void print_game_state();
    void print_players_info();
    void print_mode();
    void print_deck_contents();
};

#endif
