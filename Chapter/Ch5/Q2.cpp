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
};

int main()
{
    cout << "--------------- VECTOR OPERATIONS ---------------" << endl;
    Vector vect;
    int choice;

    vect.create();

    while (true) // The loop will continue untill user has enetered the correct choice 
    {
        cout << "\nChoose an option:" << endl;
        cout << "1. Modify an element" << endl;
        cout << "2. Multiply vector by scalar" << endl;
        cout << "3. Display the vector" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 4)
        {
            switch (choice)
            {
                case 1:
                    vect.modify(); // call modify() function if the user chooses option 1
                    break;
                case 2:
                    vect.multiply(); // call the multiply() function if the user chooses option 2
                    break;
                case 3:
                    vect.display(); // call the display() function if the user chooses option 3
                    break;
                case 4:
                    cout << "--------- END ----------" << endl; // exit the program if the user chooses option 4
                    return 0;
                default:
                    cout << "Invalid choice! Please enter again." << endl; // display an error message for invalid choices
                    break;
            }
        }
    }

    return 0;
}

