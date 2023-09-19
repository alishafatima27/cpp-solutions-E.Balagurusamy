/* Create a student class that includes a students's first name and his roll_number.
   Create five objects of this class and store them in a list thus creating a phone_lit.
   Write a program using list to display the student name if the roll_number is given and vice versa.
*/ 


#include <iostream>
#include <list>
#include <string>
using namespace std;

class Student {
public:
    string firstName;
    int rollNumber;

    Student(string name, int roll) : firstName(name), rollNumber(roll) {}
};

int main() {
    // Create a list to store student objects
    list<Student> phoneList;

    // Create five student objects and add them to the list
    phoneList.push_back(Student("Meg", 101));
    phoneList.push_back(Student("Joe", 102));
    phoneList.push_back(Student("Amy", 103));
    phoneList.push_back(Student("Beth", 104));
    phoneList.push_back(Student("Laurie", 105));

    // Search for a student by roll number
    int searchRoll;
    cout << "Enter a roll number to search for a student: ";
    cin >> searchRoll;

    bool foundByRoll = false;
    for (const Student& student : phoneList) {
        if (student.rollNumber == searchRoll) {
            cout << "Student with roll number " << searchRoll << " found: " << student.firstName << endl;
            foundByRoll = true;
            break;
        }
    }

    if (!foundByRoll) {
        cout << "Student with roll number " << searchRoll << " not found." << endl;
    }

    // Search for a student by first name
    string searchName;
    cout << "Enter a first name to search for a student: ";
    cin.ignore(); // Clear the newline character from the previous input
    getline(cin, searchName);

    bool foundByName = false;
    for (const Student& student : phoneList) {
        if (student.firstName == searchName) {
            cout << "Student with first name " << searchName << " found: Roll number " << student.rollNumber << endl;
            foundByName = true;
            break;
        }
    }

    if (!foundByName) {
        cout << "Student with first name " << searchName << " not found." << endl;
    }

    return 0;
}
