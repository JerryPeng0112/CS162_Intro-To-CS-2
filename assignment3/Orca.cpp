/*********************************************************************
** Program Filename: Orca.cpp
** Author: Tsewei Peng
** Date: 05/08/16
** Description: Orca class
** Input: age
** Output: none
*********************************************************************/
#include "Orca.h"

/*********************************************************************
** Function: Orca()
** Description: Default Constructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Orca::Orca(){}

/*********************************************************************
** Function: Orca(int age)
** Description: Constructor
** Parameters: int age
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Orca::Orca(int age) : Animal(age, 50000, 1, 20, 4000){}

/*********************************************************************
** Function: Orca(const Orca &obj)
** Description: Copy constructor
** Parameters: const Orca &obj
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Orca::Orca(const Orca &obj) : Animal(obj){}

/*********************************************************************
** Function: void operator =(const Orca &obj)
** Description: Assignment Overload
** Parameters: const Orca &obj
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Orca::operator =(const Orca &obj){
    Animal::operator =(obj);
}

/*********************************************************************
** Function: ~Orca()
** Description: Destructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Orca::~Orca(){}
