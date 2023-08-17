/* Design a class Polar which describes a point in the plane using polar coordinates radius and angle. 
   A point in polar coordinates is shown as Point(r, a) where r = radius and a = angle.

   Use the overloaded + operator to add two objects of Polar.

   Note that we cannot add polar values of two points directly. 
   This requires first the conversion of points into rectangular coordinates, then adding the corresponding 
   rectangular coordinates and finally converting the result back into polar coordinates. 
   
   You need to use the following trigonometric formulae:

        x = r * cos(a);
        y = r * sin(a);
        a = atan(y / x); // arc tangent 
        r = sqrt(x * x + y * y);
*/

/* Approach :
    - Define a Class Polar.
    - Initialization of objects using constructor 
      (I have used both default and parametrized constructors)
    - define 4 member i.e 2 for polar cordinates and 2 for rectangular cordinates.
    - Make a function to get input from user which are the two polar cordinates. 
      (Note : User is entering the angle in degree so convert it into radians.
      I have used constant M_PI which is defined in cmath library for the pi.)
    - Function to convert the polar cord to rect cord 
    - Function to convert rect cord to polar cord
    - Operator overloading to add the rect cords
    - function to display the data in both cord 
*/


#include <iostream>   // For input and output stream operations
#include <cmath>      // For mathematical functions like cos, sin, atan2, sqrt
#include <iomanip>    // For formatting output with setprecision
using namespace std;

class Polar
{
private:
    float r, a, x, y;

public:
    Polar(); // Default constructor
    Polar(float rad, float deg, float x_cord, float y_cord); // Parametrized constructor

    void getInput(); // Input function to get polar coordinates from user
    void display_pol(); // Display polar coordinates
    void conv_rect(); // Convert polar coordinates to rectangular coordinates
    void display_rect(); // Display rectangular coordinates
    Polar operator+(Polar); // Overloaded + operator to add polar coordinates
    void conv_pol(); // Convert rectangular coordinates back to polar coordinates
};

// Default Constructor
Polar::Polar()
{
    r = 0;
    a = 0;
    x = 0;
    y = 0;
}

// Parameterized Constructor
Polar::Polar(float rad, float deg, float x_cord, float y_cord)
{
    r = rad;
    a = deg;
    x = x_cord;
    y = y_cord;
}

// Input function to get polar coordinates from user
void Polar::getInput()
{
    cout << "Enter radius: ";
    cin >> r;
    cout << "Enter angle in degrees: ";
    cin >> a;
}

// Display polar coordinates
void Polar::display_pol()
{
    cout << "Polar coordinates: ( " << fixed << setprecision(3) << r << " , " << fixed << setprecision(3) << a << " degrees)" << endl;
}

// Convert polar coordinates to rectangular coordinates
void Polar::conv_rect()
{
    // Convert angle from degrees to radians
    float a_rad = a * M_PI / 180.0;

    // Convert polar coordinates to rectangular coordinates
    x = r * cos(a_rad);
    y = r * sin(a_rad);
}

// Display rectangular coordinates
void Polar::display_rect()
{
    cout << "Rectangular coordinates: (x = " << fixed << setprecision(3) << x << ", y = " << fixed << setprecision(3) << y << ")" << endl;
}

// Overloaded + operator to add polar coordinates
Polar Polar::operator+(Polar p)
{
    Polar sum;
    // Add rectangular coordinates of two polar coordinates
    sum.x = x + p.x;
    sum.y = y + p.y;
    sum.conv_pol(); // Convert the sum back to polar coordinates
    return sum;
}

// Convert rectangular coordinates back to polar coordinates
void Polar::conv_pol()
{
    // Convert rectangular coordinates back to polar coordinates
    a = atan2(y, x) * 180.0 / M_PI; // Convert angle to degrees
    r = sqrt(x * x + y * y); // Calculate new radius
}

int main()
{
    Polar p1, p2, p3;

    cout << "Enter polar coordinates for p1:" << endl;
    p1.getInput();
    p1.conv_rect(); // Convert p1 to rectangular coordinates
    p1.display_pol();
    p1.display_rect();

    cout << "\nEnter polar coordinates for p2:" << endl;
    p2.getInput();
    p2.conv_rect(); // Convert p2 to rectangular coordinates
    p2.display_pol();
    p2.display_rect();

    p3 = p1 + p2; // Add p1 and p2 polar coordinates
    cout << "Sum of polar coordinates p1 and p2:" << endl;
    p3.display_pol();

    return 0;
}
