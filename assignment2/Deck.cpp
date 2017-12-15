#include "./Deck.h"
Deck::Deck(){
    for(int i = 1; i <= 13; i++){
        for(int j = 0; j < 4; j++)
        cards[(i - 1) * 4 + j].set_card(i, j);
    }
    num_cards = 0;
}

int Deck::get_num_cards() const{
    return num_cards;
}

Card Deck::deal_card(){
    return cards[num_cards++];
}

void Deck::reset(){
    this->shuffle();
    num_cards = 0;
}

void Deck::shuffle(){
    int random;
    Card temp;
    for(int i = 0; i < 7; i++){
        for(int i = 51; i > 0; i--){
            random = rand() % i;
            temp = cards[i];
            cards[i] = cards[random];
            cards[random] = temp;
        }
    }
}

void Deck::print_deck(){
    for(int i = 0; i < 52; i++){
        cards[i].print_card();
    }
    std::cout << std::endl;
}
