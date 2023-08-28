/* Using the concept of pointers, write a function that swaps the 
   private data values of two objects of the same class type.
*/ 


#include <iostream>
using namespace std;

class Swap
{
private:
    int *a, *b;

public:
    Swap()
    {
        a = new int;
        b = new int;
    }

    void getdata()
    {
        cout << "Enter the first number : ";
        cin >> *a;
        cout << "Enter second number : ";
        cin >> *b;
    }

    void swap_data()
    {
        *a = *a + *b;
        *b = *a - *b;
        *a = *a - *b;
    }

    void display()
    {
        cout << "Number 1 : " << *a << endl;
        cout << "Number 2 : " << *b << endl;
    }

    ~Swap()
    {
        delete a;
        delete b;
    }
};

int main()
{
    Swap obj;
    obj.getdata();
    cout << "\nNumber before swapping : " << endl;
    obj.display();
    obj.swap_data();
    cout << "\nNumber after swapping : " << endl;
    obj.display();
    return 0;
}
