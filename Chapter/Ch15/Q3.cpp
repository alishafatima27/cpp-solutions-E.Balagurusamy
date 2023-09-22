// Write a program that reads several city names from the keyboard and displays only those names beginning with characters 'B' or 'C'.

// Note : This program can also be done without the usage of iterator 

#include <iostream>
#include <string>
using namespace std;

int main() {
    int size;
    cout << "Enter the number of cities: ";
    cin >> size;
    cin.ignore(); // Consume the newline character left in the buffer

    string cities[size];

    // Read city names
    for (int i = 0; i < size; i++) {
        cout << "Enter city name " << i + 1 << ": ";
        getline(cin, cities[i]);
    }

    // Display city names starting with 'B' or 'C' using iterators
    cout << "City names starting with 'B' or 'C':" << endl;
    for (int i = 0; i < size; i++) {
        string::iterator it = cities[i].begin();

        // Check if the first character is 'B' or 'C'
        if (*it == 'B' || *it == 'C') {
            cout << cities[i] << endl;
        }
    }

    return 0;
}
