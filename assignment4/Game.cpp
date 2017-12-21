/*********************************************************************
** Program Filename: Game.cpp
** Author: Tsewei Peng
** Date: 05/24/16
** Description: Game class implementation
** Input: none
** Output: everything
*********************************************************************/
#include "Game.h"

Game::Game(){}

/*********************************************************************
** Function: Game default constructor
** Description: Construct the game
** Parameters: int side
** Pre-Conditions: none
** Post-Conditions: game finished
*********************************************************************/
Game::Game(int side){
    int i = 0;
    this->side = side;
    print_arrow = 0;
    end_game_choice = 2;
    while(1){
        system("clear");
        print_welcome_message();
        if(i) clear_rooms();
        else i++;
        if(end_game_choice == 1) set_up_game();
        if(end_game_choice == 3) this->side = prompt("What is the length of the side? (Min:4, Max: 12)", 4, 12);
        if(end_game_choice == 2 || end_game_choice == 3){
            do{
                generate_position();
                set_up_game();
            }while(not_playable());
        }
        //print_hidden_map();
        run_game();
        if(end_game()){
            break;
        }
    }
}

/*********************************************************************
** Function: void generate_position
** Description: generate positions for all events
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: all coordinates setup
*********************************************************************/
void Game::generate_position(){
    for(int i = 0; i < 7; i++){
        initial_setup[2 * i] = rand() % side + 1;
        initial_setup[2 * i + 1] = rand() % side + 1;
        for(int j = 0; j < i; j++){
            if(initial_setup[2 * i] == initial_setup[2 * j] && initial_setup[2 * i + 1] == initial_setup[2 * j + 1]) i--;
        }
    }
    user_row = initial_setup[0];
    user_col = initial_setup[1];
}

/*********************************************************************
** Function: void set_up_game
** Description: set up game stats
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: game setup: room and board, and various events filled
*********************************************************************/
void Game::set_up_game(){
    wumpus_dead = false;
    has_gold = false;
    arrow = 3;
    rooms = new Room* [side + 2];
    board = new bool* [side + 2];
    for(int i = 0; i <= side + 1; i++){
        rooms[i] = new Room [side + 2];
        board[i] = new bool [side + 2];
    }
    for(int i = 0; i <= side + 1; i++){
        for(int j = 0; j <= side + 1; j++){
            board[i][j] = false;
        }
    }
    for(int i = 0; i < 4; i++){
        adjacent_room[i] = 0;
    }
    board[user_row][user_col] = true;
    user_row = initial_setup[0];
    user_col = initial_setup[1];
    wumpus_row = initial_setup[2];
    wumpus_col = initial_setup[3];
    for(int i = 1; i < 7; i++){
        create_event(i);
    }
}

/*********************************************************************
** Function: void create_event
** Description: create event for the specific rooms
** Parameters: const int i
** Pre-Conditions: rooms must be setup
** Post-Conditions: rooms filled with events
*********************************************************************/
void Game::create_event(const int i){
    int row = initial_setup[2 * i];
    int col = initial_setup[2 * i + 1];
    if(i == 1) rooms[row][col] = Room(1);
    else if(i == 2 || i == 3) rooms[row][col] = Room(2);
    else if(i == 4 || i == 5) rooms[row][col] = Room(3);
    else rooms[row][col] = Room(4);
}

/*********************************************************************
** Function: bool not_playable
** Description: check if the game is playable
** Parameters: none
** Pre-Conditions: the room setup and events output
** Post-Conditions: if not playble return true, else return false
*********************************************************************/
bool Game::not_playable(){
    if(count_events(initial_setup[0], initial_setup[1]) == 4) return true;
    if(count_events(initial_setup[2], initial_setup[3]) == 4) return true;
    if(count_events(initial_setup[12], initial_setup[13]) == 4) return true;
    return false;
}

/*********************************************************************
** Function: int count_events
** Description: count how many events adjacent to the selected coordinate
** Parameters: const int x, const int y
** Pre-Conditions: none
** Post-Conditions: return the number of events around a room
*********************************************************************/
int Game::count_events(const int x, const int y){
    int n = 0;
    if(rooms[x][y + 1].get_has_event() || y == side) n++;
    if(rooms[x][y - 1].get_has_event() || y == 1) n++;
    if(rooms[x + 1][y].get_has_event() || x == side) n++;
    if(rooms[x - 1][y].get_has_event() || x == 1) n++;
    return n;
}

