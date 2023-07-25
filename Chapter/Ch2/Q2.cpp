#include <iostream>
using namespace std;
int main()
{

    int a , b , max=0; 
    cout << "Enter first number : "<<endl;
    cin >> a ;
    cout << "Enter second number : "<<endl;
    cin >> b ;
    a>b ? max=a : max=b ;
    cout << max << "is greater among "<< a <<" and"<<b; 

}
