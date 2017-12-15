/*********************************************************************
** Program Filename: Penguin.cpp
** Author: Tsewei Peng
** Date: 05/08/16
** Description: Penguin class
** Input: age
** Output: none
*********************************************************************/
#include "Penguin.h"

/*********************************************************************
** Function: Penguin()
** Description: default constructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Penguin::Penguin(){}

/*********************************************************************
** Function: Penguin(int age)
** Description: constructor
** Parameters: int
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Penguin::Penguin(int age) : Animal(age, 1000, 3, 1, 50){}

/*********************************************************************
** Function: Penguin(const Penguin &obj)
** Description: Copy constructor
** Parameters: Penguin Object
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Penguin::Penguin(const Penguin &obj) : Animal(obj){}

/*********************************************************************
** Function: void operator =(const Penguin &obj)
** Description: Assignment Overload
** Parameters: Penguin Object
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Penguin::operator =(const Penguin &obj){
    Animal::operator =(obj);
}

/*********************************************************************
** Function: ~Penguin()
** Description: destructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Penguin::~Penguin(){}
