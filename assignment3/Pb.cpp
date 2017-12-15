/*********************************************************************
** Program Filename: Pb.cpp
** Author: Tsewei Peng
** Date: 05/08/16
** Description: Polar bear class
** Input: age
** Output: none
*********************************************************************/
#include "Pb.h"

/*********************************************************************
** Function: Pb()
** Description: Default constructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Pb::Pb(){}

/*********************************************************************
** Function: Pb(int age)
** Description: Constructor
** Parameters: int age
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Pb::Pb(int age) : Animal(age, 5000, 2, 3, 250){}

/*********************************************************************
** Function: Pb(const Pb &obj)
** Description: Copy Constructor
** Parameters: const Pb &obj
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Pb::Pb(const Pb &obj) : Animal(obj){}

void Pb::operator =(const Pb &obj){
    Animal::operator =(obj);
}

/*********************************************************************
** Function: ~Pb()
** Description: destructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Pb::~Pb(){}
