/*********************************************************************
** Program Filename: Pit.cpp
** Author: Tsewei Peng
** Date: 05/24/16
** Description: Pit class implementation
** Input: none
** Output: none
*********************************************************************/
#include "Pit.h"

Pit::Pit() : Events(3){}

void Pit::percept(){
    std::cout << "You feel a breeze." << std::endl;
}
void Pit::encounter(){
    std::cout << "You slip into a huge pit and was never heard." << std::endl;
}

Pit::Pit(const Pit &obj) : Events(obj){};

void Pit::operator =(const Pit &obj){
    Events::operator =(obj);
}

Pit::~Pit(){}
