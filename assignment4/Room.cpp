/*********************************************************************
** Program Filename: Room.cpp
** Author: Tsewei Peng
** Date: 05/24/16
** Description: Room class implementation
** Input: none
** Output: none
*********************************************************************/
#include "Room.h"

Room::Room(){
    has_event = false;
}

/*********************************************************************
** Function: Room constructor
** Description: Create a room with event in it depending on event_type
** Parameters: const int event_type
** Pre-Conditions: none
** Post-Conditions: room contain an event
*********************************************************************/
Room::Room(const int event_type){
    has_event = true;
    switch(event_type){
        case 1:
            event = new Wumpus;
            break;
        case 2:
            event = new Bat;
            break;
        case 3:
            event = new Pit;
            break;
        case 4:
            event = new Gold;
            break;
    }
}

Events* Room::get_event() const{
    return event;
}

bool Room::get_has_event() const{
    return has_event;
}

/*********************************************************************
** Function: void clear_event
** Description: clear the event from the room
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: room doens't have event
*********************************************************************/
void Room::clear_event(){
    delete event;
    has_event = false;
}

Room::Room(const Room &obj){
    int event_type;
    has_event = obj.has_event;
    if(has_event){
        std::cout << has_event << std::endl;
        event_type = obj.event->get_event_type();
        switch(event_type){
            case 1:
                event = new Wumpus;
                break;
            case 2:
                event = new Bat;
                break;
            case 3:
                event = new Pit;
                break;
            case 4:
                event = new Gold;
                break;
        }
    }
}

void Room::operator =(const Room &obj){
    int event_type;
    if(has_event) delete event;
    has_event = obj.has_event;
    if(has_event){
        event_type = obj.event->get_event_type();
        switch(event_type){
            case 1:
                event = new Wumpus;
                break;
            case 2:
                event = new Bat;
                break;
            case 3:
                event = new Pit;
                break;
            case 4:
                event = new Gold;
                break;
        }
    }
}

Room::~Room(){
    if(has_event) delete event;
}
