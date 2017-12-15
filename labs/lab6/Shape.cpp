#include "Shape.h"

Shape::Shape(){}

Shape::Shape(const string name, const string color){
    this->name = name;
    this->color = color;
}

string Shape::get_name() const{
    return name;
}

string Shape::get_color() const{
    return color;
}

void Shape::set_name(const string name){
    this->name = name;
}

void Shape::set_color(const string color){
    this->color = color;
}
