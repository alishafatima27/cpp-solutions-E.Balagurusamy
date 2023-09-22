// Write a program that will read a line of text xontaining more than three words and then replace all the blank spaces with an underscore(_).

#include <iostream>
using namespace std ; 

int main(){
    string newString ; 
    cout << "Enter a line with more than three words with spaces : "; 
    getline(cin,newString);

    string :: iterator it = newString.begin();

    while(it != newString.end()){
        if ( *it == ' ' ) {
            *it = '_' ; 
        }
        it++;
    }

     cout << "Modified text with underscores: " << newString << endl;

    return 0;
}
     
