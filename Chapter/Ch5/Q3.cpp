// Modify the class and the program of Exercise 5.1 for handling 10 customers.

/* Q5.1 
  Define a class to represent a bank account. Include the following members:

    Data members

      (a) Name of the depositor
      (b) Account number
      (c) Type of account
      (d) Balance amount in the account

    Member functions

      (a) To assign initial values
      (b) To deposit an amount
      (c) To withdraw an amount after checking the balance
      (d) To display name and balance

  Write a main program to test the program.
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

int main() {
    cout << setw(10) << "---------------WELCOME TO ABC BANK ------------------\n\n";
    bank_account account[10]; //  array of object of the bank_account class 
    for (int i=0; i < 10 ; i++ )
    {
    account[i].input();
    account[i].deposit();
    account[i].withdraw();
    account[i].display();
    }

    return 0;
}



