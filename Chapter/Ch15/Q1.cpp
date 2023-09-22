/*
Write a program that reads the name 
            Martin Luther King 
from the keyboard into three separate string objects and then concatenates them into new string object using 
  (a) + operator 
  (b) append() function 
*/


#include <iostream>
using namespace std;

int main() {
    string firstName, middleName, lastName;
    cout << "Enter the first name: ";
    cin >> firstName; // using cin because we want to read only one word
    cout << "Enter the middle name: ";
    cin >> middleName;
    cout << "Enter the last name: ";
    cin >> lastName;

    // Concatenating the first and middle name using + operator
    string fullName = firstName + " " + middleName + " ";

    cout << "Name after concatenation using + operator with middle name: " << fullName << endl;

    // Concatenating the last name using append() function
    fullName.append(lastName);

    cout << "Full name after concatenation using append() with last name: " << fullName << endl;

    return 0;
}
