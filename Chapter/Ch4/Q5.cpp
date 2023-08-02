/* -------Finding largest of three numbers using macro--------

  A macro in C++ is a preprocessor directive that defines a simple function-like behavior at compile time.
  It is defined using #define directive.
*/


#include <iostream>

// Define a preprocessor macro called 'max' to find the maximum among three numbers.
// The macro takes three arguments: x, y, and z, representing the three input numbers.
// The macro uses the ternary operator to compare the three numbers and return the maximum.
#define max(x, y, z) ((x > y && x > z) ? x : (y > x && y > z) ? y : z)

using namespace std;

int main()
{
    int x, y, z;

    cout << "Enter the first number: ";
    cin >> x;

    cout << "Enter the second number: ";
    cin >> y;

    cout << "Enter the third number: ";
    cin >> z;

    // Use the 'max' macro to find the maximum among the three input numbers.
    // The macro will compare 'x', 'y', and 'z' using the ternary operator and return the maximum value.
    cout << "The maximum number is: " << max(x, y, z);

    return 0;
}
