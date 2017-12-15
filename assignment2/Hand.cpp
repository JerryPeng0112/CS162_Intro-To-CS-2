#include "./Hand.h"

Hand::Hand(){
    num_cards = 2;
    cards = new Card [2];
}

int Hand::get_num_cards() const{
    return num_cards;
}

Card* Hand::get_cards_pointer() const{
    return cards;
}

void Hand::set_num_cards(const int num_cards){
    this->num_cards = num_cards;
}

void Hand::add_card(Deck &deck){
    Card *temp;
    temp = new Card [num_cards + 1];
    for(int i = 0; i < num_cards; i++){
        temp[i] = cards[i];
    }
    delete[] cards;
    cards = temp;
    cards[num_cards] = deck.deal_card();
    num_cards++;
}

void Hand::print_hand(){
    for(int i = 0; i < num_cards; i++){
        cards[i].print_card();
    }
}

Hand::Hand(const Hand &obj){
    num_cards = obj.num_cards;
    cards = new Card [obj.num_cards];
    for(int i = 0; i < num_cards; i++){
        cards[i] = obj.cards[i];
    }
}

void Hand::operator =(const Hand &obj){
    delete [] cards;
    num_cards = obj.num_cards;
    cards = new Card [obj.num_cards];
    for(int i = 0; i < num_cards; i++){
        cards[i] = obj.cards[i];
    }
}

Hand::~Hand(){
    delete [] cards;
}
