// Write a program that counts the number of occurences of a particular character, say 'e' in a line of text.


#include <iostream>
using namespace std;

int main() {
    string newString;
    cout << "Enter a line of text: ";
    getline(cin, newString);

    char findChar;
    cout << "Enter a character to find its occurrence: ";
    cin >> findChar;

    int count = 0;

    string::iterator it = newString.begin();

    while (it != newString.end()) {
        if (*it == findChar) {
            count++;
        }
        ++it;
    }

    if (count > 0) {
        cout << "The character '" << findChar << "' appeared " << count << " time(s) in the string." << endl;
    } else {
        cout << "The character '" << findChar << "' was not found in the string." << endl;
    }

    return 0;
}
