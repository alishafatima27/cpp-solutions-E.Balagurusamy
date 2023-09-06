// Write a function template for finding the minimum value contained im array 


#include <iostream>
using namespace std;

template <class T> //necessary declaration for template function 
T FindMin(T a[], int n) // return type is T 
{
    T min = a[0]; // declared min of T data type 
    for (int i = 1; i < n; i++)
    {
        if (min > a[i])
        {
            min = a[i];
        }
    }
    return min;
}

int main()
{
    int n;
    cout << "Enter size of Array: ";
    cin >> n;
    
    int a[n];  
    
    cout << "Enter Elements of array:" << endl;
    
    for (int i = 0; i < n; i++)
    {
        cout << "Enter array[" << i << "]: ";
        cin >> a[i];
    }
    
    int min = FindMin(a, n); //Calling Template function 
    
    cout << "Minimum value in the array is: " << min << endl;
    
    return 0;
}
