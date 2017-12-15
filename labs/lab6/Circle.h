#pragma one

const double pi = 3.1415926;

class Circle : public Shape{
    private:
        double radius;
    public:
        Circle();
        Circle(const double, const string, const string); // Constructor
        double get_radius() const; // Accessor radius
        void set_radius(const double); // Mutator radius
        double area(); // return area
};
