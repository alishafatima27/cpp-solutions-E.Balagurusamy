// Write a program that demonstrates how certain exception types are not allowed to be thrown.

/* This is a very basic program which illustrates that Array of of bound is not anexception in cpp.
   Comment out the try-catch block to see the effect of exception.
   It will produce garbage value for the endex not in range. 
*/
#include <iostream>
using namespace std; 

int main()
{
   int Array[5] = {1,2,3,4,5};
   cout << "Length of array = " << 5 << endl ;  
  int i ; 
  cout << "Enter index greater than 5 or less than 0 to see the exception. \n"; 
  cout << "Enter the index to access the element of array : ";
  cin >> i ;
  try
    {
      if(i>=0 && i<5)
     cout << Array[i] ; 
      else 
        throw i ;    
    }
    catch(int)
    {
      cout << "Array out of index bound is not an exception in cpp"<<endl; 
      cout << "Use try-catch system to handle this exception."; 
    }
}
