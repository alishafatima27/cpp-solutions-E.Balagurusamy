/* Write a program which reads a text from keyboard and displays the following information on the screen in two columns : 
        (a) Number of lines 
        (b) Number of words 
        (c) Number of characters 
   Strings should be left justified and numbers should be right justified in a suitable field width.
*/ 


#include <iostream>
#include <string>
#include <iomanip> // For setw function
using namespace std;

int main() {
    string text;
    int numLines = 0;
    int numWords = 0;
    int numChars = 0;
    bool inWord = false;

    cout << "Enter text (press Ctrl+D on a new line to end input):" << endl;

    // Read input text until Ctrl+D (EOF) is encountered
    while (getline(cin, text)) {
        numLines++; // Count lines

        // Iterate through the characters in the current line
        for (char c : text) {
            numChars++; // Count characters

            // Check if the current character is a space
            if (c == ' ') {
                inWord = false; // Not inside a word
            } else if (!inWord) {
                numWords++; // Count words
                inWord = true; // Now inside a word
            }
        }
    }

    // Increment word count by 1 as the last word may not end with a space
    if (inWord) {
        numWords++;
    }

    // Display the results in two columns
    cout << left << setw(20) << "Number of Lines:" << right << setw(10) << numLines << endl;
    cout << left << setw(20) << "Number of Words:" << right << setw(10) << numWords << endl;
    cout << left << setw(20) << "Number of Characters:" << right << setw(10) << numChars << endl;

    return 0;
}
