/*********************************************************************
** Program Filename: Gold.cpp
** Author: Tsewei Peng
** Date: 05/24/16
** Description: Gold class implementation
** Input: none
** Output: none
*********************************************************************/
#include "Gold.h"

Gold::Gold() : Events(4){}

void Gold::percept(){
    std::cout << "You see a glimmer nearby." << std::endl;
}
void Gold::encounter(){
    std::cout << "You found a chest of GOLD !" << std::endl;
}

Gold::Gold(const Gold &obj) : Events(obj){};

void Gold::operator =(const Gold &obj){
    Events::operator =(obj);
}

Gold::~Gold(){}
