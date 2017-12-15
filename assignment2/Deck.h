#pragma once
#include <iostream>
#include <cstdlib>
#include "./Card.h"

class Deck{
private:
    Card cards[52]; // 52 cards
    int num_cards; // index for the card drawn

public:
    Deck(); // Constructor, create deck
    int get_num_cards() const; // Accessor, USELESS
    Card deal_card(); // Mutator, take top card and return it
    void reset(); // Reset the num_cards index
    void shuffle(); // Shuffle the deck
    void print_deck(); // Print the deck
};
