// Write a program that demonstrate the concept of rethrowing an exception.


#include <iostream>
using namespace std; 

void divide(double x , double y)
{
    cout << "Inside function " << endl;
    try
    {
        if(y==0.0)
          throw y;
        else
          cout << "Division = " << x/y << endl ; 
    }
    catch(double)
    {
        cout << "Caught double inside function"<< endl ; 
        throw ;
    }
    cout << "End of function \n\n";
}

    
int main()
{
  cout << "Inside main \n" ;
  try
  {
      divide(10.5,2.0);
      divide(20.0,0.0);
  }
  catch(double)
  {
      cout << "Caught double inside main \n" ; 
  }
      cout << "End of main\n";
      return 0 ; 
  }
