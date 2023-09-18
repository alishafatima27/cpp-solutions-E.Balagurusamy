/* Create an array with even numbers and a list with odd numbers.
   Merge two sequences of numbers into a vector using algorithm merge().
   Display the vector.
*/ 


#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    array<int, 5> evenArray = {2, 4, 6, 8, 10};
    list<int> oddList = {1, 3, 5, 7, 9};

    // Creating a vector to store the merged sequence
    vector<int> mergedVector;

    // merge() algorithm to merge the two sequences
    merge(evenArray.begin(), evenArray.end(), oddList.begin(), oddList.end(), back_inserter(mergedVector));

    // Displaying the merged vector
    cout << "Merged vector: ";
    for (const int& num : mergedVector) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
