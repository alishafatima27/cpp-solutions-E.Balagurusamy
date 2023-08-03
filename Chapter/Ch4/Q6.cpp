/* Finding largest of three numbers using inline function.
   Test the function using main program.
*/
#include <iostream>
using namespace std;

// Function to find the largest among three numbers using the ternary operator.
// Returns the largest number among 'a', 'b', and 'c'.
inline int max(int a, int b, int c)
{
    return ((a > b && a > c) ? a : (b > a && b > c) ? b : c);
}

int main() 
{
    int x, y, z;

    // Input three numbers from the user
    cout << "Enter the first number: ";
    cin >> x;
    cout << "Enter the second number: ";
    cin >> y;
    cout << "Enter the third number: ";
    cin >> z;

    // Displaying the result
    cout << "The largest among" << x << ", " << y << " and " << z << " is: " << max(x, y, z);

    return 0;
}
