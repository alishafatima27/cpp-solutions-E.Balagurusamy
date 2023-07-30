/*
  Write a program to print a table of values of the function 
  y = e^(-x) for x varying from 0 to 10 in steps of 0.1. The table should appear as follows.

  Table for Y = EXP[-X]
---------------------------------------------------------------
|  X   0.1   0.2   0.3   0.4   0.5   0.6   0.7   0.8    0.9   |
---------------------------------------------------------------
| 0.0 |     |     |     |     |     |     |     |     |       |
| 1.0 |     |     |     |     |     |     |     |     |       | 
|  .  |     |     |     |     |     |     |     |     |       |
|  .  |     |     |     |     |     |     |     |     |       |
| 9.0 |     |     |     |     |     |     |     |     |       |
---------------------------------------------------------------
  */
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    // Print the table header
    cout << "Table for Y = EXP[-X]" << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << "|  X   0.1   0.2   0.3   0.4   0.5   0.6   0.7   0.8    0.9   |" << endl;
    cout << "---------------------------------------------------------------" << endl;

    // Loop to calculate and print the values of y for each x
    for (double x = 0.0; x <= 9.0; x += 1.0)
    {
        cout << "| " << setw(3) << fixed << setprecision(1) << x << " ";

        // Inner loop to calculate and print the y values for each step of 0.1 from 0.1 to 0.9
        for (double step = 0.1; step <= 0.9; step += 0.1)
        {
            // Calculate the value of y using the exponential function exp(-x)
            double y = exp(-x);

            // Print the value of y with proper formatting
            cout << "| " << setw(5) << fixed << setprecision(3) << y << " ";
        }

        cout << "|" << endl;
    }

    // Print the table footer
    cout << "---------------------------------------------------------------" << endl;

    return 0;
}

