/* Run the previous program with the following modifications:
     (a) Remove the definition of display_area() from one of the derived classes. 
     (b) In addition to the above change, declare the display_area() as virtual in the base class shape.
   Comment on the output of each case.
*/


/* Approach : 
      - The display_area() function is removed from the Circle class.
      - The display_area() function is declared as virtual in the base class Shape.
      - When shapePtr->display_area() is called in the main() function, the base class version of display_area() is invoked.
      - This leads to the same implementation from the base class being used for all derived classes.
        And this leads to inaccurate results. 
        Note: The display_area() of base class uses the formula dim1*dim2 which in not the correct formula 
              to calculate the area of circle .Also the default value of dim2 = 0.
              Hence giving inaccurate result i.e 0 . 
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

    // Display area made virtual to avoid calling of the same function twice 
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
// Displayed area commented out 
 /*   void display_area() override 
    {
        cout << "Area of Circle : " << M_PI * pow(dim1, 2) << endl;
    }
*/
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
