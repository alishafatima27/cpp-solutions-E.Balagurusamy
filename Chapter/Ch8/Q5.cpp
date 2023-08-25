/* Consider a class network of Fig 8.15. The class master derives information from 
   both account and admin classes which in turn derive information from the class person. 
   Define all the four classes and write a program to create, update and display the 
   information contained in master objects.














*/


#include <iostream>
using namespace std;

class Person
{
protected:
    string name;
    int code;

public:
    void getdata();
    void display();
};

void Person::getdata()
{
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter code: ";
    cin >> code;
}

void Person::display()
{
    cout << "Name : " << name << endl;
    cout << "Code : " << code << endl;
}

class Account : public Person
{
protected:
    float pay;

public:
    void getdata();
    void display();
};

void Account::getdata()
{
    Person::getdata(); 
    cout << "Enter pay amount: ";
    cin >> pay;
}

void Account::display()
{
    Person::display(); 
    cout << "Pay: " << pay;
}

class Admin : public Person
{
protected:
    int exp;

public:
    void getdata();
    void display();
};

void Admin::getdata()
{
    cout << "Select the experience level: " << endl;
    cout << "1. Beginner \n2. Intermediate \n3. Expert \n";
    cin >> exp;
}

void Admin::display()
{
    Person::display(); 
    switch (exp)
    {
    case 1:
        cout << "Need Training!";
        break;
    case 2:
        cout << "Promotion applied!";
        break;
    case 3:
        cout << "Promoted";
        break;
    default:
        cout << "You entered the wrong choice! Program exiting.";
        break;
    }
}

class Master : public Account, public Admin
{
public:
    void getdata();
    void display();
};

void Master::getdata()
{
    Account::getdata(); 
    Admin::getdata();   
}

void Master::display()
{
    Account::display(); 
    Admin::display();   
}

int main()
{
    Master a;
    a.getdata();
    a.display();
    return 0;
}