/*********************************************************************
** Function: void print_hidden_map
** Description: print hidden map for debug
** Parameters: none
** Pre-Conditions: room setup
** Post-Conditions: none
*********************************************************************/
void Game::print_hidden_map(){
    for(int i = 0; i < side; i++) std::cout << "--";
    std::cout << "-" << std::endl;
    for(int i = 1; i <= side; i++){
        for(int j = 1; j <= side; j++){ 
            std::cout << "|";
            if(i == user_row && j == user_col) std::cout << "U";
            else if(i == wumpus_row && j == wumpus_col) std::cout << "W";
            else if(i == initial_setup[12] && j == initial_setup[13]) std::cout << "G";
            else if((i == initial_setup[4] && j == initial_setup[5]) || (i == initial_setup[6] && j == initial_setup[7])) std::cout << "B";
            else if((i == initial_setup[8] && j == initial_setup[9]) || (i == initial_setup[10] && j == initial_setup[11])) std::cout << "P";
            else std::cout << " ";
        }
        std::cout << "|" << std::endl;
        for(int j = 1; j <= side; j++) std::cout << "--";
        std::cout << "-" << std::endl;
    }
}

/*********************************************************************
** Function: void print_map
** Description: print the map for user interface
** Parameters: none
** Pre-Conditions: rooms setup
** Post-Conditions: none
*********************************************************************/
void Game::print_map(){
    for(int i = 0; i < side; i++) std::cout << "--";
    std::cout << "-" << std::endl;
    for(int i = 1; i <= side; i++){
        for(int j = 1; j <= side; j++){
            std::cout << "|";
            if(i == user_row && j == user_col) std::cout << "@";
            else if(i == wumpus_row && j == wumpus_col && wumpus_dead) std::cout << "#";
            else if(i == initial_setup[12] && j == initial_setup[13] && board[i][j]) std::cout << "!";
            else if((i == initial_setup[4] && j == initial_setup[5] && board[i][j]) || (i == initial_setup[6] && j == initial_setup[7] && board[i][j])) std::cout << "~";
            else std::cout << " ";
        }
        std::cout << "|" << std::endl;
        for(int j = 1; j <= side; j++) std::cout << "--";
        std::cout << "-" << std::endl;
    }
    std::cout << std::endl;
    std::cout << "\"@\" = Your Position | \"#\" = Dead Wumpus" <<
    std::endl << "\"!\" = Found Gold    | \"~\" = Found Bat" << std::endl << std::endl;
}

/*********************************************************************
** Function: void run_game
** Description: the function that actually runs the game
** Parameters: none
** Pre-Conditions: rooms setup
** Post-Conditions: the user lose or win based on their moves
*********************************************************************/
void Game::run_game(){
    int i = 0;
    while(!game_over()){
        get_room();
        if(wumpus_dead && i == 0){
            std::cout << "The Evil, Deadly Wumpus' heart was Pierced by you arrow\nThe Wumpus lets out a loud groan, and collapsed..." << std::endl;
            if(!has_gold) std::cout << "Get the gold and leave before another monster strikes !" << std::endl;
            else std::cout << "Find your way back to where the rope was !" << std::endl;
            std::cout << std::endl;
            i++;
        }
        print_arrow_state();
        encounter();
        percept();
        round();
    }
}

