// Write a program to demonstrate the use of reinterpret_cast operator.

/* Approach : 
    1 ) Created an integer variable intValue and a pointer to an integer intPtr, pointing to intValue. 
    2 ) We use reinterpret_cast to cast intPtr to a void* called voidPtr. 
    3 ) Finally, we cast voidPtr back to an integer pointer newIntPtr using reinterpret_cast and access the original integer value.
*/ 

/*     note : reinterpret_cast operator is used to change one data type to fundamnetally another datatype.
       It should be only used for casting inherently to incompatible type. 
       Here we have chosen int* to void* conversion and vice versa as they are incompatible datatype. 
*/ 


#include <iostream>
using namespace std;

int main() {
    int intValue = 42;

    // Create a pointer to an integer
    int* intPtr = &intValue;

    // Use reinterpret_cast to cast the integer pointer to a void pointer
    void* voidPtr = reinterpret_cast<void*>(intPtr);

    // Cast the void pointer back to an integer pointer using reinterpret_cast
    int* newIntPtr = reinterpret_cast<int*>(voidPtr);

    // Access and print the value through the new integer pointer
    cout << "Original Integer Value: " << *newIntPtr << endl;

    return 0;
}
