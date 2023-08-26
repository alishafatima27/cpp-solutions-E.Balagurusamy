/*
  Create a base class called shape. Use this class to store two double type values that 
  could be used to compute the area of figures. 
  Derive two specific classes called triangle and rectangle from the base shape.
  Add to the base class, a member function get_data() to initialize base class data members 
  and another member function display_area() to compute and display the area of figures. 
  Make display_area() as a virtual function and redefine this function in the derived
  classes to suit their requirements.

  Using these three classes, design a program that will accept dimensions of a triangle or a rectangle interactively, and
  display the area.

  Remember the two values given as input will be treated as lengths of two sides in the case of rectangles, 
  and as base and height in the case of the triangles, and used as follows:

  Area of rectangle = x * y Area of triangle = 1/2 * x * y
*/ 


#include <iostream>
using namespace std;

class Shape {
protected:
    double dim1;
    double dim2;

public:
    void get_data() {
        cout << "Enter dimension 1: ";
        cin >> dim1;
        cout << "Enter dimension 2: ";
        cin >> dim2;
    }

    virtual void display_area() {
        cout << "Shape Area: " << dim1 * dim2 << endl;
    }
};

class Triangle : public Shape {
public:
    void display_area() override {
        cout << "Triangle Area: " << 0.5 * dim1 * dim2 << endl;
    }
};

class Rectangle : public Shape {
public:
    void display_area() override {
        cout << "Rectangle Area: " << dim1 * dim2 << endl;
    }
};

int main() {
    int choice;
    Shape *shapePtr; // Base class pointer to hold derived class objects

    cout << "Select shape: " << endl;
    cout << "1. Triangle" << endl;
    cout << "2. Rectangle" << endl;
    cin >> choice;

    switch (choice) {
        case 1:
            shapePtr = new Triangle();
            break;
        case 2:
            shapePtr = new Rectangle();
            break;
        default:
            cout << "Invalid choice" << endl;
            return 1;
    }

    shapePtr->get_data();
    shapePtr->display_area();

    delete shapePtr; // Free memory allocated for shapePtr

    return 0;
}
