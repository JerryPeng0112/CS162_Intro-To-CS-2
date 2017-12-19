#include "./Game.h"

Game::Game(){
    init_money = get_money();
    num_players = get_player();
    players = new Player[num_players];
    for(int i = 0; i < num_players; i++){
        players[i] = Player(init_money);
    }
    for(int i = 0; i < num_players; i++){
        players[i].set_name(get_name(i));
    }
    run_game();
}

int Game::get_player(){
    int c = 0;
    std::cout << std::endl << "How many players are playing this blackjack game? (Max 8 players): " << std::endl;
    while(1){
        c = get_num();
        if(c > 8){
            std::cout << "Value too big !! MAX 8 PLAYERS !!" << std::endl;
        }else{
            std::cout << std::endl;
            return c;
        }
    }
}

int Game::get_money(){
    int c = 0;
    std::cout << std::endl << "To win, reach more than 4 times the initial amount of money !" << std::endl << std::endl << "How much money does each players get? (Min: 100, Max: 1000) " << std::endl;
    while(1){
        c = get_num();
        if(c < 100 || c > 1000){
            std::cout << "Please enter a valid number" << std::endl;
        }else if(c % 10 != 0){
            std::cout << "Please round the number to 10's" << std::endl;
        }else{
            return c;
            break;
        }
    }
}

bool Game::check_quit(){
    int zero_count = 0;
    std::cout << "-----------| Player stats |-----------" << std::endl;
    for(int i = 0; i < num_players; i++){
        std::cout << players[i].get_name() << ": $" << players[i].get_playing_total() << std::endl;
        if(players[i].get_playing_total() > 4 * init_money){
            std::cout << players[i].get_name() << " WINS !!! CONGRATULATION !" << std::endl;
            return true;
        }
    }
    for(int i = 0; i < num_players; i++){
        if(players[i].get_playing_total() == 0){
            zero_count++;
        }
    }

    if(num_players == zero_count){
        std::cout << "Eveyone bankrupts" << std::endl;
        std::cout << "-----------| Game Over |-----------" << std::endl;
        return true;
    }
    return false;
}

std::string Game::get_name(int i){
    std::string line;
    std::string reprompt;
    bool exist;
    while(1){
        std::cout << "Player " << i + 1 << " , please enter you name (Max 10 characters): " << std::endl;
        while(1){
            exist = false;
            getline(std::cin, line);
            for(int j = 0; j < i; j++){
                if(line == players[j].get_name()){
                    std::cout << "Sorry, this name is already taken" << std::endl;
                    exist = true;
                    break;
                }
            }
            if(line.empty()){
                std::cout << "Please enter a name" << std::endl;
            }
            if(!line.empty() && !exist){
                break;
            }
        }
        while(1){
            std::cout << "You want to keep this name? ('y' for yes, 'n' for no): " << std::endl;
            getline(std::cin, reprompt);
            if(line.empty() || !(reprompt != "y" || reprompt != "n")){
                std::cout << "Invalid response !" << std::endl;
            }else if(reprompt == "y"){
                std::cout << std::endl;
                return line;
            }else if(reprompt == "n"){
                std::cout << std::endl;
                break;
            }
        }
    }
}

void Game::run_game(){
    while(1){
        if(check_quit()){
            return;
        }
        round();
        reset_round();
    }
}

void Game::round(){
        bet();
        deal();
        user_choice();
        clear_line();
        std::cout << "--------| Last Round Result |--------" << std::endl;
        calculate_money();
        print_result();
        deal_dealer();
        std::cout << std::endl << std::endl;
}

void Game::bet(){
    int num;
    for(int i = 0; i < num_players; i++){
        if(players[i].get_playing_total() != 0){
            player_banner(i);
            std::cout << "How much do you want to bet? " << std::endl;
            while(1){
                num = get_num();
                if(num <= players[i].get_playing_total() && num >= 2){
                    if(num % 2 != 0){
                        std::cout << "One dollar is returned to make the bet even !" << std::endl;
                        num--;
                    }
                    players[i].set_bet(num);
                    break;
                }else if(num < 2) std::cout << "Minimum bet is $2" << std::endl;
                else std::cout << "You don't have enough money !" << std::endl;
            }
        }
    }
    std::cout << game_dealer.get_d_hand()->get_num_cards() << std::endl;
}

void Game::deal(){
    cards.reset();
    for(int j = 0; j < 2; j++){
        for(int i = 0; i < num_players; i++){
            if(players  [i].get_playing_total() != 0){
                players[i].get_p_hand()->get_cards_pointer()[j] = cards.deal_card();
            }
        }
        game_dealer.get_d_hand()->get_cards_pointer()[j] = cards.deal_card();
    }
}

