// Write a program using the find() algorithm to locate the position of a specified value in the sequence container.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target;

    cout << "The sequence container contains: ";
    for (int i : numbers) 
    {
        cout << i << " "; // Print each element from the container
    }

    // Prompt the user to enter the value to search for
    cout << "\nEnter a value to search for: ";
    cin >> target;

    // Use the find() algorithm to locate the position of the specified value
    auto result = find(numbers.begin(), numbers.end(), target);
    // 'auto' keyword is used to automatically deduce the iterator type

    // Check if the value was found
    if (result != numbers.end()) 
    {
        int position = distance(numbers.begin(), result);
        cout << "Value " << target << " found at position " << position << "." << endl;
    }
    else 
    {
        cout << "Value " << target << " not found in the container." << endl;
    }

    return 0;
}
