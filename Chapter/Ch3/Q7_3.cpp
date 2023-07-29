//(c)cos x = 1 - ((x^2)/(2!)) + ((x^4)/(4!)) - ((x^6)/(6!)) + ...
//Program to calculate value of cos using taylor series 

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Function to calculate the factorial of a number
// This function is used to calculate the terms of the Taylor series.
// It takes an integer as input and returns the factorial of that number.
int fact(int z)
{
    if (z == 0)
    {
        return 1;
    }
    else
    {
        return z * fact(z - 1);
    }
}

// Function to calculate the cosine using the Taylor series expansion
float cos_ts(float a)
{
    float terms = 1.0;
    float sum = 1.0;
    int sign = -1;

    // Display the first term and the sum up to the first term
    cout << "Term 1 = " << terms << endl
         << "Sum up to term 1: " << sum << endl;

    // Calculate the cosine using Taylor series expansion until the terms become negligible
    for (int i = 2; abs(terms) >= 0.000001 * abs(sum); i += 2)
    {
        // Calculate the current term using the formula: (-1)^n * (x^n) / n!
        terms = sign * pow(a, i) / fact(i);
        
        // Add the current term to the sum
        sum += terms;
        
        // Display the current term and the sum up to the current term
        cout << "\n\nTerm = " << terms << endl
             << "Sum up to current term = " << sum << endl;

        // Alternate the sign for the next term (alternating series)
        sign *= -1;
    }

    return sum; // Return the final sum (approximation of cosine)
}

int main()
{
    int x;
    float x_rad;
    float result;

    // Input: Angle in degrees
    cout << "Enter the angle in degrees: ";
    cin >> x;
    
    // Normalize the angle to the range [0, 360)
    x = x % 360;
    cout << "Value of x in standard form = " << x << endl;

    // Convert the angle to radians
    x_rad = static_cast<float>(x) * M_PI / 180;
    cout << "Value of angle in radians: " << x_rad << endl;

    // Calculate cosine using the Taylor series expansion
    result = cos_ts(x_rad);
    cout << "\n\n\t-------------The value of cos(" << x << ") = " << fixed << setprecision(6) << result << "-------------\n";

    return 0; // Indicate successful program execution
}