void Game::print_deal_stat(){
    for(int i = 0; i < num_players; i++){
        if(players[i].get_playing_total() != 0)
            players[i].print_player(0);
    }
    game_dealer.print_dealer(true);
}

void Game::user_choice(){
    int num;
    int iter;
    bool choice[2] = {false, false};
    for(int i = 0; i < num_players; i++){
        if(players[i].get_playing_total() != 0){
            iter = 1;
            clear_screen();
            print_deal_stat();
            player_banner(i);
            players[i].print_player(1);
            while(players[i].get_card_total()[0] < 21 && players[i].get_playing_total() != 0){
                for(int j = 0; j < 2; j++){
                    choice[j] = false;
                }
                num = get_user_choice(iter, i, choice);
                iter++;
                if(num == 1){
                    hit(i, 0, false);
                }
                else if(num == 2){
                    break;
                }
                else if(var_choice(choice, num) == 0){
                    split(i);
                    break;
                }else if(players[i].get_playing_total() - players[i].get_bet()[0] >= 2 && var_choice(choice, num) == 1){
                    double_down(i, 0);
                    break;
                }
                if(players[i].get_card_total()[0] == 21) std::cout << "You have a BLACKJACK !!!" << std::endl;
            }
        }
    }
}

int Game::get_user_choice(const int iter, const int index, bool choice[]){
    int count;
    int num;
    while(players[index].get_playing_total() != 0){
        count = 2;
        std::cout << "(1) Hit (2) Stay ";
        if(iter == 1 && players[index].get_p_hand()->get_cards_pointer()[0].get_value() == players[index].get_p_hand()->get_cards_pointer()[1].get_value() && players[index].get_bet()[0] >= 4){
            std::cout << "(" << ++count << ") Split ";
            choice[0] = true;
        }
        if(iter == 1 && players[index].get_card_total()[0] >= 9 && players[index].get_card_total()[0] <= 11){
            std::cout << "(" << ++count << ") Double Down ";
            choice[1] = true;
        }
        std::cout << std::endl;
        num = get_num();
        if(num >= 1 && num <= count){
            return num;
        }else{
            std::cout << "Please enter a valid number !" << std::endl;
        }
    }
}

int Game::var_choice(bool choice[], const int num){
    int new_num = num - 3;
    for(int i = 0; i < 3; i++){
        if(choice[i] == true){
            if(new_num == 0){
                return i;
            }
            new_num--;
        }
    }
}

void Game::hit(const int index, const int hand_index, const bool split){
    if(!split){
        players[index].get_p_hand()[0].add_card(cards);
        players[index].print_player(1);
    }else{
        players[index].get_p_hand()[hand_index].add_card(cards);
        players[index].print_player_split(hand_index);
    }
}

void Game::split(const int index){
    int iter;
    bool dd = false;
    int num;
    players[index].split(cards);
    players[index].print_player(1);
    for(int i = 0; i < 2; i++){
        std::cout << "------| Hand " << i + 1 << " |------" << std::endl;
        iter = 1;
        while(players[index].get_card_total()[i] < 21 && players[index].get_playing_total() != 0){
            num = 0;

            std::cout << "(1) Hit (2) Stay";
            if(iter == 1 && players[index].get_card_total()[i] >= 9 && players[index].get_card_total()[i] <= 11 && players[index].get_playing_total() - total_bet(index) >= 2){
                std::cout << "(3) Double Down";
                dd = true;
            }
            std::cout << std::endl;
            num = get_split_user_choice(dd);
            if(num == 1) hit(index, i, true);
            else if(num == 2) break;
            else{double_down(index, i); break;}
            iter++;
            dd = false;
            if(players[index].get_card_total()[i] == 21) std::cout << "You have a BLACKJACK !!!" << std::endl;
        }
    }
}

int Game::total_bet(const int index){
    int total_bet = players[index].get_bet()[0] + players[index].get_bet()[1];
    return total_bet;
}

int Game::get_split_user_choice(const bool dd){
    int num;
    int range;
    if(dd){range = 4;}
    else{range = 3;}
    while(1){
        num = get_num();
        if(num < 1 || num > range){
            std::cout << "Please enter a valid number for your choice !" << std::endl;
        }else{
            return num;
        }
    }
}

void Game::double_down(const int index, const int hand_index){
    int num;
    while(1){
        std::cout << "How much additional bet do you want to add? (no more than original bet: " << players[index].get_bet()[0] << ")): " << std::endl;
        num = get_num();
        if(num > players[index].get_bet()[hand_index]){
            std::cout << "You cannot add more than your original bet !" << std::endl;
        }
        else if(num < 2){
            std::cout << "Please bet at least 2 dollars !" << std::endl;
        }else{
            if(num % 2 != 0){
                std::cout << "One dollar is returned to make the bet even !" << std::endl;
                num--;
            }
            players[index].get_bet()[hand_index] += num;
            break;
        }
    }
    hit(index, hand_index, true);
    if(players[index].get_card_total()[hand_index] == 21) std::cout << "You have a BLACKJACK !!!" << std::endl;
}

