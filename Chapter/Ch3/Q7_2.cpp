
//(b) SUM = 1 + ((1/2)^2) + ((1/3)^3) + ((1/4)^4) + ...

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std; 

// Function to calculate the power of a number
double power(double base, double exponent) // This function is just for demonstration purposes and is not being used.
{
    double result = 1.0; //Every number is a multiple of 1. 3*1=3 etc...
    for (int i = 1; i <= exponent; i++)
    {
        result *= base;
    }
    return result;
}


// Function to calculate the sum of the series
float sum()
{
    double terms = 1.0, sum = 0.0; // to avoid truncation, initialized with double data type 
    cout << " terms 1 of the series : " << terms << endl ; 
    /*If we initialize i with an int , the division 1.0 / i will be an integer division.
    It will truncate the decimal part. To avoid this error and ensure floating-point division, 
    we should initialize i with a double value of 1.0*/
  
    for(double i = 2 ; terms > 0.000001*sum ; i++) 
    {
        // Calculate the current term: (1/i)^i
        terms = (pow(1/i,i)); // pow function defined in cmath library.
      // To use user defined power function simply replace pow with power 
      
        cout << "Term "<<i<<" of the series : (1/" << i << ")^"<<i<<" = "<< terms <<endl; 

        // Add the current term to the sum
        sum += terms; 
        cout << "sum upto " << i << " th term : " << sum << "\n\n" << endl; 
    }
    return sum ; // Return the final sum
}
int main()
{
    cout << "Total Sum of the series upto 0.0001% accuracy = " << sum() ; 
    return 0 ; // Indicate successful program execution
}
