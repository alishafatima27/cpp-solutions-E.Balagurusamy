// Write a program that uses catch(...) handler.


#include <iostream>
using namespace std;

int main() {
    try {
        // Attempt to perform division operations that may throw exceptions
        int numerator = 10;
        int denominator = 0;
        int result = numerator / denominator; // This will throw a division by zero exception
    } catch (...) {
        // Catch any type of exception
        cout << "An unknown exception occurred." << endl;
    }

    return 0;
}
