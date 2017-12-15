/*********************************************************************
** Program Filename: Pb.h
** Author: Tsewei Peng
** Date: 05/08/16
** Description: Polar Bear class header
** Input: none
** Output: none
*********************************************************************/
#ifndef PB_H
#define PB_H
#include "Animal.h"

class Pb : public Animal{
private:
public:
    Pb(); // Default Constructor
    Pb(int age); // Constructor;
    Pb(const Pb&); // Copy Constructor
    void operator =(const Pb&); // Assignment overload
    ~Pb();
};

#endif
