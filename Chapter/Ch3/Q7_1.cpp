/*
Write programs to evaluate the following functions to 0.0001% accuracy.
(a) sin x = x - ((x^3)/(3!)) + ((x^5)/(5!)) - ((x^7)/(7!)) + ...
*/

/*Approach to Calculate Sine Using Taylor Series:

   1.  Convert the angle from degrees to radians using the formula: radian_angle = degree_angle * (π / 180).
   2.  Implement a function to calculate the power of a number using a for loop.
   3.  Implement a recursive function to calculate the factorial of a number.
       (note : both power and factorial have common series which is 1 , 3 , 5 ....)
   4.  Implement a function named sin_ts to calculate the sine of the given angle using the Taylor series expansion.
   5.  Initialize variables for the sum, the current term, and a sign variable to alternate the sign of each term.
   6.  Use a for loop to iterate through odd values (1, 3, 5, ...) to calculate each term of the Taylor series.
   7.  Calculate the numerator (power of the angle) and the denominator (factorial of the term) for each term.
   8.  Calculate the current term using the formula: current_term = (numerator) / (denominator) * sign, and add it to the sum.
   9.  Alternate the sign for the next term by multiplying the sign variable by -1.
  10.  Return the final sum, which represents the approximate sine value of the angle in radians.

*/
#include <iostream>
#include <cmath> // defines the value of pi 
#include <iomanip> // defines the precision and width of print zones 
using namespace std;

// Function to calculate the power of a number
float power(float a, int p)
{
    float num = 1;
    for (int i = 1; i <= p; i++)
    {
        num *= a;
    }
    return num;
}

// Function to calculate the factorial of a number
int fact(int x)
{
    if (x == 0)
    {
        return 1;
    }
    else
    {
        return x * fact(x - 1);
    }
}

// Function to calculate sin(x) using Taylor series
float sin_ts(float x_rad)
{
    float terms;
    float sign = 1;
    float sum = 0;

    // Loop to calculate the terms in Taylor series until the desired accuracy is achieved
    for (int i = 1; abs(terms) >= 0.0000001 * abs(sum); i += 2)
    //abs function takes the absolute value and ignores the signs
    {
        // Calculate the numerator and denominator for the current term
        float num = power(x_rad, i);
        float den = fact(i);

        // Calculate the current term
        terms = sign * num / den;

        // Add the term to the sum
        sum += terms;

        // Change the sign for the next term
        sign *= -1;
    }

    return sum;
}

int main()
{
    int x;
    cout << "\n\tEnter angle (degrees): ";
    cin >> x;

    // Ensure the angle is between 0 and 360 degrees
    x = x % 360;

    cout << "\tEquivalent Angle (between 0 to 360) :" << x;

    // Convert the angle to radians
    //Adding the decimal point after 180 ensures that the division is performed
   // as a floating-point division, which gives the correct result.
    float x_rad = x * M_PI / 180.0;

    cout << "\n\tAngle in radian = " << x_rad;

    // Calculate the sin(x) using Taylor series
    float result = sin_ts(x_rad);

    cout << fixed << setprecision(10); // Set the precision to 10 decimal places
    cout << "\n\n\tSin(" << x << ") = " << result;

    return 0;
}
