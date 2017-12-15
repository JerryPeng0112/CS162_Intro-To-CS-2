/*********************************************************************
** Program Filename: Zoo.h
** Author: Tsewei Peng
** Date: 05/08/16
** Description: Zoo class header
** Input: none
** Output: none
*********************************************************************/
#ifndef ZOO_H
#define ZOO_H
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "Animal.h"
#include "Orca.h"
#include "Tiger.h"
#include "Pb.h"
#include "Penguin.h"

class Zoo{
private:
    Animal **animals;
    int num_tiger;
    int num_pb;
    int num_penguin;
    int num_orca;
    int base_food_cost;
    bool aquarium; // if true, can buy orca
    int aquarium_construct; // Days left of construct
    bool boom; // if true, add bonus
    int feed_type; // 1 or 2 or 3, 1 is premium, 3 is cheap
    int bank; // Bank
    int budget; // Planned budget shown at the start of everyday
public:
    Zoo(); // constructor
    void play_game(); // Start the game
    void print_start_screen(); // Print game starting screen
    void start_game(); // Start the game
    void start_animal(); // Buy animals
    void zoo_tycoon(); // Run the function to run days
    bool run_day(int&); // Run the function for each day.
    void print_yesterday(); // Print the stats from yesterday
    void add_age(); // Add the age to the animals
    void count_animal(); // Count the number of animals
    void print_budget(); // Print the budget
    void print_animal(int, int, int, int); // Print the number of animals
    void choose_feed(); // Choose the feed for the animals
    void feed(); // Feed the animals
    void random_event(); // Generate random event
    void text_output(int); // Output from the text
    void sickness(); // Sickness occurred
    void kill_animal(int); // Kill the animal
    void birth(); // Animal born
    void give_birth(int); // Give birth
    bool check_adult(int); // Check if there is adult
    void add_animal(int); // Add animal
    void calc_payoff(); // Calculate payoff
    bool end_of_day(); // Buy the animal return true if not quit
    void buy_animal(); // Buy an animal
    void buy_aquarium(); // Buy aquarium
    int get_num(); // Get user input number
    bool check_num(std::string); // Check if input is num
    Zoo(const Zoo&); // Copy Constructor
    void operator =(const Zoo&); // Operator Overload
    ~Zoo(); // Destructor
};

#endif
