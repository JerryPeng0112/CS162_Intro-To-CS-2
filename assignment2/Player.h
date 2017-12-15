#pragma once
#include <iostream>
#include <string>
#include "./Hand.h"
#include "./Deck.h"

class Player{
private:
    std::string name;
    Hand *p_hand;
    int hand_total;
    int playing_total;
    int taunt;
    int *card_total;
    int *bet;
public:
    Player();// Default Constructor
    Player(const int); // Constructor
    int get_taunt(); // Accessor
    void reduce_taunt(); // Mutator
    std::string get_name() const; // Accessor name
    Hand* get_p_hand() const; // Accesoor p_hand
    int get_hand_total() const; // Accessor hand_total
    int get_playing_total() const; // Accessor playing_total
    int* get_card_total() const; // Accessor card_total
    int* get_bet() const; // Accessor bet
    void set_name(const std::string); // Mutator name
    void split(Deck&); // Mutator split
    void set_card_total(); // Mutator card_total
    int get_card_value(const int); // convert value of card
    void set_bet(const int); // Mutator bet
    void zero_playing_total(); // Mutator playing_total
    void start_playing_total(const int); // Mutator playing_total
    void set_playing_total(const int); // Mutator playing_total
    void compare(const int, const int, const int); // Compare the cards and dealer
    void reset();
    void print_player(const int); // Print player cards info
    void print_player_split(const int); // Print player cards after split
    Player(const Player&); // Copy Constructor
    void operator =(const Player&); // Assignment overload
    ~Player(); // Destructor
};
