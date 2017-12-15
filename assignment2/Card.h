#pragma once
#include <iostream>

static const char Suit[4][8] = {"Spade", "Heart", "Diamond", "Club"};

class Card{
private:
    int value;
    char* suit;
public:
    Card(); // Default Constructor
    Card(const int, const int); // Constructor
    int get_value() const; // Accessor value
    char* get_suit() const; // Accessor suit
    void set_card(const int, const int); // Mutator
    void print_card(); // Print the card
    Card(const Card&); // Copy constructor
    void operator =(const Card&); // Assignment op overload
    ~Card();
};
