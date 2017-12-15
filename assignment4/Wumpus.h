/*********************************************************************
** Program Filename: Wumpus.h
** Author: Tsewei Peng
** Date: 05/24/16
** Description: Wumpus class header
** Input: none
** Output: none
*********************************************************************/
#ifndef WUMPUS_H
#define WUMPUS_H
#include "Events.h"

class Wumpus : public Events{
private:
public:
    Wumpus(); // Default Constructor
    void percept(); // Polymorphism percept
    void encounter(); // Polymorphism encounter
    Wumpus(const Wumpus&); // Copy Constructor
    void operator =(const Wumpus&); // Operator overload
    ~Wumpus(); // Destructor
};

#endif