/*********************************************************************
** Function: void print_arrow_state
** Description: Print the state of the arrow and completed objective
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Game::print_arrow_state(){
    if(wumpus_dead || has_gold){
        std::cout << "|--- Completed Objective ---|" << std::endl;
        if(wumpus_dead) std::cout << "Wumpus killed" << std::endl;
        if(has_gold) std::cout << "Gold Aquired" << std::endl;
        std::cout << std::endl;
    }
    if(print_arrow) std::cout << "|--- What happened to the Arrow ---|" << std::endl;
    if(print_arrow == 4) std::cout << "The arrow disappeared into the dark\nNothing happened..." << std::endl << std::endl;
    if(print_arrow == 3) std::cout << "You don't have any arrows left !" << std::endl << std::endl;
    else if(print_arrow == 2) std::cout << "The arrow flew, and fled... " << std::endl << std::endl;
    else if(print_arrow == 1) std::cout << "The Arrow flew, and there comes silence..." << std::endl << "Wumpus woke up and fled to another corner of the cave" << std::endl << std::endl;
    print_arrow = 0;
}

/*********************************************************************
** Function: void encounter
** Description: print the encounter message if user meet a bat or gold
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: game state changed
*********************************************************************/
void Game::encounter(){ // for bat and gold
    int row, col;
    if(rooms[user_row][user_col].get_has_event()){
        std::cout << "|------ Room Event ------|" << std::endl;
        if(rooms[user_row][user_col].get_event()->get_event_type() == 2){
            rooms[user_row][user_col].get_event()->encounter();
            while(1){
                user_row = rand() % side + 1;
                user_col = rand() % side + 1;
                if(!super_bat()){
                    print_map();
                    break;
                }
            }
        }
        else if(rooms[user_row][user_col].get_event()->get_event_type() == 4 && !has_gold){
            has_gold = true;
            rooms[user_row][user_col].get_event()->encounter();
        }
        std::cout << std::endl;
    }
}

/*********************************************************************
** Function: bool super_bat
** Description: check super bat drop the user to a room without any event
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: if it is pre-occupied by event, return true, else false
*********************************************************************/
bool Game::super_bat(){
    //std::cout << rooms[user_row][user_col].get_event()->get_event_type() << std::endl;
    if(user_row == wumpus_row && user_col == wumpus_col) return true;
    for(int i = 2; i < 7; i++){
        if(user_row == initial_setup[i * 2] && user_col == initial_setup[i * 2 + 1]) return true;
    }
    //std::cout << rooms[user_row][user_col].get_event()->get_event_type() << std::endl;
    return false;
}

/*********************************************************************
** Function: void get_room
** Description: get the number for the room
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Game::get_room(){
    int room = (user_row - 1) * side + user_col;
    std::cout << "==============================" << std::endl;
    std::cout << " You are currently in Room " << room << std::endl;
    std::cout << "==============================" << std::endl;
    //print_hidden_map();
    print_map();
}

/*********************************************************************
** Function: void percept
** Description: print the percept message
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Game::percept(){
    int count = 1;
    for(int i = user_row - 1; i <= user_row + 1; i++){
        for(int j = user_col - 1; j <= user_col + 1; j++){
            if(rooms[i][j].get_has_event() && ((i == user_row + 1 && j == user_col) || (i == user_row - 1 && j == user_col) || (i == user_row && j == user_col + 1) || (i == user_row && j == user_col - 1))){
                if(!(rooms[i][j].get_event()->get_event_type() == 1 && wumpus_dead) && !(rooms[i][j].get_event()->get_event_type() == 4 && has_gold)) {
                    if (count) {
                        std::cout << "|------ Percept ------|" << std::endl;
                        count--;
                    }
                    rooms[i][j].get_event()->percept();
                    std::cout << std::endl;
                }
            }
        }
    }
}

/*********************************************************************
** Function: void round
** Description: run the round
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Game::round(){
    int choice;
    std::cout << "You have " << arrow << " arrows. USE THEM WISELY !" << std::endl;
    choice = prompt("Would you like to (1) Move | (2) Shoot Arrow ?", 1, 2);
    if(choice == 1) move();
    if(choice == 2) shoot();
}

/*********************************************************************
** Function: void move
** Description: the user moves
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: the user moves
*********************************************************************/
void Game::move(){
    char room_num[4];
    std::string question;
    int choice;
    determine_adjacent();
    question = "Which room do you want to move to? \n";
    for(int i = 0; i < 4; i++){
        if(adjacent_room[i] != 0){
            tostring(room_num, adjacent_room[i]);
            question += "(";
            question += room_num;
            question += ")";
            if(i == 0) question += " Up";
            else if(i == 1) question += " Down";
            else if(i == 2) question += " Left";
            else question += " Right";
            question += " ";
        }
    }
    choice = prompt_room(question);
    if(choice == 0) user_row--;
    else if(choice == 1) user_row++;
    else if(choice == 2) user_col--;
    else user_col++;
    board[user_row][user_col] = true;
}

