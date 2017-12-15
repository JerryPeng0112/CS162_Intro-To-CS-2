/*********************************************************************
** Program Filename: driver.cpp
** Author: Tsewei Peng
** Date: 05/08/16
** Description: Run the Zoo Tycoon game
** Input: none
** Output: none
*********************************************************************/
#include "Zoo.h"

/*********************************************************************
** Function: main
** Description: The main function to run the game
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
int main(){
    srand(time(NULL));
    Zoo zoo;
    zoo.play_game();
    return 0;
}
