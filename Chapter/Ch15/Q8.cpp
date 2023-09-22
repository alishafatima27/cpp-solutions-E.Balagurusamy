/* Given a string 
       string s("123456789");
   Write a program that displays the following : 
                          1
                        2 3 2  
                      3 4 5 4 3 
                    4 5 6 7 6 5 4 
                  5 6 7 8 9 8 7 6 5 
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s("123456789");
    int n = s.length();

    int spaces = n - 1;

    for (int i = 1; i <= (n+1)/2; i++) {
        // Printing leading spaces
        for (int j = spaces; j > 0; j -= 2) {
            cout << "  ";
        }

        // Printing the first half of the numbers
        for (int k = i; k <= i * 2 - 1; k++) {
            cout << s[k-1] << " ";
        }

        // Printing the second half of the numbers (excluding the last element)
        for (int j = i * 2 - 2; j >= i; j--) {
            cout << s[j] << " ";
        }

        cout << endl;
        spaces -= 2; // decrementing value of spaces 
    }

    return 0;
}