void Game::deal_dealer(){
    game_dealer.set_card_total();
    while(game_dealer.get_card_total() < 17){
        game_dealer.get_d_hand()->add_card(cards);
        game_dealer.set_card_total();
    }
    game_dealer.print_dealer(false);
}

void Game::calculate_money(){
    int dealer_card_total = game_dealer.get_card_total();
    for(int i = 0; i < num_players; i++){
        if(players[i].get_playing_total() != 0)
        players[i].set_playing_total(dealer_card_total);
    }
}

void Game::print_result(){
    for(int i = 0; i < num_players; i++){
        std::cout << std::endl;
        std::cout << players[i].get_name() << ": ";
        if(players[i].get_playing_total() != 0){
            if(players[i].get_hand_total() == 1){
                players[i].get_p_hand()->print_hand();
                std::cout << " Total: " << players[i].get_card_total()[0] << " Bet: " << players[i].get_bet()[0];
                print_status(players[i].get_card_total()[0]);
                std::cout << std::endl << "          Playing total: " << players[i].get_playing_total() << std::endl;
            }
            if(players[i].get_hand_total() == 2){
                for(int j = 0; j < 2; j++){
                    std::cout << "          Hand " << j + 1 << ": ";
                    players[i].get_p_hand()[j].print_hand();
                    std::cout << " Total: " << players[i].get_card_total()[j] << " Bet: " << players[i].get_bet()[j];
                    print_status(players[i].get_card_total()[j]);
                }
                std::cout << std::endl << "          Playing total: " << players[i].get_playing_total() << std::endl;
            }
        }else{
            std::cout << players[i].get_name() << " lost." << std::endl;
        }
    }
    std::cout << std::endl << std::endl;
}

void Game::print_status(const int player_card_total){
    int dealer_card_total = game_dealer.get_card_total();
    if(player_card_total > 21){
        std::cout << " BUST !";
        return;
    }
    if(player_card_total == 21){
        std::cout << " Blackjack !";
    }
    if((dealer_card_total > 21 && player_card_total <= 21) || player_card_total > dealer_card_total){
        std::cout << " WIN !!!";
    }
    if(dealer_card_total <= 21 && player_card_total == dealer_card_total){
        std::cout << " Tie !";
    }
    if(dealer_card_total <= 21 && player_card_total < dealer_card_total){
        std::cout << " LOST !";
    }
}

void Game::reset_round(){
    for(int i = 0; i < num_players; i++){
        players[i].reset();
        if(players[i].get_playing_total() == 1){
            players[i].zero_playing_total();
        }
    }
    game_dealer.reset();
}

void Game::clear_line() const{
    for(int i = 0; i < 5; i++){
        std::cout << std::endl;
    }
}

void Game::clear_screen() const{
    for(int i = 0; i < 50; i++){
        std::cout << std::endl;
    }
}

void Game::player_banner(const int index) const{
    std::cout << std::endl << "----> " << players[index].get_name() << std::endl;
}

int Game::get_num(){
    std::string line;
    int num;
    while(1){
        getline(std::cin, line);
        if(line.empty()){
            std::cout << "Please enter a number" << std::endl;
        }else if(check_num(line) != true){
            std::cout << "Please enter a valid number" << std::endl;
        }else if(line.length() > 7){
            std::cout << "Please enter a valid number" << std::endl;
        }else{
            num = atoi(line.c_str());
            return num;
        }
    }
}

bool Game::check_num(std::string line){
    for(int i = 0; i < line.length(); i++){
        if(line[i] < '0' || line[i] > '9'){
            return false;
        }
    }
    return true;
}

Deck Game::get_deck() const{
    return cards;
}

Player* Game::get_players_pointer() const{
    return players;
}

Dealer Game::get_dealer() const{
    return game_dealer;
}

int Game::get_num_players() const{
    return num_players;
}

Game::Game(const Game &obj){
    init_money = obj.init_money;
    cards = obj.cards;
    game_dealer = obj.game_dealer;
    num_players = obj.num_players;
    players = new Player [obj.num_players];
    for(int i = 0; i < num_players; i++){
        players[i] = obj.players[i];
    }
}

void Game::operator =(const Game &obj){
    init_money = obj.init_money;
    cards = obj.cards;
    game_dealer = obj.game_dealer;
    num_players = obj.num_players;
    delete [] players;
    players = new Player [num_players];
    for(int i = 0; i < num_players; i++){
        players[i] = obj.players[i];
    }
}

Game::~Game(){
    delete [] players;
}
