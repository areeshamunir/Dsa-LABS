#include <iostream>
using namespace std;

// Abstract class
class Shape {
public:
    // Pure virtual function
    virtual double area() = 0;
};

// Circle class
class Circle : public Shape {
private:
    double radius;

public:
    // Constructor
    Circle(double r) {
        radius = r;
    }

    // Implement area()
    double area() override {
        return 3.14159 * radius * radius;
    }
};

// Rectangle class
class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    // Constructor
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }

    // Implement area()
    double area() override {
        return length * width;
    }
};

int main() {
    // Create objects
    Circle c(5);
    Rectangle r(10, 4);

    // Display areas
    cout << "Area of Circle = " << c.area() << endl;
    cout << "Area of Rectangle = " << r.area() << endl;

    return 0;
}