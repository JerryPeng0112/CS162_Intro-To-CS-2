/*********************************************************************
** Program Filename: Events.h
** Author: Tsewei Peng
** Date: 05/24/16
** Description: Event class header
** Input: none
** Output: none
*********************************************************************/
#ifndef EVENTS_H
#define EVENTS_H
#include <iostream>

class Events{
private:
    int event_type; // (1) Wumpus, (2) Bat, (3) Pit, (4) Gold
public:
    Events(); // Default constructor
    Events(const int); // Constructor
    int get_event_type() const; // Accessor
    void set_event_type(const int); // Mutator
    virtual void percept()=0; // Virual function for percept
    virtual void encounter()=0; // Virtual function for encounter
    Events(const Events&); // Copy Constructor
    void operator =(const Events&); // operator overload
    virtual ~Events()=0; // Pure Virtual Destructor
};
#endif
