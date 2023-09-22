/* Define a namespace named "Constants" that contains declarations of some constants.
   Write a program that uses the constants defined in the namespace "Constants".
*/

#include <iostream>
using namespace std ; 

namespace Constants
{
    double pi = 3.14159265359 ; 
    double e = 2.71828182846 ;
}

int main()
{ 
    cout << "Some mathematical constant defined using namespace \"Constants\" : " << endl ; 
    cout << "Value of PI = " << Constants :: pi << endl ; 
    cout << "Value of e : " << Constants :: e << endl ; 
}
