/* Write a class template to represent a generic vector .
   Include memberfunctions to perform the following tasks : 
   (a)  To create the vector.
   (b)  To modify the value of a given element 
   (c)  To multiply by a scalar value
   (d)  To display the vector in the form (10,20,30,....) 
*/


#include <iostream>

using namespace std;

template <class T>
class Vector 
{
    int size ; 
    T *A ;  // Change int to T* to store elements of type T 
public : 
    void getdata();
    void display();
    void modify(int pos , int val);
    void multiply(int scalar); 
}; 

template <class T>
void Vector<T>::getdata()
{
    int s ; 
    cout << "Enter size of vector : ";
    cin >> s ; 
    this->size = s ;  // Use this->size to access the class member
    A = new T[size];  // Dynamically allocate memory for the array
    for(int i = 0; i < size; i++)
    {
       cout << "Enter element " << i << " : ";
       cin >> A[i]; 
    }
}

template <class T>
void Vector<T>::display()
{
    cout << "\n( " ; 
    for(int i = 0 ; i < size ; i++)
    {
        cout << A[i];
        if (i < size - 1) {
            cout << " , ";
        }
    }
    cout << " )" << endl ;
}

template <class T>
void Vector<T>::modify(int pos ,int val )
{
    A[pos] = val; 
}
template <class T> 
void Vector<T> ::multiply(int scalar)
{
    for (int i = 0 ; i < size ;i++)
    {
        A[i] = scalar*A[i];
    }
   // return A ; 
}

int main()
{
    Vector<int> T;  // Create a Vector of integers
    T.getdata();
    T.display();
    int pos , val ; 
    cout << "Enter the position of element for modification : ";
    cin >> pos ; 
    cout << "Enter the modified value : ";
    cin >> val ;
    T.modify(pos , val);
    cout << "\nAfter modification : " << endl;
    T.display();
    int scalar ; 
    cout<< "Enter a scalar : " << endl ;
    cin >> scalar ; 
    T.multiply(scalar);
    cout << "Scalar multiplication: " << endl ; 
    T.display();
    
    return 0;
}
