#pragma once
#include <iostream>
#include <string>
#include "./Hand.h"

class Dealer{
private:
    std::string name;
    Hand d_hand;
    int card_total;
public:
    Dealer(); // Constructor
    std::string get_name() const; //Accessor name
    Hand* get_d_hand(); // Accessor d_hand
    int get_card_total() const; // Accessor card_total
    void set_card_total(); // Mutator card_total
    int get_card_value(const int) const; // Return the real value of cards
    void print_dealer(const bool); // print the dealer
    void reset(); // reset the dealer cards
    Dealer(const Dealer&); // Copy Constructor
    void operator =(const Dealer&); // Assignment overload
    ~Dealer(); // Destructor
};
