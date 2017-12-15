/*********************************************************************
** Program Filename: Pit.h
** Author: Tsewei Peng
** Date: 05/24/16
** Description: Pit class header
** Input: none
** Output: none
*********************************************************************/
#ifndef PIT_H
#define PIT_H
#include "Events.h"

class Pit : public Events{
private:
public:
    Pit(); // Default Constructor
    void percept(); // Polymorphism percept
    void encounter(); // Polymorphism encounter
    Pit(const Pit&); // Copy Constructor
    void operator =(const Pit&); // Operator overload
    ~Pit(); // Destructor
};

#endif
