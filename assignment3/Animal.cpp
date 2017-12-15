/*********************************************************************
** Program Filename: Animal.cpp
** Author: Tsewei Peng
** Date: 05/08/16
** Description: Animal class
** Input: none
** Output: none
*********************************************************************/
#include "Animal.h"

/*********************************************************************
** Function: Animal()
** Description: Default Constructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Animal::Animal(){}

/*********************************************************************
** Function: Animal(int age, int cost, int babies, int average_food_cost_mult, int payoff)
** Description: Constructor
** Parameters: int age, int cost, int babies, int average_food_cost_mult, int payoff
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Animal::Animal(int age, int cost, int babies, int average_food_cost_mult, int payoff){
    this->age = age;
    this->cost = cost;
    this->babies = babies;
    this->avg_food_cost_mult = avg_food_cost_mult;
    this->payoff = payoff;
}

/*********************************************************************
** Function: int get_age()
** Description: accessor age
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
int Animal::get_age(){
    return age;
}

/*********************************************************************
** Function: int get_cost()
** Description: accessor cost
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
int Animal::get_cost(){
    return cost;
}

/*********************************************************************
** Function: int get_babies()
** Description: accessor babies
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
int Animal::get_babies(){
    return babies;
}

/*********************************************************************
** Function: int get_multiplier()
** Description: accessor multiplier
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
int Animal::get_multiplier(){
    return avg_food_cost_mult;
}

/*********************************************************************
** Function: int get_payoff()
** Description: accessor payoff
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
int Animal::get_payoff(){
    return payoff;
}

/*********************************************************************
** Function: void increase_age
** Description: increase age
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Animal::increase_age(){
    age++;
}

/*********************************************************************
** Function: Animal(const Animal &obj)
** Description: Copy constructor
** Parameters: const Animal &obj
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Animal::Animal(const Animal &obj){
    age = obj.age;
    cost = obj.cost;
    babies = obj.babies;
    avg_food_cost_mult = obj.avg_food_cost_mult;
    payoff = obj.payoff;
}

/*********************************************************************
** Function: void operator =(const Animal &obj)
** Description: assignment overload
** Parameters: const Animal &obj
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Animal::operator =(const Animal &obj){
    age = obj.age;
    cost = obj.cost;
    babies = obj.babies;
    avg_food_cost_mult = obj.avg_food_cost_mult;
    payoff = obj.payoff;
}

/*********************************************************************
** Function: ~Animal()
** Description: Destructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Animal::~Animal(){}
