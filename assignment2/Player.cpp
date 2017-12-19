#include "Player.h"

Player::Player(){
    hand_total = 1;
    p_hand = new Hand [1];
    taunt = 3;
    card_total = new int [1];
    bet = new int [1];
    bet[0] = 0;
}

Player::Player(const int playing_total){
    hand_total = 1;
    p_hand = new Hand [1];
    card_total = new int [1];
    bet = new int [1];
    taunt = 3;
    bet[0] = 0;
    this->playing_total = playing_total;
}

int Player::get_taunt(){
    return taunt;
}

void Player::reduce_taunt(){
    taunt--;
}

std::string Player::get_name() const{
    return name;
}

Hand* Player::get_p_hand() const{
    return p_hand;
}

int Player::get_hand_total() const{
    return hand_total;
}

int Player::get_playing_total() const{
    return playing_total;
}

int* Player::get_card_total() const{
    return card_total;
}

int* Player::get_bet() const{
    return bet;
}

void Player::set_name(const std::string name){
    this->name = name;
}

void Player::split(Deck &deck){
    hand_total = 2;
    Hand* temp_h;
    int* temp_ct;
    int* temp_b;
    temp_h = new Hand [2];
    temp_ct = new int [2];
    temp_b = new int [2];
    temp_h[0].get_cards_pointer()[0] = p_hand[0].get_cards_pointer()[0];
    temp_h[1].get_cards_pointer()[0] = p_hand[0].get_cards_pointer()[1];
    delete [] p_hand;
    p_hand = temp_h;
    temp_h[0].get_cards_pointer()[1] = deck.deal_card();
    temp_h[1].get_cards_pointer()[1] = deck.deal_card();
    delete [] card_total;
    card_total = temp_ct;
    set_card_total();
    temp_b[0] = bet[0] / 2;
    temp_b[1] = bet[0] / 2;
    delete [] bet;
    bet = temp_b;
}

void Player::set_card_total(){
    int card_count;
    int ace_count;
    for(int h = 0; h < hand_total; h++){
        card_count = 0;
        ace_count = 0;
        for(int i = 0; i < p_hand[h].get_num_cards(); i++){
            if(p_hand[h].get_cards_pointer()[i].get_value() == 1){
                ace_count++;
            }
        }
        for(int i = 0; i < p_hand[h].get_num_cards(); i++){
            card_count += get_card_value(p_hand[h].get_cards_pointer()[i].get_value());
        }
        for(int i = 0; i < ace_count; i++){
            if(ace_count != 0 && card_count > 21){
                ace_count--;
                card_count -= 10;
            }
        }
        card_total[h] = card_count;
    }
}

int Player::get_card_value(const int value){
    if(value == 1){
        return 11;
    }
    if(value >= 11 && value <= 13){
        return 10;
    }else{
        return value;
    }
}

void Player::set_bet(const int bet){
    this->bet[0] = bet;
}

void Player::zero_playing_total(){
    playing_total = 0;
}

void Player::set_playing_total(const int dealer_card_total){
    // Bet must be divisible by 4 !
    for(int i = 0; i < hand_total; i++){
        compare(i, bet[i], dealer_card_total);
    }
}

void Player::compare(const int hand_num, const int bet, const int dealer_card_total){
    int bonus = bet / 2;
    if(card_total[hand_num] > 21 || (dealer_card_total > card_total[hand_num] && dealer_card_total <= 21)){
        playing_total -= bet;
    }else if(dealer_card_total < card_total[hand_num] || (dealer_card_total > 21 && card_total[hand_num] <= 21)){
        playing_total += bet;
    }
    if(card_total[hand_num] == 21){
        playing_total += bonus;
    }
}

void Player::reset(){
    delete [] p_hand;
    delete [] card_total;
    delete [] bet;
    p_hand = new Hand [1];
    card_total = new int [1];
    bet = new int [1];
    hand_total = 1;
}

void Player::print_player(const int output){
    if(output == 0) std::cout << name << ": ";
    else std::cout << "Your cards: ";
    set_card_total();
    if(hand_total == 1){
        p_hand->print_hand();
        std::cout << std::endl << " Total: " << card_total[0];
        if(card_total[0] > 21) std::cout << " BUST !";
        std::cout << std::endl;
    }else{
        print_player_split(0);
        if(output == 0){
            for(int i = 0; i < name.length(); i++) std::cout << " ";
        }else{
            for(int i = 0; i < 12; i++) std::cout << " ";
        }
        print_player_split(1);
    }
}

void Player::print_player_split(const int hand_index){
    set_card_total();
    std::cout << "Hand " << hand_index + 1 << ": ";
    p_hand[hand_index].print_hand();
    std::cout << " Total: " << card_total[hand_index];
    if(card_total[hand_index] > 21){std::cout << " BUST !";}
    std::cout << std::endl;
}

Player::Player(const Player &obj){
    name = obj.name;
    hand_total = obj.hand_total;
    playing_total = obj.playing_total;
    bet = new int [hand_total];
    p_hand = new Hand [obj.hand_total];
    card_total = new int [obj.hand_total];
    for(int i = 0; i < hand_total; i++){
        bet[i] = obj.bet[i];
        p_hand[i] = obj.p_hand[i];
        card_total[i] = obj.card_total[i];
    }
}

void Player::operator =(const Player &obj){
    name = obj.name;
    hand_total = obj.hand_total;
    playing_total = obj.playing_total;
    delete [] bet;
    delete [] p_hand;
    delete [] card_total;
    bet = new int [hand_total];
    p_hand = new Hand [obj.hand_total];
    card_total = new int [obj.hand_total];
    for(int i = 0; i < hand_total; i++){
        bet[i] = obj.bet[i];
        p_hand[i] = obj.p_hand[i];
        card_total[i] = obj.card_total[i];
    }
}

Player::~Player(){
    delete [] p_hand;
    delete [] card_total;
    delete [] bet;
}
