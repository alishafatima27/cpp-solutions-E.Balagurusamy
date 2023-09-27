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

#include <iostream>
using namespace std;

class Vector {
    float *data; // Vector data type to store float elements
    int n;       // Number of elements in the vector

public:
    Vector() {
        data = nullptr;
        n = 0;
    }

    void create() {
        cout << "Enter the size of the vector: ";
        cin >> n;
        data = new float[n];
        for (int i = 0; i < n; i++) {
            cout << "Enter element " << i + 1 << ": ";
            cin >> data[i];
        }
    }

    void modify() {
        int index, new_value;
        cout << "Modifying the vector:" << endl;
        cout << "Enter the index of the vector to modify: ";
        cin >> index;

        if (index > 0 && index <= n) {
            cout << "Enter the new element to be inserted at index " << index << ": ";
            cin >> new_value;
            data[index - 1] = new_value; // Indexing in the array starts from 0
            cout << "Element at index " << index << " has been modified." << endl;
        } else {
            cout << "Invalid index! Please enter a valid index between 1 and " << n << "." << endl;
        }
    }

    void multiplyScalar(float scalar) {
        for (int i = 0; i < n; i++) {
            data[i] = data[i] * scalar;
        }
    }

    void addVector(const Vector &other) {
        if (n != other.n) {
            cout << "Vector addition is not possible. Vectors have different sizes." << endl;
            return;
        }

        for (int i = 0; i < n; i++) {
            data[i] += other.data[i];
        }
    }

    void display() {
        cout << "\n--------- The elements of the vector are: ----------" << endl;
        cout << "( ";
        for (int i = 0; i < n; i++) {
            cout << data[i];

            // Add a comma after each element except the last one
            if (i < n - 1) {
                cout << ", ";
            }
        }
        cout << " )" << endl;
    }
};

int main() {
    cout << "--------------- VECTOR OPERATIONS ---------------" << endl;
    Vector vector1, vector2;
    int choice;

    cout << "Vector 1:" << endl;
    vector1.create();
    vector1.display();

    cout << "\nVector 2:" << endl;
    vector2.create();
    vector2.display();

    while (true) {
        cout << "\nChoose an option:" << endl;
        cout << "1. Modify an element in Vector 1" << endl;
        cout << "2. Multiply Vector 1 by a scalar" << endl;
        cout << "3. Add Vector 1 and Vector 2" << endl;
        cout << "4. Display Vector 1" << endl;
        cout << "5. Display Vector 2" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                vector1.modify();
                break;
            case 2:
                float scalar;
                cout << "Enter the scalar value: ";
                cin >> scalar;
                vector1.multiplyScalar(scalar);
                break;
            case 3:
                vector1.addVector(vector2);
                cout << "Vector 1 + Vector 2:" << endl;
                vector1.display();
                break;
            case 4:
                vector1.display();
                break;
            case 5:
                vector2.display();
                break;
            case 6:
                cout << "--------- END ----------" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please enter again." << endl;
                break;
        }
    }
    return 0;
}
