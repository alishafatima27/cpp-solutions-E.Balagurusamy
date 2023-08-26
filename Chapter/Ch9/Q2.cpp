/*  
  Extend the previous program to display the area of circles. 
  This requires addition of a new derived class 'circle' that computes the area of a circle. 
  Remember, for a circle we need only one value, its radius, but the get_data() function in
  the base class requires two values to be passed. 
  (Hint: Make the second argument of get_data() function as a default one with zero value.)
*/


#include <iostream>
#include <cmath> // For the constant M_PI
using namespace std;

class Shape 
{
protected:
    double dim1;
    double dim2;

public:
    void get_data(double d1, double d2 = 0) 
    {
        dim1 = d1;
        dim2 = d2;
    }

    virtual void display_area() 
    {
        cout << "Shape Area: " << dim1 * dim2 << endl;
    }
};

class Triangle : public Shape {
public:
    void display_area() override 
    {
        cout << "Area of Triangle: " << 0.5 * dim1 * dim2 << endl;
    }
};

class Rectangle : public Shape 
    {
public:
    void display_area() override {
        cout << "Area of rectangle : " << dim1 * dim2 << endl;
    }
};

class Circle : public Shape {
public:
    void display_area() override 
    {
        cout << "Area of Circle : " << M_PI * pow(dim1, 2) << endl;
    }
};

int main() {
    int choice;
    Shape *shapePtr; // Base class pointer to hold derived class objects

    cout << "Select shape: " << endl;
    cout << "1. Triangle" << endl;
    cout << "2. Rectangle" << endl;
    cout << "3. Circle" << endl;
    cin >> choice;

    switch (choice) {
        case 1:
            shapePtr = new Triangle();
            break;
        case 2:
            shapePtr = new Rectangle();
            break;
        case 3:
            shapePtr = new Circle();
            break;
        default:
            cout << "Invalid choice" << endl;
            return 1;
    }

    double dim1, dim2 = 0;
    cout << "Enter dimension 1: ";
    cin >> dim1;
    if (choice != 3) {
        cout << "Enter dimension 2: ";
        cin >> dim2;
    }

    shapePtr->get_data(dim1, dim2);
    shapePtr->display_area();

    delete shapePtr; // Free memory allocated for shapePtr

    return 0;
}
