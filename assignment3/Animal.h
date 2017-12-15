/*********************************************************************
** Program Filename: Animal.h
** Author: Tsewei Peng
** Date: 05/08/16
** Description: Animal class header
** Input: none
** Output: none
*********************************************************************/
#ifndef ANIMAL_H
#define ANIMAL_H

class Animal{
private:
    int age;
    int cost;
    int babies;
    int avg_food_cost_mult;
    int payoff;
public:
    Animal(); // Default Constructor
    Animal(int, int, int, int, int); // Non-default Constructor
    int get_age(); // Accessor age
    int get_cost(); // Accessor cost
    int get_babies(); // Accessor babies
    int get_multiplier(); // Accessor average_food_cost_mult
    int get_payoff(); // Accessor payoff
    void increase_age(); // Increase the age
    Animal(const Animal&); // Copy constructor
    void operator =(const Animal&); // Assignment overload
    ~Animal();
};

#endif
