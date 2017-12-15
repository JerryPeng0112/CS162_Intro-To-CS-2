#pragma once
#include <iostream>
#include <cstdlib>
#include "./Card.h"
#include "./Deck.h"
#include "./Hand.h"
#include "./Dealer.h"
#include "./Player.h"

static std::string const player_taunt[3] = {
    "You suck, I'll take all your money",
    "I think you have some tricks up your sleeves, you dirty cheater !",
    "After I win all the money, I ain't tipping you.",
};
static std::string const dealer_counter_1[3] = {
    "I don't think you have the balls to do it.",
    "I think your brain is a puddle of mustard, full of junk.",
    "I don't expect the tip from a loser."
};
static std::string const dealer_counter_2[1] = {
    "I think you are 1 inch over the line, now BACK OFF !"
};
static std::string const dealer_counter_3[1] = {
    "Stop your dirty mouth before It's Too Late !"
};

class Game{
private:
    int init_money;
    Deck cards;
    Player *players;
    Dealer game_dealer;
    int num_players;
public:
    Game(); // Constructor
    int get_player(); // Get number of player
    int get_money(); // Get amount of initial money
    bool check_quit(); // Check if able to quit
    std::string get_name(int); // Get name for player
    void run_game(); // Run the game
    void round(); // Run each round
    void bet(); // Set bet
    void deal(); // Deal the card
    void print_deal_stat(); // Print the stat for all players
    void user_choice(); // Let user decide
    int get_user_choice(const int, const int, bool []); // Get the right output and user choice
    int var_choice(bool[], const int); //
    void hit(const int, const int, const bool); // User hit
    void split(const int); // User split
    int total_bet(const int); // Get total bet for split
    int get_split_user_choice(const bool); // Check for user split option
    void double_down(const int, const int); // User double down
    void taunt(const int); // User taunt dealer
    void deal_dealer(); // Deal card to dealer
    void calculate_money(); // Calculate money
    void print_result(); // Print the result
    void print_status(const int); // Print the status of the hands
    void reset_round(); // reset
    void clear_screen() const; // Clear screen
    void clear_line() const; // Create a clear line
    void player_banner(const int i) const;
    int get_num(); // Get number
    bool check_num(std::string); // Check if all characters are numbers
    Deck get_deck() const; // Accessor cards
    Player* get_players_pointer() const; // Accessor players
    Dealer get_dealer() const; // Accessor game_dealer
    int get_num_players() const; // Accessor num_players
    Game(const Game&); // Copy Constructor
    void operator =(const Game&); // Assignment overload
    ~Game(); // Destructor
};
