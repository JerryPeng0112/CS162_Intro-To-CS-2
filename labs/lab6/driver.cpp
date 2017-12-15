#include "Shape.h"
#include "Circle.h"
#include "Rect.h"

void print_shape_info(Shape &a){
    cout << "Shape name: " << a.get_name() << endl
        << "   color: " << a.get_color() << endl
        << "   Area: " << a.area() << endl;
}

int main(){
    Shape *rect = new Rect(1.1,35.4, "Rectangle", "Red");
    Shape *circle = new Circle(2.9, "Circle", "Yellow");
    print_shape_info(*rect);
    print_shape_info(*circle);
    delete rect;
    delete circle;
}
