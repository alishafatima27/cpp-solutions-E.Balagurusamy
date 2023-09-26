/* Write a function power() to raise a number m to power n. The function takes a double value for m and int n,
   and returns the result correctly. 
   Use default value of 2 for n to make the function calculate squares when this argument is omitted.
   Write a main that gets a values of m and n from the user to test the function.
*/

#include <iostream>
#include <string>
using namespace std;

// Function to calculate the power of a number 'm' raised to an integer exponent 'n'
double calculatePower(float m, int n)
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

int main()
{
    double base;
    int power;

    cout << "Enter the base number: ";
    cin >> base;

    // Ignore any characters in the input buffer before reading the exponent value
    cin.ignore();

    cout << "Enter the exponent (press Enter to use the default value of 2): ";

    string input;
    getline(cin, input);

    // If the input is empty (i.e., the user pressed Enter without entering any value),
    // set the default exponent value of 2.
    if (input.empty())
    {
        power = 2;
    }
    else
    {
        bool isInteger = true; // Initialize the boolean variable as true

        // Check if each character in the input is a digit
        for (char c : input)
        {
            if (!isdigit(c)) // If a character is not a digit
            {
                isInteger = false; // Set the boolean variable to false
                break; // Exit the loop
            }
        }

        if (isInteger) // If the input consists of only digits
        {
            // Convert the input string to an integer
            power = stoi(input);
        }
        else
        {
            cout << "Invalid input for exponent. Using default value of 2." << endl;
            power = 2;
        }
    }

    double result = calculatePower(base, power);

    cout << base << " raised to power " << power << " is: " << result;

    return 0;
}
