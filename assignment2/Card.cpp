#include "./Card.h"

Card::Card(){}

Card::Card(const int value, const int suit_val){
    this->value = value;
    this->suit = (char*) Suit[suit_val];
}

int Card::get_value() const{
    return value;
}

char* Card::get_suit() const{
    return suit;
}

void Card::set_card(const int value, const int suit_val){
    this->value = value;
    this->suit = (char*) Suit[suit_val];
}

void Card::print_card(){
    switch(value){
        case 1:
            std::cout << "Ace";
            break;
        case 11:
            std::cout << "Jack";
            break;
        case 12:
            std::cout << "Queen";
            break;
        case 13:
            std::cout << "King";
    }
    if(value >= 2 && value <= 10){
        std::cout << value;
    }
    std::cout << "-" << suit << " ";
}

Card::Card(const Card &obj){
    value = obj.value;
    suit = obj.suit;
}

void Card::operator =(const Card &obj){
    value = obj.value;
    suit = obj.suit;
}

Card::~Card(){}
