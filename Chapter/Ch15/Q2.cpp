// Write a program using an iterator and while() construct to display the contents of a string object.


#include <iostream>
#include <string>
using namespace std;

int main(){
    string newString("This is a String object"); // Creating a string object with one argument constructor 
    
    // Creating an iterator to iterate through the characters of the string
    iterator it = newString.begin();

    // Use a while loop to display the contents of the string
    while(it != newString.end()){
         cout << *it ;  // Output the character pointed by the iterator
         ++it ;   // Move the iterator to the next character
    }

    return 0 ;
}
