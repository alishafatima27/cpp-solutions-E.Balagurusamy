/* Write a program containing a possible exception. Use a try 
   block to throw it and catch block to handle it properly.
*/ 


/* Appraoch : 
        This program illustrates the use try block and catch block to catch the exception division by zero.
        The program enters a try block to perform division.
           -Inside the try block:
                - It checks if b is not equal to zero.
                - If b is not zero, it performs the division a / b and displays the result.
                - If b is zero, it throws an exception by using throw b;.
           -The catch block is used to handle the exception:
                - It catches the exception as a float (float f) to match the type of b that was thrown.
                - It displays an error message indicating that a division by zero exception has been caught.
*/


#include <iostream>
using namespace std;

int main() {
    float a, b;
    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;
    try  // try block 
    {
        if (b != 0) 
        {
            cout << "Division = " << a / b << "\n";
        } else 
        {
            throw b; // Throw the float value
        }
    } catch (float f)  // Catch as float
    {
        cout << "EXCEPTION CAUGHT: Divide by zero!\n";
    }

    return 0;
}
