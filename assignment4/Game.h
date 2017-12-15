/*********************************************************************
** Program Filename: Game.h
** Author: Tsewei Peng
** Date: 05/24/16
** Description: Game class header
** Input: none
** Output: eveything
*********************************************************************/
#ifndef GAME_H
#define GAME_H
#include "Room.h"
#include <string>
#include <cstdlib>

class Game{
private:
    Room **rooms; // bigger room: 2 more rows and columns
    bool **board; // Hidden board to show if user stepped on it
    int initial_setup[14]; // Position: initial starting, Wumpus
                            // 2 bat, 2 pit, gold (in row and col)
    int adjacent_room[4]; // The position of adjacent rooms,
                            // '0' if room out of border
    bool wumpus_dead; // true if wumpus dead
    bool has_gold; // true if user acquire gold
    int side; // the number of rooms on each side
    int print_arrow; // the message to print for arrow
    int arrow; // number of arrows
    int user_row; // Room for user: row
    int user_col; // Room for user: col
    int wumpus_row; // Room for wumpus row
    int wumpus_col; // Room for wumpus col
    int end_game_choice; // the end game choice
public:
    Game(); // Default Constructor
    Game(int); // Constructor
    void generate_position(); // Generate position for all the events
    void set_up_game(); // Set up the game_table;
    void create_event(const int); // Create the event using generated position
    bool not_playable(); // Check if the game board is playable
    int count_events(const int, const int); // Count events around
    void print_hidden_map(); // Print all the info on the map
    void print_map(); // Print the map for user
    void run_game(); // Run the game
    void encounter(); // Print the encounter message
    bool super_bat(); // Check if position available for super bat
    void print_arrow_state(); // Print the arrow state
    void get_room(); // Get the room number
    void percept(); // Print the percept message
    void round(); // Play the round
    void move(); // move to another rooms
    void determine_adjacent(); // Determine adjacent rooms
    void shoot(); // shoot the arrow
    void shoot_arrow(const int); // Shoot the arrow at direction
    void wumpus_flee(); // Wumpus flee when arrow missed
    bool wumpus_position(); // Check if new wumpus position good
    bool game_over(); // Check if the user win or lose
    void clear_rooms(); // Clear the rooms for a new game
    void print_game_over(const int); // print game over message
    void print_welcome_message(); // print the welcome message
    int prompt_room(std::string question); // Prompt adjacent
                                // room, user input number
    bool prompt_ai(); // prompt the user if he wants to use AI
    void ai_percept(int []); // percept for AI
    void ai_encounter(); // encounter for AI
    bool end_game(); // prompt the user the choice at the end of game
    void tostring(char [], int); // convert integer to string
    int prompt(const std::string, const int, const int); // Prompt the user questions
    int get_num(const std::string); // Get the number from user
    bool valid_num(const std::string); // Check if the user input is valid
    Game(const Game&); // Copy Constructor
    void operator =(const Game&); // operator overload
    ~Game(); // Destructor
};

#endif
