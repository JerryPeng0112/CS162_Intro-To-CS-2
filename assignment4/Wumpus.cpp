/*********************************************************************
** Program Filename: Wumpus.cpp
** Author: Tsewei Peng
** Date: 05/24/16
** Description: Wumpus class implementation
** Input: none
** Output: none
*********************************************************************/
#include "Wumpus.h"

Wumpus::Wumpus() : Events(1){}

void Wumpus::percept(){
    std::cout << "You smell a terrible stench." << std::endl;
}
void Wumpus::encounter(){
    std::cout << "Suddenly your flashlight went out!" << std::endl << "Everything became a mystery," << std::endl << "and the myth of the Wumpus never dies..." << std::endl;
}

Wumpus::Wumpus(const Wumpus &obj) : Events(obj){};

void Wumpus::operator =(const Wumpus &obj){
    Events::operator =(obj);
}

Wumpus::~Wumpus(){}
