/*********************************************************************
** Program Filename: Tiger.h
** Author: Tsewei Peng
** Date: 05/08/16
** Description: Tiger class header
** Input: none
** Output: none
*********************************************************************/
#ifndef TIGER_H
#define TIGER_H
#include "Animal.h"

class Tiger : public Animal{
private:
public:
    Tiger(); // Default Constructor
    Tiger(int age); // Constructor
    Tiger(const Tiger&); // Copy Constructor
    void operator =(const Tiger&); // Assignment overload
    ~Tiger(); // Destructor
};

#endif
