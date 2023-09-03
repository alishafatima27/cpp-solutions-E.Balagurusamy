/* Write a program to find the value of e in the following series 
   e = 1 + 1/(1!) + 1/(2!) + 1/(3!) +  ..... upto acc = 0.0001 
*/

/* Approach : 
       Progam gives the output using manipulators defined in <iomanip> header file.
       Here I have used two manipultors i.e s
            - setw() : sets the width 
                        width() can also be used from ios class 
            - setiosflags(ios::scientific) : displays output in scientific notion 
*/ 


#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Function to calculate factorial
double factorial(int n) 
{
    if (n <= 1) 
    {
        return 1.0;
    } else 
    {
        return n * factorial(n - 1);
    }
}

int main() 
{
    double e = 1.0;  // Initialize e to 1.0, the first term in the series
    double term = 1.0;
    int n = 1;

    // Set the desired accuracy
    double accuracy = 0.0001;

    while (abs(term) >= accuracy) 
    {
      
        // Calculate the next term in the series
        term = 1.0 / factorial(n);
      
        // Add the term to e
        e += term;  

        // Increment n for the next term
        n++;
    }

    cout << "Approximate value of e: " << setw(15) << setiosflags(ios::scientific) << e << endl;

    return 0;
}
