/*********************************************************************
** Program Filename: Gold.h
** Author: Tsewei Peng
** Date: 05/24/16
** Description: Gold class header
** Input: none
** Output: none
*********************************************************************/
#ifndef GOLD_H
#define GOLD_H
#include "Events.h"

class Gold : public Events{
private:
public:
    Gold(); // Default Constructor
    void percept(); // Polymorphism percept
    void encounter(); // Polymorphism encounter
    Gold(const Gold&); // Copy Constructor
    void operator =(const Gold&); // Operator overload
    ~Gold(); // Destructor
};

#endif
