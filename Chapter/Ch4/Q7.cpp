/* Write a function power() to raise a number m to power n. The function takes a double value for m and int n,
   and returns the result correctly. 
   Use default value of 2 for n to make the function calculate squares when this argument is omitted.
   Write a main that gets a values of m and n from the user to test the function.
*/

#include <iostream>
#include <string>
using namespace std;

// Function to calculate the power of a number 'm' raised to an integer exponent 'n'
double calculatePower(double m, int n)
{
    if (n == 0 || m == 1)
    {
        return 1;
    }
    else
    {
        return m * calculatePower(m, n - 1); // Return the result of m times m^(n-1)
    }
}

// Overloaded function to calculate the square of a number
double calculatePower(double m)
{
    return m * m;
}

int main()
{
    double base;
    int power;

    cout << "Enter the base number: ";
    cin >> base;

    // Ignore any characters in the input buffer before reading the exponent value
    cin.ignore();

    cout << "Enter the exponent (press Enter to calculate square): ";

    string input;
    getline(cin, input);

    // If the input is empty (i.e., the user pressed Enter without entering any value),
    // calculate the square of the number.
    if (input.empty())
    {
        double result = calculatePower(base);
        cout << "Square of " << base << " is: " << result;
    }
    else
    {
        // If the input is not empty, parse it as an integer to calculate the power.
        power = stoi(input);
        double result = calculatePower(base, power);
        cout << base << " raised to power " << power << " is: " << result;
    }

    return 0;
}
