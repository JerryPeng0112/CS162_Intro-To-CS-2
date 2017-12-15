#include "./Dealer.h"

Dealer::Dealer(){
    name = "Dealer";
    card_total = 0;
}

std::string Dealer::get_name() const{
    return name;
}

Hand* Dealer::get_d_hand(){
    return &d_hand;
}

int Dealer::get_card_total() const{
    return card_total;
}

void Dealer::set_card_total(){
    int ace_count = 0;
    card_total = 0;
    for(int i = 0; i < d_hand.get_num_cards(); i++){
        if(d_hand.get_cards_pointer()[i].get_value() == 1){
            ace_count++;
        }
    }
    for(int i = 0; i < d_hand.get_num_cards(); i++){
        card_total += get_card_value(d_hand.get_cards_pointer()[i].get_value());
    }
    for(int i = 0; i < ace_count; i++){
        if(ace_count != 0 && card_total > 21){
            ace_count--;
            card_total -= 10;
        }
    }
}

int Dealer::get_card_value(const int value) const{
    if(value == 1){
        return 11;
    }
    if(value >= 11 && value <= 13){
        return 10;
    }else{
        return value;
    }
}

void Dealer::print_dealer(const bool hidden){
    std::cout << "Dealer: ";
    if(hidden){
        d_hand.get_cards_pointer()[0].print_card();
        std::cout << " Hidden" << std::endl;
    }
    if(!hidden){
        d_hand.print_hand();
        std::cout << " Total: " << card_total << std::endl;
        if(card_total == 21){
            std::cout << "Dealer has a blackjack !!!" << std::endl;
        }else if(card_total > 21){
            std::cout << "Dealer: BUST !!!" << std::endl;
        }
    }
}

void Dealer::reset(){
    d_hand = Hand();
}

Dealer::Dealer(const Dealer &obj){
    name = obj.name;
    d_hand = obj.d_hand;
    card_total = obj.card_total;
}

void Dealer::operator =(const Dealer &obj){
    name = obj.name;
    d_hand = obj.d_hand;
    card_total = obj.card_total;
}

Dealer::~Dealer(){}
