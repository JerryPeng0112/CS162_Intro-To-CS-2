#include "Shape.h"
#include "Circle.h"

Circle::Circle(){}

Circle::Circle(const double radius, const string name, const string color) : Shape(name, color){
    this->radius = radius;
}

double Circle::get_radius() const{
    return radius;
}

void Circle::set_radius(const double radius){
    this->radius = radius;
}

double Circle::area(){
    cout << pi;
    double a = radius * radius * pi;
    cout << a;
    return a;
}
