#pragma once
#include <iostream>
#include "./Card.h"
#include "./Deck.h"
class Hand{
private:
    Card *cards;
    int num_cards;
public:
    Hand(); // Constructor, also create array
    int get_num_cards() const; // Accessor num_cards
    Card* get_cards_pointer() const; // Accessor cards pointer
    void set_num_cards(const int); // Mutator num_cards
    void add_card(Deck&); // Player hit
    void print_hand(); // Print hand
    Hand(const Hand&); // Copy Constructor
    void operator =(const Hand&); // Assignment overload
    ~Hand(); // Destructor
};
