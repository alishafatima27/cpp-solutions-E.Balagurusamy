/* 
  Write aprogram taht reads the folloing text and counts the number of times the word "it" appears i  it .
          It is new. It is singular.
          It is simple. It must succeed! 
*/  


#include <iostream>
#include <string>
using namespace std;

int main() {
    string text;
    cout << "Enter the text: ";
    getline(cin, text);

    string wordToCount = "it"; // The word we want to count
    int count = 0; // Counter to keep track of the word count

    size_t pos = text.find(wordToCount); // Find the first occurrence of the word in the text

    // Start a loop to search for the word repeatedly
    while (pos != string::npos) {
        count++; // Increment the count for each found occurrence
        pos = text.find(wordToCount, pos + 1); // Search for the next occurrence starting from the next position
    }

    // Display the result
    cout << "The word \"" << wordToCount << "\" appears " << count << " time(s) in the text." << endl;

    return 0;
}
    
