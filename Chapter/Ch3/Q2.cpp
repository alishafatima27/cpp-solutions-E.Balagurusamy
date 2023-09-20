// Creating a vector of user given size using a new operator.

/* new is a memory management operator.
   New and delete are also known as free store operators.
*/



#include <iostream>
#include <vector>
using namespace std;

int main()
{
   int size; 
   

   cout << "Enter the size of vector : ";
   cin >> size ; 

   int *vector = new int[size] ; // dynamic memory allocation of vector using new operator

   for (int i = 0 ; i < size ; i++ )
   {
        cout << "Enter the vector: ";
        cin >> vector[i];
   }
   cout << "Vector : "
   for (int i = 0 ; i < size ; i++)
   {
        cout << vector[i] << " ";
   }
   return 0;
}
