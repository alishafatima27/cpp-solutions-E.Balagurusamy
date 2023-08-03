/* Q7 :  Write a function power() to raise a number m to power n. The function takes a double value for m and int n,
         and returns the result correctly. 
         Use default value of 2 for n to make the function calculate squares when this argument is omitted.
         Write a main that gets a values of m and n from the user to test the function.

    Q8 : Write a function to perform same operation as above but takes int value for m.
         Both functions should have same name.Write a main that calls both functions.
         Use concept of function overloading. 
*/

#include <iostream>
#include <string>
using namespace std;

// Function prototyping 
double pow(double m, int n);
int pow(int m, int n);

// Function definition
double pow(double m, int n)
{
    if (n == 0 || m == 1)
    {
        return 1;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            return m * pow(m, n - 1); // Recursive call to calculate the power
        }
    }
}

// Function definition for integer
int pow(int m, int n)
{
    if (n == 0 || m == 1)
    {
        return 1;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            return m * pow(m, n - 1); // Recursive call to calculate the power
        }
    }
}

int main()
{
    double base;
    int power;

    cout << "Enter the base number: ";
    cin >> base;

    // Input the exponent (press any char to use the default value of 2)
    cout << "Enter the exponent (press any char to use the default value of 2): ";
    cin >> power;

    // If the user doesn't enter a number, setting power to the default value of 2.
    if (!cin)
    {
        power = 2;
        cout << "\t---------Power set to default value i.e., 2-----------\n\n";
    }

    // Calculate and display the power for both double and integer bases
    cout << "\t----------This is the function ---------\n";
    cout << "\t" << "base" << " raised to power " << "power" << " is with base as double: " << pow(base, power) << endl;
    cout << "\n\n\t" << "----------This is achieved through function overloading---------\n";
    cout << "\t" << "base" << " raised to power " << "power" << " is with base as int: " << pow(static_cast<int>(base), power);

    return 0;
}