/*********************************************************************
** Function: void determine_adjacent
** Description: determine what the adjacent rooms are
** Parameters: none
** Pre-Conditions:none
** Post-Conditions: array filled with the adjacent room numbers
*********************************************************************/
void Game::determine_adjacent(){
    // up down left right
    int count = 1;
    if(user_row != 1) {
        adjacent_room[0] = count;
        count++;
    }
    else adjacent_room[0] = 0;
    if(user_row != side) {
        adjacent_room[1] = count;
        count++;
    }
    else adjacent_room[1] = 0;
    if(user_col != 1) {
        adjacent_room[2] = count;
        count++;
    }
    else adjacent_room[2] = 0;
    if(user_col != side) {
        adjacent_room[3] = count;
    }
    else adjacent_room[3] = 0;
}

/*********************************************************************
** Function: void shoot
** Description: the user decided to shoot
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: the user shoots and loses one arrow
*********************************************************************/
void Game::shoot(){
    int choice = prompt("Which direction do you want to shoot the arrow at?\n(1) Up   (2) Down\n(3) Left (4) Right", 1, 4);
    if(arrow){
        arrow--;
        if(!wumpus_dead){
            shoot_arrow(choice);
        }else{
            print_arrow = 2;
        }
    }else print_arrow = 3;
}

/*********************************************************************
** Function: void shoot_arrow
** Description: shoot the arrow in certain direction
** Parameters: const int choice
** Pre-Conditions: none
** Post-Conditions: if the arrow hits, then wumpus dead, else wumpus might flee
*********************************************************************/
void Game::shoot_arrow(const int choice){
    if(choice == 1){
        for(int i = 1; i <= 3; i++){
            if(user_row - i == wumpus_row && user_col == wumpus_col){
                wumpus_dead = true;
                return;
            }
        }
    }
    if(choice == 2){
        for(int i = 1; i <= 3; i++){
            if(user_row + i == wumpus_row && user_col == wumpus_col){
                wumpus_dead = true;
                return;
            }
        }
    }
    if(choice == 3){
        for(int i = 1; i <= 3; i++){
            if(user_row == wumpus_row && user_col - i == wumpus_col){
                wumpus_dead = true;
                return;
            }
        }
    }
    if(choice == 4){
        for(int i = 1; i <= 3; i++){
            if(user_row == wumpus_row && user_col + i == wumpus_col){
                wumpus_dead = true;
                return;
            }
        }
    }
    wumpus_flee();
}

/*********************************************************************
** Function: wumpus_flee
** Description: wumpus flee from original spot (75%)
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: wumpus flee or stay
*********************************************************************/
void Game::wumpus_flee(){
    int wumpus_move = rand()%4;
    if(wumpus_move > 0){
        rooms[wumpus_row][wumpus_col].clear_event();
        while(1){
            wumpus_row = rand() % side + 1;
            wumpus_col = rand() % side + 1;
            if(wumpus_position()){
                rooms[wumpus_row][wumpus_col] = Room(1);
                break;
            }
        }
        print_arrow = 1;
    }else print_arrow = 4;
}

/*********************************************************************
** Function: bool wumpus_position
** Description: check if wumpus position is available for event
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: return false if not available, else true
*********************************************************************/
bool Game::wumpus_position(){
    if(wumpus_row == user_row && wumpus_col == user_col) return false;
    for(int i = 2; i < 7; i++){
        if(wumpus_row == initial_setup[2 * i] && wumpus_col == initial_setup[2 * i + 1]){
            return false;
        }
    }
    return true;
}

/*********************************************************************
** Function: bool game_over
** Description: check if game over or not
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: return true if game over, or return false
*********************************************************************/
bool Game::game_over(){ // encounter for wumpus and pit
    system("clear");
    if(user_row == initial_setup[0] && user_col == initial_setup[1] && has_gold && wumpus_dead){
        std::cout << "You climbed up the rope, and the myth of Wumpus is gone !" << std::endl;
        print_game_over(2);
        return true;
    }
    if(arrow == 0 && !wumpus_dead){
        std::cout << "You ran out of Arrow..." << std::endl << "Now you are left to be eaten by the Wumpus" << std::endl;
        print_game_over(1);
        return true;
    }
    if(user_row == wumpus_row && user_col == wumpus_col && !wumpus_dead){
        rooms[user_row][user_col].get_event()->encounter();
        print_game_over(1);
        return true;
    }
    if((user_row == initial_setup[8] && user_col == initial_setup[9]) || (user_row == initial_setup[10] && user_col == initial_setup[11])){
        rooms[user_row][user_col].get_event()->encounter();
        if(!wumpus_dead) std::cout << "The myth of the Wumpus never dies..." << std::endl;
        print_game_over(1);
        return true;
    }
    return false;
}

