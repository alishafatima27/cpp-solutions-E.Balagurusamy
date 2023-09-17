/* Write a code segment that does the following :
     (a) Defines a vector v with maximum size of 10 
     (b) Sets the first element of v to 0.
     (c) Sets the last element of v to 9.
     (d) Sets the other element to 1.
     (e) Displays the contents of v.
*/ 


#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // (a) Define a vector v with a maximum size of 10
    vector<int> v(10);

    // (b) Set the first element of v to 0
    v[0] = 0;

    // (c) Set the last element of v to 9
   // v.size() : returns size of function
    v[v.size() - 1] = 9; 

    // (d) Set the other elements to 1 using for each loop
    for (int i = 1; i < v.size() - 1; ++i) {
        v[i] = 1;
    }

    // (e) Display the contents of v using for each loop
    cout << "Contents of v: ";
    for (int i : v) {
        cout << v[i] << " ";
    }
    cout << endl;
}
