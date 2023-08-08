/* Modify the class and program of Exercise 5.2 such that the program would be able to add two vectors 
   and display the resultant vector. (Note that we can pass objects as function arguments.) 
*/

/*Q2  Write a class to represent a vector (a series of float values). Include member functions to perform the following tasks:

   (a) To create a vector
   (b) To modify the value of a given element
   (c) To multiply by a scalar value
   (d) To display the vector in the form (10, 20, 30, ...)

   Write a program to test your class.
*/ 
/* Write a class to represent a vector (a series of float values). Include member functions to perform the following tasks:

   (a) To create a vector
   (b) To modify the value of a given element
   (c) To multiply by a scalar value
   (d) To display the vector in the form (10, 20, 30, ...)

   Write a program to test your class.
*/ 
#include <iostream>
#include <vector>
using namespace std;

class Vector 
{
    vector<int> data; // vector data type to store integer elements
    int n; // to store the number of elements in the vector

public:
    void create()
    {
        cout << "Enter the size of the vector: "; 
        cin >> n; 
        for (int i = 0; i < n; i++)
        {
            int value;
            cout << "Enter element " << i + 1 << ": "; 
            cin >> value;
            data.push_back(value); // push_back() add elements to the vector
        }
    }

    void modify()
    {
        int index, new_value;
        cout << "Modifying the vector:" << endl;
        cout << "Enter the index of the vector to modify: ";
        cin >> index;

        if (index >= 0 && index < n)
        {
            cout << "Enter the new element to be inserted at index " << index << ": ";
            cin >> new_value;
            data[index] = new_value; // modifies the element at the given index
            cout << "Element at index " << index << " has been modified." << endl;
        }
        else 
        {
            cout << "Invalid index! Please enter a valid index between 0 and " << n-1 << " ." << endl;
        }
    }

    void multiply()
    {
        float scalar;
        cout << "Enter the scalar value: ";
        cin >> scalar;

        for (int i = 0; i < n; i++)
        {
            // multiply each element by the scalar and convert it to float to preserve decimal points
            data[i] = static_cast<float>(data[i]) * scalar; 
        }
    }

    void display()
    {
        cout << "--------- The elements of the vector are: ----------" << endl;
        cout << "( ";
        for (int i = 0; i < n; i++)
        {
            cout << data[i];
            
            // I will use this logic to add a comma after each element except the last one
            if (i < n - 1)
            {
                cout << ", ";
            }
        }
        cout << " )" << endl;
    }
    void add(const Vector& v1, const Vector& v2) {
    if (v1.n != v2.n) {
        cout << "Vector sizes do not match. Addition is not possible." << endl;
        return;
    }

    // Initialize the size of the resultant vector
    n = v1.n;
    data.clear(); // Clear existing data

    // Add the corresponding elements of v1 and v2 and store in the resultant vector
    for (int i = 0; i < n; i++) {
        data.push_back(v1.data[i] + v2.data[i]);
    }
}



};

int main()
{
    cout << "--------------- VECTOR OPERATIONS ---------------" << endl;
    Vector vect1 , vect2 , resultant ; 
    int choice;

    vect1.create();
    vect2.create();
    resultant.add(vect1 , vect2) ; 
    resultant.display() ; 
}

