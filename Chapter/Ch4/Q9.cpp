/* write a function to calculate area of triangle and circle by overloading the area() 
*/ 

/*
  Compiler when sees the functions(function polymorphism) with same name, it tries to find the best match by checking : 
     1) Number of argumnets passed 
     2) Data types of Argument 
  If the match is not found then it uses 
      Integral promotion to find best match (i.e Char to int , float to double ) 
  Note : Int cannot be implicitly converted to double or long 
*/

#include <iostream>
#include <cmath>
using namespace std;

// Function prototypes for calculating the areas
float area(float r);
float area(float r, float h);

// Function to calculate the area of a circle
float area(float r)
{
    return (M_PI * r * r);
}

// Function to calculate the lateral surface area of a cylinder
float area(float r, float h)
{
    return 2 * M_PI * r * (r + h);
}

int main()
{
    float rad_cir, rad_cyl, h;

    cout << "Enter radius of circle: ";
    cin >> rad_cir;

    cout << "Enter radius of cylinder: ";
    cin >> rad_cyl;

    cout << "Enter height of the cylinder: ";
    cin >> h;

    cout << "Area of circle: " << area(rad_cir) << endl;

    cout << "Area of Cylinder: " << area(rad_cyl, h) << endl;

    return 0;
}
