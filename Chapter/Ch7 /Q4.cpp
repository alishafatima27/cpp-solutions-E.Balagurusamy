// Define a class String. Use overloaded == operator to compare two strings.


#include <iostream>
#include <string.h>
using namespace std; 

class String
{
    char *str; //Pointer to string 
    int len; //Stores length of string 
public:
    String(); //Default constructor 
    String(const char *a);//Prametrized Contructor
    void input();
    void display();
    bool operator==(const String &other); // op overloading == op 
    ~String(); // Destructor 
};

String::String()
{
    str = nullptr; 
    len = 0; 
}

String::String(const char *a)
{
    str = new char[strlen(a) + 1]; 
    strcpy(str , a);
    len = strlen(str); // Set the length in the constructor
}

void String::input()
{
    cout << "Enter the string : ";
    char buffer[100]; // Buffer to read input
    cin.getline(buffer, 100);
    len = strlen(buffer); // Set the length based on user input
    str = new char[len + 1]; // Allocate memory for str
    strcpy(str, buffer); // Copy the input into str
}

void String::display()
{
    cout << "String : " << str; 
}

bool String::operator==(const String &other)
{
    return strcmp(str, other.str) == 0;
}

String::~String()
{
   // delete[] str; commented to avoid double free error
}

int main()
{
    String s1,s2; 
    s1.input();
    s1.display();
    s2 = String("Hello world!");
    //s2.input();
    s2.display();
    if (s1 == s2)
    {
        cout << "\nString 1 equals to string 2\n";
    }
    else 
    {
        cout << "\nNot equal!\n";
    }
}
