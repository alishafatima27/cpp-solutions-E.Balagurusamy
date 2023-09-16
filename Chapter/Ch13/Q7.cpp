/* Write a main program that calls a deeply nested function containing an exception.
   Incorporate necessary exception handling mechanism.
*/ 


#include <iostream>
using namespace std;

// Function that may throw an exception
void innermostFunction() {
    cout << "Inside innermostFunction." << endl;
    throw "Exception inside innermostFunction.";
}

// Middle-level function that calls innermostFunction
void middleFunction() {
    cout << "Inside middleFunction." << endl;
    try {
        innermostFunction();
    } catch (const char*) {
        cout << "Caught exception inside middleFunction." << endl;
        throw; // Re-throw the caught exception
    }
}

// Top-level function that calls middleFunction
void topLevelFunction() {
    cout << "Inside topLevelFunction." << endl;
    try {
        middleFunction();
    } catch (const char*) {
        cout << "Caught exception inside topLevelFunction." << endl;
        throw; // Re-throw the caught exception
    }
}

int main() {
    cout << "Inside main, calling topLevelFunction." << endl;
    try {
        topLevelFunction();
    } catch (const char*) {
        cout << "Caught exception inside main." << endl;
    }

    return 0;
}
