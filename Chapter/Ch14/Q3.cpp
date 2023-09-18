// Write a program using count() algorithm to count how many elements in a container have a specified value. 


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5, 2, 6, 2, 7, 8, 9};
    int target;

    cout << "Enter a value to count: ";
    cin >> target;

    // count() algorithm to count the specified value in the container
    int occur = count(numbers.begin(), numbers.end(), target);

    cout << "The value " << target << " appears " << occurr << " times in the container." << endl;

    return 0;
}
