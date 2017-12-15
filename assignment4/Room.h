/*********************************************************************
** Program Filename: Room.h
** Author: Tsewei Peng
** Date: 05/24/16
** Description: Room class header
** Input: none
** Output: none
*********************************************************************/
#ifndef ROOM_H
#define ROOM_H
#include "Events.h"
#include "Wumpus.h"
#include "Bat.h"
#include "Pit.h"
#include "Gold.h"

class Room{
private:
    Events *event;
    bool has_event;
public:
    Room(); // Default Constructor
    Room(const int); // Constructor
    Events* get_event() const; // Accessor
    bool get_has_event() const; // Accessor
    void clear_event(); // Mutator
    Room(const Room&); // Copy Constructor
    void operator =(const Room&); // assignment overload
    ~Room(); // Destructor
};

#endif
