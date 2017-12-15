#pragma one

class Rect : public Shape {
    private:
        double length;
        double width;
    public:
        Rect();
        Rect(const double, const double, const string, const string); // Constructor
        double get_length() const; // Accessor length
        double get_width() const; // Accessor width
        void set_length(const double); // Mutator length
        void set_width(const double); // Mutator width
        double area(); // Calculate Area
};
