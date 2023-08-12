/* Design constructors for the classes designed in Programming exercises 5.1 through
   5.5 of Chapter 5.
*/ 

// Constructor is a special member function whose task is to initialize objects of its class.
// It has same name as class name.

/* I have modified the program 5.1 by adding default constructor to the class
   It can also be done using parametrized constructor.
   But with parametrized constructor , the object declaration, such as 
        bank_account account; 
   may not work.
    So we have to pass the value either implicitly or explicitly in main function.
    
        bank_account account = bank_account(alisha,9997662,1,1000,100,90) ; // explicit 
        bank_account account(alisha,9997662,1,1000,100,90);
        
    Dont forget to add parameters in the declaration and defination section of constructor to avoid
    "function call with incorrect/missing arguments" error.
*/


#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class bank_account {
private:
    string name;
    int account_num;
    int type;
    float balance;
    float dep;
    float wd;

public:
    bank_account(); // Default constructor declaration
    void input() {
        cout << "Please enter your name: ";
        getline(cin, name);
        cout << "Please enter your account number: ";
        cin >> account_num;

        cout << "Please enter your account type (1 for Savings, 2 for Current): ";
        cin >> type;
        while (type != 1 && type != 2) {
            cout << "\aInvalid Input! Please enter 1 for Savings or 2 for Current: ";
            cin >> type;
        }

        cout << "Please enter your balance: ";
        cin >> balance;
    }

    void deposit() {
        cout << "Enter amount to be Deposited: ";
        cin >> dep;
        balance += dep;
    }

    void withdraw() {
        cout << "Enter amount to be withdrawn: ";
        cin >> wd;
        if (wd > balance) {
            cout << "Insufficient Balance!" << endl;
            wd = 0;
        }
        balance -= wd;
    }

    void display() {
        cout << "\n\n\t**************************************************" << endl;
        cout << "\t\tName: " << name << endl;
        cout << "\t\tAccount number: " << account_num << endl;
        cout << "\t\tAccount type (1: Savings, 2: Current): " << type << endl;
        cout << "\t\tAmount deposited: " << dep << endl;
        cout << "\t\tAmount withdrawn: " << wd << endl;
        cout << "\t\tFinal Balance: " << balance << endl;
    }
};
bank_account::bank_account() // Constructor defination 
{
    name="Alisha";
    account_num=987654321;
    type=1;
    balance=100;
    dep=0;
    wd=0;
}

int main() {
    cout << setw(10) << "---------------WELCOME TO ABC BANK ------------------\n\n";
    bank_account account; // Create an object of the class bank_account which invokes the constructor
    account.input();
    account.deposit();
    account.withdraw();
    account.display();

    return 0;
}


