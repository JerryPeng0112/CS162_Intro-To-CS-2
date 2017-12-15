/*********************************************************************
** Program Filename: Bat.h
** Author: Tsewei Peng
** Date: 05/24/16
** Description: Bat class header
** Input: none
** Output: none
*********************************************************************/
#ifndef BAT_H
#define BAT_H
#include "Events.h"

class Bat : public Events{
private:
public:
    Bat(); // Default Constructor
    void percept(); // Polymorphism percept
    void encounter(); // Polymorphism encounter
    Bat(const Bat&); // Copy Constructor
    void operator =(const Bat&); // Operator overload
    ~Bat(); // Destructor
};

#endif
