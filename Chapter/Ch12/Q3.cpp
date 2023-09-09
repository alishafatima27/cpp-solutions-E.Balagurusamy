// Write a function template to perform linear search in an array 


#include <iostream>
using namespace std;

template <typename T>
int LinearSearch(const T arr[], int size, const T& val) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == val) {
            return i; // Element found, return its index
        }
    }
    return -1; // Element not found, return -1
}

int main() {
    int size, val;

    // Input the size of the array
    cout << "Enter the size of the array: ";
    cin >> size;

    // Input array elements
    int intArray[size];
    cout << "Enter " << size << " integer values:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> intArray[i];
    }

    // Input the element to search
    cout << "Enter the element to search for: ";
    cin >> val;

    // Perform linear search
    int result = LinearSearch(intArray, size, val);

    // Check if the element was found
    if (result != -1) {
        cout << "Element " << val << " found at index " << result << endl;
    } else {
        cout << "Element " << val << " not found in the array." << endl;
    }

    return 0;
}