/*********************************************************************
** Function: void clear_rooms
** Description: if starts a new game, old board cleaned
** Parameters: none
** Pre-Conditions: game finished and new one started
** Post-Conditions: clear all the arrays
*********************************************************************/
void Game::clear_rooms(){
    for(int i = 0; i <= side + 1; i++){
        delete [] board[i];
        delete [] rooms[i];
    }
    delete [] board;
    delete [] rooms;
}

/*********************************************************************
** Function: void print_game_over
** Description: print the game over message
** Parameters: const int status
** Pre-Conditions: game over
** Post-Conditions: if status is 1, print game over, else print winning message
*********************************************************************/
void Game::print_game_over(const int status){
    if(status == 1){
        std::cout << "============================" << std::endl
                  << "|         Game Over        |" << std::endl
                  << "============================" << std::endl;
    }else{
        std::cout << "============================" << std::endl
                  << "|     Congratulations !    |" << std::endl
                  << "============================" << std::endl
                  << "|         You Won !!!      |" << std::endl
                  << "============================" << std::endl;
    }
}

/*********************************************************************
** Function: void print_welcome_message
** Description: print the welcome message
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Game::print_welcome_message(){
    std::cout << " ______________________________________ " << std::endl
              << "|                                      |" << std::endl
              << "|                Welcome               |" << std::endl
              << "|                  to                  |" << std::endl
              << "|        --~ Hunt the Wumpus ~--       |" << std::endl
              << "|                                      |" << std::endl
              << "|______________________________________|" << std::endl
              << std::endl
              << "You are an adventurer, Jeremy Cole !" << std::endl
              << "You went on an adventure, and it might cost you your life" << std::endl
              << "You slip down a rope into a cave" << std::endl
              << "Now your objective is to: " << std::endl
              << "    --> Find the chest of gold" << std::endl
              << "    --> Kill the Wumpus using your arrow" << std::endl
              << "    --> Find your way back to your rope to escape" << std::endl
              << "Use your \"percept\" ability to sense your surroundings !" << std::endl
              << "Good luck and hope you don't get eaten !" << std::endl
              << std::endl;
}

/*********************************************************************
** Function: int prompt_room
** Description: prompt which room to enter
** Parameters: std::string question
** Pre-Conditions: none
** Post-Conditions: the user enter a valid adjacent room number
*********************************************************************/
int Game::prompt_room(std::string question){
    int room_choice;
    while(1){
        room_choice = get_num(question);
        if(room_choice != 0){
            for(int i = 0; i < 4; i++){
                if(adjacent_room[i] == room_choice){
                    return i;
                }
            }
            std::cout << "Please enter a valid room number !" << std::endl;
        }
        else std::cout << "Please enter a valid room number !" << std::endl;
    }
}

/*********************************************************************
** Function: bool end_game
** Description:
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: end the game or play with new boards, etc
*********************************************************************/
bool Game::end_game(){
    end_game_choice = prompt("Would you like to:\n   (1) Start over with same map (Same map, Same size)\n   (2) Start over with same configuration (Different map, Same size)\n   (3) Start over with different configuration (Different size)\n   (4) Quit the game", 1, 4);
    if(end_game_choice == 4){
        return true;
    }
    return false;
}

