// Modify the program in Q6 to count the number of wods that starts with character 's'.


#include <iostream>
#include <string>
#include <sstream> // Include the <sstream> header for using stringstream
using namespace std;

int main() {
    string text; // Declare a string variable to store the input text
    cout << "Enter the text: "; // Prompt the user to enter text
    getline(cin, text); // Read a line of text from the user and store it in the 'text' variable

    // Create a stringstream object 'ss' and initialize it with the input text
    stringstream ss(text);

    string word; // Declare a string variable to store individual words
    int count = 0; // Initialize a counter for words starting with 's'

    // Use a while loop to extract words from the stringstream
    while (ss >> word) {
        // Check if the extracted word is not empty and starts with the character 's'
        if (!word.empty() && word[0] == 's') {
            count++; // Increment the count if the word meets the criteria
        }
    }

    // Display the result
    cout << "The word starting with \"s\" appears " << count << " time(s) in the text." << endl;

    return 0;
}
