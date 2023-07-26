// Creating a vector of user given size M using a new operator.
#include <iostream>
using namespace std;
//new is a memory management operator.
//New and delete are also known as free store operators.
//The answer to this question might be wrong maybe so any changes are most welcome
int main()
{
   int M; 
   int *vect;

   cout << "Enter the size of vector : ";
   cin >> M ; 

   vect = new int[M]    ;
     for (int i = 0 ; i<M; i++ )
  {
    cout << "Enter the vector: ";
    cin >> vect[i];
    
  }
    for (int i = 0 ; i <M ; i++)
    {
        cout << vect[i] <<endl;
    }
  return 0;
}
