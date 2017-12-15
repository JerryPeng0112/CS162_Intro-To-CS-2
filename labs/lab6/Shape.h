#pragma one
#include <iostream>
#include <string>
using namespace std;

class Shape{
    private:
        string name;
        string color;
    public:
        Shape();
        Shape(const string, const string); // Constructor
        string get_name() const; // Accessor name
        string get_color() const; // Accessor color
        void set_name(const string); // Mutator name
        void set_color(const string); // Mutator color
        /* The area function should be polymorphed
            I'll make it polymorphic by making it virtual
            It can be a pure virtual function, nut I didnt make that way
            This class is the abstract base class */
        virtual double area(){
            return 0.0;
        }
};
