/* Define two classes Polar and Rectangle to represent points in the polar and rectangle systems.
   Use conversion routines to convert from one system to the other.
*/

#include <cmath>     // For mathematical functions like cos, sin, sqrt
#include <iostream>  // For standard input and output operations
#include <iomanip>   // For controlling output formatting 

using namespace std;

// Forward declaration of the Polar class
class Polar;

// Rectangle class to represent rectangular coordinates
class Rectangle {
    float x_cord;  // x-coordinate
    float y_cord;  // y-coordinate

public:
    // Constructors
    Rectangle();
    Rectangle(float x, float y);

    // Input and display functions
    void Input();
    void Display(Polar &pol); //Paased object of Polar class as refrence variable to access it member for dislaying

    // Accessor functions for x and y coordinates
    float Access_x();
    float Access_y();

    // Conversion function to convert to Polar coordinates
    Polar toPolar();

    // Friend class declaration for Polar to access Rectangle members
    friend class Polar;
};

// Polar class to represent polar coordinates
class Polar {
    float angle;   // Angle in degrees
    float radius;  // Radius

public:
    // Constructors
    Polar();
    Polar(float a, float rad);

    // Input and display functions
    void Input_p();
    void Display_p(Rectangle &rect); //Paased object of rectangle as refrence variable to access it member for dislaying

    // Accessor functions for angle and radius
    float Access_a();
    float Access_r();

    // Conversion function to convert to Rectangle coordinates
    Rectangle toRectangle();

    // Friend class declaration for Rectangle to access Polar members
    friend class Rectangle;
};

// Implementations of Rectangle class methods

Rectangle::Rectangle() {
    x_cord = 0;
    y_cord = 0;
}

Rectangle::Rectangle(float x, float y) {
    x_cord = x;
    y_cord = y;
}

void Rectangle::Input() {
    cout << "Enter the length of rectangle: ";
    cin >> x_cord;
    cout << "Enter the breadth of rectangle: ";
    cin >> y_cord;
}

void Rectangle::Display(Polar &pol) {
    cout << "\nLength of rectangle = " << x_cord << endl;
    cout << "Breadth of rectangle = " << y_cord << endl;
    cout << "Rectangular coordinates of (" << fixed << setprecision(3) << pol.Access_a() << " degree , " << fixed << setprecision(3) << pol.Access_r() << ") = "
         << "( " << x_cord << " , " << y_cord << " )" << endl;
}

float Rectangle::Access_x() {
    return x_cord;
}

float Rectangle::Access_y() {
    return y_cord;
}

Polar Rectangle::toPolar() {
    float r = sqrt(x_cord * x_cord + y_cord * y_cord);
    float a = atan2(y_cord, x_cord) * 180 / M_PI;
    return Polar(a, r);
}

// Implementations of Polar class methods

Polar::Polar() {
    angle = 0;
    radius = 0;
}

Polar::Polar(float a, float rad) {
    angle = a;
    radius = rad;
}

void Polar::Input_p() {
    cout << "\nEnter the angle: ";
    cin >> angle;
    cout << "Enter the radius: ";
    cin >> radius;
}

void Polar::Display_p(Rectangle &rect) {
    cout << "\nPolar coordinates of (" << fixed << setprecision(3) << rect.Access_x() << " , " << fixed << setprecision(3) << rect.Access_y() << ") = "
         << "( " << radius << ", " << angle << " degree )" << endl;
}

float Polar::Access_r() {
    return radius;
}

float Polar::Access_a() {
    return angle;
}

Rectangle Polar::toRectangle() {
    float x_cord = radius * cos(angle * M_PI / 180);
    float y_cord = radius * sin(angle * M_PI / 180);
    return Rectangle(x_cord, y_cord);
}

// Main function

int main() {
    Rectangle r, r_conv;
    Polar p, p_conv;

    // Input rectangle coordinates and convert to Polar
    r.Input();
    p_conv = r.toPolar();
    p_conv.Display_p(r);

    // Input Polar coordinates and convert to Rectangle
    p.Input_p();
    r_conv = p.toRectangle();
    r_conv.Display(p);

    return 0;
}
