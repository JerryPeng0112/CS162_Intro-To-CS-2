/*********************************************************************
** Program Filename: Events.cpp
** Author: Tsewei Peng
** Date: 05/24/16
** Description: Events class implementation
** Input: none
** Output: none
*********************************************************************/
#include "Events.h"

Events::Events(){}

Events::Events(const int event_type){
    this->event_type = event_type;
}

int Events::get_event_type() const{
    return event_type;
}

void Events::set_event_type(const int event_type){
    this->event_type = event_type;
}

Events::Events(const Events &obj){
    event_type = obj.event_type;
}

void Events::operator =(const Events &obj){
    event_type = obj.event_type;
}

Events::~Events(){}
