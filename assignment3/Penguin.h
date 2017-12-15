/*********************************************************************
** Program Filename: Penguin.h
** Author: Tsewei Peng
** Date: 05/08/16
** Description: Penguin class header
** Input: none
** Output: none
*********************************************************************/
#ifndef PENGUIN_H
#define PENGUIN_H
#include "Animal.h"

class Penguin : public Animal{
private:
public:
    Penguin(); // Default Constructor
    Penguin(int age); // Constructor
    Penguin(const Penguin&); // Copy Constructor
    void operator =(const Penguin&); // Assignment overload
    ~Penguin();
};

#endif
