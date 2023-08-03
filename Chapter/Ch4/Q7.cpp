/* Write a function power() to raise a number m to power n. The function takes a double value for m and int n,
   and returns the result correctly. 
   Use default value of 2 for n to make the function calculate squares when this argument is omitted.
   Write a main that gets a values of m and n from the user to test the function.
*/

#include <iostream>
#include <string>
using namespace std;

// Function to calculate the power of a number 'm' raised to an integer exponent 'n'
double pow(float m, int n)
{
    if (n == 0 || m == 1)
    {
        return 1;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            return m * pow(m, n - 1);
        }
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
        /*
         Suppose you entered '2ed6'
         this loop will iterate over each character individually 
         i.e first for 2 then check if 2 is integer or not.
         if yes then secnd iteration will take place.
         if second char is not digit then the value of boolean becomes false and loop will break.
        */
        bool isInteger = true; // initialization of boolean variable 
        for (char c : input) // iterates over each character of the input
        {
            if (!isdigit(c)) // condition : not a digit  
            {
                isInteger = false; // value is false otherwise true 
                break;
            }
        }

            cout << "Invalid input for exponent. Using default value of 2." << endl;
            power = 2;
        
    }

    double result = pow(base, power);

    cout << base << " raised to power " << power << " is: " << result;

    return 0;
}
