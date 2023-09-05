/* Write a program that reads a text file and creates another file 
   that is identical except that every sequence of consecutive 
   blank space is replaced by a single space.
*/ 


#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream sourceFile;
    ofstream destinationFile;

    sourceFile.open("source.txt"); 
    destinationFile.open("dest.txt"); 

    if (!sourceFile) {
        cout << "Source file does not exist!" << endl;
        return 1; // Exit with an error code
    }

    char prevChar = ' ';
    char ch;
    while (sourceFile.get(ch)) {
        if (!(prevChar == ' ' && ch == ' ')) {
            destinationFile.put(ch); // Write the character to the destination file
        }
        prevChar = ch;
    }

    sourceFile.close();
    destinationFile.close();

    cout << "File copied and extra spaces removed successfully!" << endl;

    return 0;
}
