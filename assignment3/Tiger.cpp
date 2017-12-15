/*********************************************************************
** Program Filename: Tiger.cpp
** Author: Tsewei Peng
** Date: 05/08/16
** Description: Tiger class
** Input: age
** Output: none
*********************************************************************/
#include "Tiger.h"

/*********************************************************************
** Function: Tiger()
** Description: Default Constructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Tiger::Tiger(){}

/*********************************************************************
** Function: Tiger(int age)
** Description: Constructor
** Parameters: int age
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Tiger::Tiger(int age) : Animal(age, 10000, 1, 5, 1000){}

/*********************************************************************
** Function: Tiger(const Tiger &obj)
** Description: Copy constructor
** Parameters: const Tiger &obj
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Tiger::Tiger(const Tiger &obj) : Animal(obj){}

/*********************************************************************
** Function: void operator =(const Tiger &obj)
** Description: assignment overload
** Parameters: const Tiger &obj
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Tiger::operator =(const Tiger &obj){
    Animal::operator =(obj);
}

/*********************************************************************
** Function: ~Tiger()
** Description: destructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Tiger::~Tiger(){}