/*********************************************************************
** Function: void tostring
** Description: convert integer to c string
** Parameters: char str[], int num
** Pre-Conditions: none
** Post-Conditions: return the c string
*********************************************************************/
void Game::tostring(char str[], int num)
{
    int i, rem, len = 0, n = num;
    while (n != 0){
        len++;
        n /= 10;
    }
    for (i = 0; i < len; i++){
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
}

/*********************************************************************
** Function: int prompt
** Description: prompt the questions and get user input
** Parameters: string prompt, const int min, const int max
** Pre-Conditions: none
** Post-Conditions: return the user choice
*********************************************************************/
int Game::prompt(const std::string prompt, const int min, const int max){
    int choice;
    while(1){
        choice = get_num(prompt);
        if(choice < min || choice > max) std::cout << std::endl << "Please enter a valid number !" << std::endl;
        else return choice;
    }
}

/*********************************************************************
** Function: int get_num
** Description: get the number from user
** Parameters: std::string prompt
** Pre-Conditions: a question is prompted
** Post-Conditions: return the user input
*********************************************************************/
int Game::get_num(const std::string prompt){
    std::string line;
    while(1){
        std::cout << prompt << std::endl;
        int choice;
        getline(std::cin, line);
        if(valid_num(line)){
            choice = atoi(line.c_str());
            return choice;
        }
    }
}

/*********************************************************************
** Function: bool valid_num
** Description: check if the user input are all numbers
** Parameters: user input string
** Pre-Conditions: user input
** Post-Conditions: return true if all are numbers, or false
*********************************************************************/
bool Game::valid_num(const std::string line){
    if(line.empty()){
        std::cout << std::endl << "Please enter something !" << std::endl;
        return false;
    }
    else if(line.length() > 3){
        std::cout << std::endl << "Please enter a valid number !" << std::endl;
        return false;
    }
    for(int i = 0; i < line.length(); i++){
        if(line[i] < '0' || line[i] > '9'){
            std::cout << std::endl << "Please enter a valid number !" << std::endl;
            return false;
        }
    }
    return true;
}

/*********************************************************************
** Function: Copy constructor
** Description: Copy Constructor
** Parameters: const Game&
** Pre-Conditions: none
** Post-Conditions:none
*********************************************************************/
Game::Game(const Game &obj){
    wumpus_dead = obj.wumpus_dead;
    has_gold = obj.has_gold;
    side = obj.side;
    arrow = obj.arrow;
    user_row = obj.user_row;
    user_col = obj.user_col;
    wumpus_row = obj.wumpus_row;
    wumpus_col = obj.wumpus_col;
    end_game_choice = obj.end_game_choice;
    for(int i = 0; i < 4; i++){
        adjacent_room[i] = obj.adjacent_room[i];
    }
    for(int i = 0; i < 14; i++){
        initial_setup[i] = obj.initial_setup[i];
    }
    rooms = new Room * [side + 2];
    board = new bool * [side + 2];
    for(int i = 0; i <= side + 1; i++){
        rooms[i] = new Room [side + 2];
        board[i] = new bool [side + 2];
    }
    for(int i = 0; i <= side +1; i++){
        for(int j = 0; j <= side + 1; j++){
            rooms[i][j] = obj.rooms[i][j];
            board[i][j] = obj.board[i][j];
        }
    }
}

/*********************************************************************
** Function: void operator=
** Description: operator overload
** Parameters: const Game&
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Game::operator =(const Game &obj){
    wumpus_dead = obj.wumpus_dead;
    has_gold = obj.has_gold;
    side = obj.side;
    arrow = obj.arrow;
    user_row = obj.user_row;
    user_col = obj.user_col;
    wumpus_row = obj.wumpus_row;
    wumpus_col = obj.wumpus_col;
    end_game_choice = obj.end_game_choice;
    for(int i = 0; i < 4; i++){
        adjacent_room[i] = obj.adjacent_room[i];
    }
    for(int i = 0; i < 14; i++){
        initial_setup[i] = obj.initial_setup[i];
    }
    for(int i = 0; i <= side + 1; i++){
        delete [] board[i];
        delete [] rooms[i];
    }
    delete [] board;
    delete [] rooms;
    rooms = new Room * [side + 2];
    board = new bool * [side + 2];
    for(int i = 0; i <= side + 1; i++){
        rooms[i] = new Room [side + 2];
        board[i] = new bool [side + 2];
    }
    for(int i = 0; i <= side +1; i++){
        for(int j = 0; j <= side + 1; j++){
            rooms[i][j] = obj.rooms[i][j];
            board[i][j] = obj.board[i][j];
        }
    }
}

/*********************************************************************
** Function: ~Game
** Description: destructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: game destructed
*********************************************************************/
Game::~Game(){
    for(int i = 0; i <= side + 1; i++){
        delete [] board[i];
        delete [] rooms[i];
    }
    delete [] board;
    delete [] rooms;
}