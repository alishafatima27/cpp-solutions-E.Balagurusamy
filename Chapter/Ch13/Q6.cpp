/* Write a program with the following :
      (a)  A function to read double type numbers from keyboards.
      (b)  A function to calculate the division of these two numbers.
      (c)  A try block to throw an exception when a wrong data type is keyed in.
      (d)  A try block to detect and throw an exception if the condition "divide-by-zero" occurs.
      (e)  Appropriate catch block to handle the exceptions thrown.
*/


#include <iostream>
using namespace std;

void read(double m , double n)
{
    try
    { 
        cout << "Enter the first double value : ";
        cin >> m ;
        cout << "Enter the second double value : ";
        cin >> n ;
        if(!m)
        {
            throw m ; 
        }
        if(!n)
        {
            throw n ; 
        }
        
    }
    catch(double)
    {
        cout << "Exception ! Incorrect data type." << endl ;
    }
    
}

int division(double d , double e)
{
    try
    {
        if(e==0)
        {
            throw e ; 
        }
        else
        {
            return d/e ; 
        }
    }
        
        catch(double)
        {
            cout << "Exception! Divide by zero.";
        }
}

int main()
{
    double d , e ; 
    read(d , e);
    cout << division(d , e);
}
