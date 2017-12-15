/*********************************************************************
** Program Filename: Zoo.cpp
** Author: Tsewei Peng
** Date: 05/08/16
** Description: Zoo tycoon class
** Input: none
** Output: none
*********************************************************************/
#include "Zoo.h"

/*********************************************************************
** Function: Zoo()
** Description: Default Constructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Zoo::Zoo(){
    num_orca = 0;
    aquarium = false;
    aquarium_construct = 5;
    boom = false;
    bank = 100000;
    budget = 0;
}

/*********************************************************************
** Function: void play_game()
** Description: play the game
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Zoo::play_game(){
    print_start_screen();
    animals = new Animal* [4];
    start_game();
    zoo_tycoon();
}

/*********************************************************************
** Function: void print_start_screen
** Description: print starting screen
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Zoo::print_start_screen(){
    system("clear");
    std::cout << " ______________________________________ " << std::endl
              << "|                                      |" << std::endl
              << "|                                      |" << std::endl
              << "|                Welcome               |" << std::endl
              << "|                  to                  |" << std::endl
              << "|           --~ Zoo Tycoon ~--         |" << std::endl
              << "|                                      |" << std::endl
              << "|______________________________________|" << std::endl << std::endl;
    std::cout << "This is the wonderland of animals, " << std::endl
              << "Where the animals grows one year older," << std::endl
              << "Everyday...." << std::endl << std::endl
              << "At the start, You can purchase: " << std::endl
              << "Tiger, Polar Bear, and Penguin" << std::endl << std::endl
              << "Feed type: cheap, Generic, Premium" << std::endl
              << "They each cost: $10, $20, $40"<< std::endl << std::endl
              << "You have to buy an Aquarium to have orca !" << std::endl
              << "The Aquarium costs 150,000 dollars" << std::endl
              << "And takes 5 days to construct !"<< std::endl << std::endl
              << "You have $100,000, now Go !" << std::endl << std::endl;
}

/*********************************************************************
** Function: start_game()
** Description: Start the real game
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Zoo::start_game(){
    std::cout << "Do you want One or Two penguins? (1 or 2)($1000 Each)" << std::endl;
    while(1){
        num_penguin = get_num();
        if(num_penguin != 1 && num_penguin != 2){
            std::cout << "Please enter a valid number !" << std::endl;
        }else break;
    }
    std::cout << std::endl << "Do you want One or Two Polar Bears? (1 or 2)($5000 Each)" << std::endl;
    while(1){
        num_pb = get_num();
        if(num_pb != 1 && num_pb != 2){
            std::cout << "Please enter a valid number !" << std::endl;
        }else break;
    }
    std::cout << std::endl << "Do you want One or Two Tigers? (1 or 2)($10000 Each)" << std::endl;
    while(1){
        num_tiger = get_num();
        if(num_tiger != 1 && num_tiger != 2){
            std::cout << "Please enter a valid number !" << std::endl;
        }else break;
    }
    std::cout << std::endl;
    start_animal();
}

/*********************************************************************
** Function: start_animal
** Description: start the animals
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Zoo::start_animal(){
    animals[0] = new Penguin [num_penguin];
    animals[1] = new Pb [num_pb];
    animals[2] = new Tiger [num_tiger];
    animals[3] = new Orca [num_orca];
    for(int i = 0; i < num_penguin; i++){
        animals[0][i] = Penguin(3);
    }
    for(int i = 0; i < num_pb; i++){
        animals[1][i] = Pb(3);
    }
    for(int i = 0; i < num_tiger; i++){
        animals[2][i] = Tiger(3);
    }
    bank -= 1000 * num_penguin;
    bank -= 5000 * num_pb;
    bank -= 10000 * num_tiger;
}

/*********************************************************************
** Function: void zoo_tycoon
** Description: start the zoo tycoon game
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Zoo::zoo_tycoon(){
    int day = 1;
    while(1){
        system("clear");
        std::cout << "------------| DAY " << day << " |------------" << std::endl << std::endl;
        if(!run_day(day)){
            break;
        }
    }
}

/*********************************************************************
** Function: run_day(int &day)
** Description:  run the day
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
bool Zoo::run_day(int &day){
    if(bank < 0){
        std::cout << "Sorry, you bankrupted !" << std::endl;
        return false;
    }
    if(day > 1){
        print_yesterday();
    }
    std::cout << "Bank: $" << bank << std::endl;
    add_age();
    if(aquarium && aquarium_construct > 0){
        std::cout << "Aquarium Constructing. " << aquarium_construct-- << " days left !" << std::endl;
    }
    count_animal();
    print_budget();
    choose_feed();
    random_event();
    if(aquarium && !aquarium_construct){
        aquarium_construct--;
        std::cout << "Aquarium construction FINISHED ! Orcas are available" << std::endl;
    }
    day++;
    if(!end_of_day()) return false;
    else return true;
}

/*********************************************************************
** Function: print_yesterday()
** Description: print yesterday stat
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Zoo::print_yesterday(){
    if(budget >= 0) std::cout << "Yesterday Earning ------> $" << budget << std::endl;
    else std::cout << "Yesterday lost ------> $" << budget * (-1) << std::endl;
    budget = 0;
}

/*********************************************************************
** Function: add_age
** Description: add the age to all animals
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Zoo::add_age(){
    for(int i = 0; i < num_penguin; i++){
        animals[0][i].increase_age();
    }
    for(int i = 0; i < num_pb; i++){
        animals[1][i].increase_age();
    }
    for(int i = 0; i < num_tiger; i++){
        animals[2][i].increase_age();
    }
    for(int i = 0; i < num_orca; i++){
        animals[3][i].increase_age();
    }
}

/*********************************************************************
** Function: count_animal
** Description: count animal
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Zoo::count_animal(){
    int num_baby_penguin = 0, num_baby_pb = 0, num_baby_tiger = 0, num_baby_orca = 0;
    std::cout << std::endl;
    for(int i = 0; i < num_penguin; i++){
        if(animals[0][i].get_age() < 3){
            num_baby_penguin++;
        }
    }
    for(int i = 0; i < num_pb; i++){
        if(animals[1][i].get_age() < 3){
            num_baby_pb++;
        }
    }
    for(int i = 0; i < num_tiger; i++){
        if(animals[2][i].get_age() < 3){
            num_baby_tiger++;
        }
    }
    if(aquarium && aquarium_construct < 0){
        for(int i = 0; i < num_orca; i++){
            if(animals[3][i].get_age() < 3){
                num_baby_orca++;
            }
        }
    }
    print_animal(num_baby_penguin, num_baby_pb, num_baby_tiger, num_baby_orca);
}

/*********************************************************************
** Function: print_animal(int int int int)
** Description: print the animals
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Zoo::print_animal(int num_baby_penguin, int num_baby_pb, int num_baby_tiger, int num_baby_orca){
    std::cout << "Animals you own: " << num_penguin - num_baby_penguin << " Adult Penguins, " << num_baby_penguin << " Baby Penguins" << std::endl;
    std::cout << "                 " << num_pb - num_baby_pb << " Adult Polar Bears, " << num_baby_pb << " Baby Polar Bears" << std::endl;
    std::cout << "                 " << num_tiger - num_baby_tiger << " Adult Tigers, " << num_baby_tiger << " Baby Tigers" << std::endl;
    if(num_orca > 0){
         std::cout << "                 " << num_orca - num_baby_orca << " Adult Orcas, " << num_baby_orca << " Baby Orcas" << std::endl;
    }
    std::cout << std::endl;
}

/*********************************************************************
** Function: print_budget()
** Description: print_budget
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Zoo::print_budget(){
    int food_cost = 0, earning = 0;
    for(int i = 0; i < num_penguin; i++){
        food_cost += 20;
        earning += 50;
    }
    for(int i = 0; i < num_pb; i++){
        food_cost += 20 * 3;
        earning += 250;
    }
    for(int i = 0; i < num_tiger; i++){
        food_cost += 20 * 5;
        earning += 1000;
    }
    for(int i = 0; i < num_orca; i++){
        food_cost += 20 * 20;
        earning += 4000;
    }
    std::cout << "Bedget for the day (Approximation): " << std::endl << "    Food Cost: $" << food_cost << std::endl << "    Payoff: $" << earning << std::endl << std::endl;
}

/*********************************************************************
** Function: choose_feed()
** Description: choose the feed for the animals
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Zoo::choose_feed(){
    std::cout << "What type of feed would you like?" << std::endl << "(1) $10 - Cheap | (2) $20 - Generic | (3) $40 - Premium" << std::endl;
    while(1){
        feed_type = get_num();
        if(feed_type > 3 || feed_type < 1){
            std::cout << "Please enter a valid number !" << std::endl;
        }else break;
    }
    if(feed_type == 1) base_food_cost = 10;
    else if(feed_type == 2) base_food_cost = 20;
    else base_food_cost = 40;
    feed();
}

/*********************************************************************
** Function: feed()
** Description: feed
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Zoo::feed(){
    int food_cost = 0;
    for(int i = 0; i < num_penguin; i++){
        if(animals[0][i].get_age() >= 3){
            food_cost += base_food_cost;
        }else{
            food_cost += base_food_cost * 2;
        }
    }
    for(int i = 0; i < num_pb; i++){
        if(animals[1][i].get_age() >= 3){
            food_cost += base_food_cost * 3;
        }else{
            food_cost += base_food_cost * 6;
        }
    }
    for(int i = 0; i < num_tiger; i++){
        if(animals[2][i].get_age() >= 3){
            food_cost += base_food_cost * 5;
        }else{
            food_cost += base_food_cost * 10;
        }
    }
    for(int i = 0; i < num_orca; i++){
        if(animals[3][i].get_age() >= 3){
            food_cost += base_food_cost * 20;
        }else{
            food_cost += base_food_cost * 40;
        }
    }
    std::cout << "Food cost: $" << food_cost << " subtracted from the budget" << std::endl << std::endl;
    budget -= food_cost;
}

/*********************************************************************
** Function: random_event
** Description: random event
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Zoo::random_event(){
    int random;
    if(feed_type == 1) random = rand() % 10;
    if(feed_type == 2) random = rand() % 8;
    if(feed_type == 3) random = rand() % 7;
    int text_random = 0;
    if(random/2 == 0){ // Do nothing
        text_output(1);
    }else if(random/2 == 1){ // Boom
        text_output(2);
        boom = true;
    }else if(random/2 == 2){ // Birth
        text_output(3);
        birth();
    }else{ // Sickness
        text_output(4);
        sickness();
    }
    calc_payoff();
}

/*********************************************************************
** Function: text_output
** Description: output the text
** Parameters: integer
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Zoo::text_output(int num){
    int random;
    std::string line;
    if(num == 1) random = rand() % 2 + 1;
    else if(num == 2) random = rand() % 3 + 3;
    else if(num == 3) random = rand() % 2 + 6;
    else random = rand() % 3 + 8;
    std::ifstream file;
    file.open("random.txt");
    while(random){
        random--;
        getline(file, line);
    }
    std::cout << line << std::endl;
    file.close();
}

/*********************************************************************
** Function: sickness
** Description: the animals are sick
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Zoo::sickness(){
    int choice = 0;
    std::cout << "Which animal got the disease? Please cure the animal !" << std::endl << "(1) Penguin | (2) Polar Bear | (3) Tiger | (4) Orca" << std::endl;
    while(1){
        choice = get_num();
        if(choice < 1 || choice > 4){
            std::cout << "Please enter a valid number !" << std::endl;
        }if((choice == 1 && num_penguin == 0) || (choice == 2 && num_pb == 0) || (choice == 3 && num_tiger == 0) || (choice == 4 && num_orca == 0)){
            std::cout << "You do not any of the animal you chose !" << std::endl;
        }else break;
    }
    std::cout << "Unfortunately the animal died anyway..." << std::endl;
    kill_animal(choice);
}

/*********************************************************************
** Function: kill_animal
** Description: kill the animal
** Parameters: int choice
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Zoo::kill_animal(int choice){
    int num;
    if(choice == 1){
        num = --num_penguin;
        Animal *temp = new Penguin [num];
        for(int i = 0; i < num; i++){
            temp[i] = animals[choice - 1][i];
        }
        delete [] animals[choice - 1];
        animals[choice - 1] = temp;
    }
    else if(choice == 2){
        num = --num_pb;
        Animal *temp = new Pb [num];
        for(int i = 0; i < num; i++){
            temp[i] = animals[choice - 1][i];
        }
        delete [] animals[choice - 1];
        animals[choice - 1] = temp;
    }
    else if(choice == 3){
        num = --num_tiger;
        Animal *temp = new Tiger [num];
        for(int i = 0; i < num; i++){
            temp[i] = animals[choice - 1][i];
        }
        delete [] animals[choice - 1];
        animals[choice - 1] = temp;
    }
    else{
        num = --num_orca;
        Animal *temp = new Orca [num];
        for(int i = 0; i < num; i++){
            temp[i] = animals[choice - 1][i];
        }
        delete [] animals[choice - 1];
        animals[choice - 1] = temp;
    }
}

/*********************************************************************
** Function: birth()
** Description: the animal give birth
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Zoo::birth(){
    int choice;
    std::cout << "Which baby animal is born?" << std::endl << "(1) Penguin | (2) Polar Bear | (3) Tiger | (4) Orca" << std::endl;
    while(1){
        choice = get_num();
        if(choice < 1 || choice > 4){
            std::cout << "Please enter a valid number !" << std::endl;
        }else if(!check_adult(choice)){
            std::cout << "The choice you chose do not have adult !" << std::endl;
        }else break;
    }
    give_birth(choice);
}

/*********************************************************************
** Function: give_birth(int)
** Description: give birth whatever animal that is
** Parameters: int choice
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Zoo::give_birth(int choice){
    if(choice == 1){
        num_penguin += 3;
        Animal * temp = new Penguin [num_penguin];
        for(int i = 0; i < num_penguin - 3; i++) temp[i] = animals[choice - 1][i];
        delete [] animals[choice - 1];
        animals[choice - 1] = temp;
        for(int i = 0; i < 3; i++) animals[choice - 1][num_penguin - 3 + i] = Penguin(0);
    }
    else if(choice == 2){
        num_pb += 2;
        Animal * temp = new Pb [num_pb];
        for(int i = 0; i < num_pb - 1; i++) temp[i] = animals[choice - 1][i];
        delete [] animals[choice - 1];
        animals[choice - 1] = temp;
        for(int i = 0; i < 2; i++) animals[choice - 1][num_pb - 2 + i] = Pb(0);
    }
    else if(choice == 3){
        Animal * temp = new Tiger [++num_tiger];
        for(int i = 0; i < num_tiger - 1; i++) temp[i] = animals[choice - 1][i];
        delete [] animals[choice - 1];
        animals[choice - 1] = temp;
        animals[choice - 1][num_tiger - 1] = Tiger(0);
    }
    else{
        Animal * temp = new Orca [++num_orca];
        for(int i = 0; i < num_orca - 1; i++) temp[i] = animals[choice - 1][i];
        delete [] animals[choice - 1];
        animals[choice - 1] = temp;
        animals[choice - 1][num_orca - 1] = Orca(0);
    }
}

/*********************************************************************
** Function: check_adult(int choice)
** Description: check if it is adult
** Parameters: int choice
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
bool Zoo::check_adult(int choice){
    if(choice == 1){
        for(int i = 0; i < num_penguin; i++){
            if(animals[0][i].get_age() >= 3){
                return true;
            }
        }
        return false;
    }
    if(choice == 2){
        for(int i = 0; i < num_pb; i++){
            if(animals[1][i].get_age() >= 3){
                return true;
            }
        }
        return false;
    }
    if(choice == 3){
        for(int i = 0; i < num_tiger; i++){
            if(animals[2][i].get_age() >= 3){
                return true;
            }
        }
        return false;
    }
    if(choice == 1){
        for(int i = 0; i < num_orca; i++){
            if(animals[3][i].get_age() >= 3){
                return true;
            }
        }
        return false;
    }
}

/*********************************************************************
** Function: add_animal(int choice)
** Description: add the animal to the zoo
** Parameters: int choice
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Zoo::add_animal(int choice){
    if(choice == 1){
        Animal * temp = new Penguin [++num_penguin];
        for(int i = 0; i < num_penguin - 1; i++) temp[i] = animals[choice - 1][i];
        delete [] animals[choice - 1];
        animals[choice - 1] = temp;
        animals[choice - 1][num_penguin - 1] = Penguin(3);
        bank -= 1000;
    }
    else if(choice == 2){
        Animal * temp = new Pb [++num_pb];
        for(int i = 0; i < num_pb - 1; i++) temp[i] = animals[choice - 1][i];
        delete [] animals[choice - 1];
        animals[choice - 1] = temp;
        animals[choice - 1][num_pb - 1] = Pb(3);
        bank -= 5000;
    }
    else if(choice == 3){
        Animal * temp = new Tiger [++num_tiger];
        for(int i = 0; i < num_tiger - 1; i++) temp[i] = animals[choice - 1][i];
        delete [] animals[choice - 1];
        animals[choice - 1] = temp;
        animals[choice - 1][num_tiger - 1] = Tiger(3);
        bank -= 10000;
    }
    else{
        Animal * temp = new Orca [++num_orca];
        for(int i = 0; i < num_orca - 1; i++) temp[i] = animals[choice - 1][i];
        delete [] animals[choice - 1];
        animals[choice - 1] = temp;
        animals[choice - 1][num_orca - 1] = Orca(3);
        bank -= 50000;
    }
}

/*********************************************************************
** Function: calc_payoff
** Description: calculate payoff
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Zoo::calc_payoff(){
    int payoff = 0;
    for(int i = 0; i < num_penguin; i++){
        if(animals[0][i].get_age() >= 3){
            payoff += 50;
        }else payoff += 100;
    }
    for(int i = 0; i < num_pb; i++){
        if(animals[1][i].get_age() >= 3){
            payoff += 250;
        }else payoff += 500;
    }
    for(int i = 0; i < num_tiger; i++){
        if(animals[2][i].get_age() >= 3){
            payoff += 1000;
        }else payoff += 2000;
    }
    if(boom){
        int bonus = rand() % 251 + 250;
        std::cout << "Bonus for each tiger: " << bonus << std::endl;
        payoff += bonus * num_tiger;
        boom = false;
    }
    for(int i = 0; i < num_orca; i++){
        if(animals[3][i].get_age() >= 3){
            payoff += 4000;
        }else payoff += 8000;
    }
    std::cout << std::endl << "Payoff: $" << payoff << " added to the budget" << std::endl << std::endl;
    budget += payoff;
}

/*********************************************************************
** Function: end_of_day()
** Description: end of the day check
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
bool Zoo::end_of_day(){
    bank += budget;
    std::cout << "Actual Budget: " << budget << " | Bank: " << bank << std::endl;
    int choice;
    std::cout << "It is the end of the day !" << std::endl << "(1) Invest | (2) Continue to next day | (3) End the game" << std::endl;
    while(1){
        choice = get_num();
        if(choice < 1 || choice > 3){
            std::cout << "Please enter a valid number !" << std::endl;
        }else break;
    }
    if(choice == 3){
        return false;
    }else if(choice == 2){
        return true;
    }else if(choice == 1){
        buy_animal();
        return true;
    }
}

/*********************************************************************
** Function: buy_animal
** Description: buy animal
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Zoo::buy_animal(){
    int choice;
    if(!aquarium && bank >= 120000){
        buy_aquarium();
    }
    std::cout << "Which animal would you like to buy?" << std::endl << "(1) Penguin  ($1,000) | (2) Polar Bear ($5,000)" << std::endl << "(3) Tiger ($10,000) | (4) Orca ($50,000)" << std::endl;
    while(1){
        choice = get_num();
        if(choice < 1 || choice > 4){
            std::cout << "Please enter a valid number !" << std::endl;
        }else if(choice == 4 && !aquarium){
            std::cout << "Please build an aquarium to unlock orcas !" << std::endl;
        }else if((choice == 1 && bank < 1000) || (choice == 1 && bank < 5000) || (choice == 1 && bank < 10000) || (choice == 1 && bank < 50000)){
            std::cout << "You do not have enough money !" << std::endl;
        }else break;
    }
    add_animal(choice);
}

/*********************************************************************
** Function: buy_aquarium()
** Description: purchase the aquarium
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Zoo::buy_aquarium(){
    int choice;
    std::cout << "You have enough money for an aquarium !" << std::endl << "Would you like to buy it? ($120000) (1 - yes, 2 - no)" << std::endl;
    while(1){
        choice = get_num();
        if(choice < 1 || choice > 2){
            std::cout << "Please enter a valid number !" << std::endl;
        }else break;
    }
    if(choice == 1){
        std::cout << std::endl << "Construction started ! It will end in 5 days !" << std::endl;
        aquarium = true;
        bank -= 120000;
    }
}

/*********************************************************************
** Function: int get_num()
** Description: get number
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
int Zoo::get_num(){
    std::string line;
    int num;
    while(1){
        getline(std::cin, line);
        if(line.empty()){
            std::cout << "Please enter a number !" << std::endl;
        }else if(line.length() > 3 || !check_num(line)){
            std::cout << "Please enter a valid number !" << std::endl;
        }else{
            num = atoi(line.c_str());
            return num;
        }
    }
}

/*********************************************************************
** Function: check_num(string)
** Description: check if all characters are all numbers
** Parameters: string line
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
bool Zoo::check_num(std::string line){
    for(int i = 0; i < line.length(); i++){
        if(line[i] <= '0' || line[i] >= '9'){
            return false;
        }
    }
    return true;
}

/*********************************************************************
** Function: Zoo(const Zoo &obj)
** Description: copy constructor
** Parameters: const Zoo &
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Zoo::Zoo(const Zoo &obj){
    num_tiger = obj.num_tiger;
    num_pb = obj.num_pb;
    num_penguin = obj.num_penguin;
    num_orca = obj.num_orca;
    base_food_cost = 20;
    aquarium = obj.aquarium;
    aquarium_construct = obj.aquarium_construct;
    boom = obj.boom;
    feed_type = obj.feed_type;
    bank = obj.bank;
    budget = obj.budget;
    if(num_penguin != 0){
        animals[0] = new Penguin [num_penguin];
    }
    if(num_pb != 0){
        animals[1] = new Pb [num_pb];
    }
    if(num_tiger != 0){
        animals[2] = new Tiger [num_tiger];
    }
    if(num_orca != 0){
        animals[3] = new Orca [num_orca];
    }
    for(int i = 0; i < num_penguin; i++){
        animals[0][i] = obj.animals[0][i];
    }
    for(int i = 0; i < num_pb; i++){
        animals[1][i] = obj.animals[1][i];
    }
    for(int i = 0; i < num_tiger; i++){
        animals[2][i] = obj.animals[2][i];
    }
    for(int i = 0; i < num_orca; i++){
        animals[3][i] = obj.animals[3][i];
    }
}

/*********************************************************************
** Function: void operator =(const Zoo &obj)
** Description: operator overload
** Parameters: const Zoo &obj
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Zoo::operator =(const Zoo &obj){
    num_tiger = obj.num_tiger;
    num_pb = obj.num_pb;
    num_penguin = obj.num_penguin;
    num_orca = obj.num_orca;
    base_food_cost = 20;
    aquarium = obj.aquarium;
    aquarium_construct = obj.aquarium_construct;
    boom = obj.boom;
    feed_type = obj.feed_type;
    bank = obj.bank;
    budget = obj.budget;
    delete [] animals[0];
    animals[0] = new Penguin [num_penguin];
    delete [] animals[1];
    animals[1] = new Pb [num_pb];
    delete [] animals [2];
    animals[2] = new Tiger [num_tiger];
    delete [] animals [3];
    animals[3] = new Orca [num_orca];
    for(int i = 0; i < num_penguin; i++){
        animals[0][i] = obj.animals[0][i];
    }
    for(int i = 0; i < num_pb; i++){
        animals[1][i] = obj.animals[1][i];
    }
    for(int i = 0; i < num_tiger; i++){
        animals[2][i] = obj.animals[2][i];
    }
    for(int i = 0; i < num_orca; i++){
        animals[3][i] = obj.animals[3][i];
    }
}

/*********************************************************************
** Function: ~Zoo
** Description: Destructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: everything deleted
*********************************************************************/
Zoo::~Zoo(){
    for(int i = 0; i < 4; i++){
        delete [] animals[i];
    }
    delete [] animals;
}
