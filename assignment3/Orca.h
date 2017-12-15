/*********************************************************************
** Program Filename: Orca.h
** Author: Tsewei Peng
** Date: 05/08/16
** Description: Orca class header
** Input: none
** Output: none
*********************************************************************/
#ifndef ORCA_H
#define ORCA_H
#include "Animal.h"

class Orca : public Animal{
private:
public:
    Orca(); // Default Constructor
    Orca(int); // Constructor
    Orca(const Orca&); // Copy Constructor
    void operator =(const Orca&); // Assignment overload
    ~Orca(); // Destructor
};

#endif
