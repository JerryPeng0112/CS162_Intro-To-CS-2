#include "Shape.h"
#include "Rect.h"

Rect::Rect(){}

Rect::Rect(const double length, const double width, const string name, const string color) : Shape(name, color){
    this->length = length;
    this->width = width;
}

double Rect::get_length() const{
    return length;
}

double Rect::get_width() const{
    return width;
}

void Rect::set_length(const double length){
    this->length = length;
}

void Rect::set_width(const double width){
    this->width = width;
}

double Rect::area(){
    cout << "width" << width << endl;
    return width*length;
}
