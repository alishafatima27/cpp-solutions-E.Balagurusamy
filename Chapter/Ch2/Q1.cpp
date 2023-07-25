#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    
    int a , b , c ;
    cout <<" Enter the marks : "<< endl;
    cin >> a >> b >> c ;
    cout << setw(50) << "Maths = "<< a << endl << setw(50) << "Physics = "<< b <<endl<<setw(50) << "Chemistry = "<< c << endl ;
	return 0;

}
