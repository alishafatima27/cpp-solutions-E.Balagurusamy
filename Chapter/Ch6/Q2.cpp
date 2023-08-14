/*  Define a class String that could work as an user-defined string type. 
    Include constructors that will enable us to create uninitialized string

   String s1; // string with length 0
   and also to initialize an object with a string constant at the time of creation like

   String s2("Well done!");

   Include a function that adds two strings to make a third string. Note that the statement
   s2 = s1;
   will be perfectly reasonable expression to copy one string to another.

   Write a complete program to test your class to see that it does the following tasks:

      (a) Creates uninitialized string objects.
      (b) Creates objects with string constants.
      (c) Concatenates two strings properly.
      (d) Displays a desired string object.
*/

#include <iostream>
#include <string>
using namespace std;

class String
{
    string str; // Private member to hold the string data
public:
    // Default constructor
    String()
    {
        str = ""; // Initialize with an empty string
    }

    // Parameterized constructor to initialize with a given string
    String(const char para_str[])
    {
        str = para_str; // Assign the provided string
    }

    // Function to input a string from the user
    void input()
    {
        cout << "Enter the string : ";
        getline(cin, str); // Using getline to handle spaces
    }

    // Function to display the current string
    void display()
    {
        cout << "The string is : " << str << "\n\n";
    }

    // Function to concatenate two strings
    void concatenate(const string &s1, const string &s2)
    //'&' signifies that the function is taking the parameters by reference
    // 'const' indicates that the function won't modify the passed strings
    {
        str = s1 + s2; // Concatenate strings using the + operator
    }

    // method to access the private member
    string getString() const
    {
        return str;
    }
};

int main()
{
    // Create an uninitialized String object and display its content
    String uninitialized;
    cout << "Uninitialized string:" << endl;
    uninitialized.display();

    // Create a String object with an initial value and display it
    String initialized("Well Done!");
    cout << "Initialized string:" << endl;
    initialized.display();

    // Input two strings from the user and display them
    String s1, s2;
    cout << "Enter the first string:" << endl;
    s1.input();
    cout << "Entered first string:" << endl;
    s1.display();

    cout << "Enter the second string:" << endl;
    s2.input();
    cout << "Entered second string:" << endl;
    s2.display();

    // Concatenate the two input strings and display the result
    String s3;
    s3.concatenate(s1.getString(), s2.getString());
    cout << "Concatenated string:" << endl;
    s3.display();

    return 0; // Indicate successful execution
}
