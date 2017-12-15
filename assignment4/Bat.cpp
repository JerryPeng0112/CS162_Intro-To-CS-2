/*********************************************************************
** Program Filename: Bat.cpp
** Author: Tsewei Peng
** Date: 05/24/16
** Description: Bat class implementation
** Input: none
** Output: none
*********************************************************************/
#include "Bat.h"

Bat::Bat() : Events(2){}

void Bat::percept(){
    std::cout << "You hear wings flapping." << std::endl;
}
void Bat::encounter(){
    std::cout << "The gigantic Super Bat carried you" << std::endl << "And dropped you in a random room" << std::endl;
}

Bat::Bat(const Bat &obj) : Events(obj){};

void Bat::operator =(const Bat &obj){
    Events::operator =(obj);
}

Bat::~Bat(){}
