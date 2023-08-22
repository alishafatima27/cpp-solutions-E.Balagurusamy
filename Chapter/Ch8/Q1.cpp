/* Assume that a bank maintains kinds of accounts for customers, one called as savings account and the other as current account. 
   The savings account provides compound interest and withdrawal facilities, but no cheque book facility. 
   The current account provides cheque book facility but no interest. 
   Current account holders should also maintain a minimum balance and if the balance falls below this level, a service charge is imposed.

   Create a class account that stores customer name, account number and type of account.
   From this, derive the classes cur_acct and sav_acct to make them more specific to their requirements. 
   Include necessary member functions in order to achieve the following tasks:
          (a) Accept deposit from a customer and update the balance.
          (b) Display the balance.
          (c) Compute and deposit interest.
          (d) Permit withdrawal and update the balance.
          (e) Check for the minimum balance, impose penalty, necessary, and update the balance.
   Do not use any constructors. Use member functions to initialize the class members.
*/ 


#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Account
{
protected:
    string name;
    int acc_num;
    float bal, wd, dep;

public:
    void init()
    {
        name = "";
        acc_num = 0;
        bal = 0;
        wd = 0;
        dep = 0;
    }

    void getdata()
    {
        cin.ignore(); // Clear newline character from previous input
        cout << "Enter customer name: ";
        getline(cin, name);

        cout << "Enter account number: ";
        cin >> acc_num;

        cout << "Enter initial balance: ";
        cin >> bal;
    }

    void deposit()
    {
        cout << "Enter amount to be deposited: ";
        cin >> dep;
        bal += dep;
        cout << "Amount deposited successfully.\n";
    }

    virtual void withdraw()
    {
        cout << "Enter amount to be withdrawn: ";
        cin >> wd;
        if (wd <= bal)
        {
            bal -= wd;
            cout << "Amount withdrawn successfully.\n";
        }
        else
        {
            cout << "Insufficient Balance! Money can't be withdrawn.\n";
        }
    }

    float AccessBal()
    {
        return bal;
    }
};

class Saving : public Account
{
    float rate;

public:
    Saving()
    {
        rate = 2.5;
    }

    void cal_int()
    {
        float ci = AccessBal() * rate / 100.0 + AccessBal();
        cout << "Balance with " << rate << "% interest: " << setw(10) << ci << "\n";
    }
};

class Current : public Account
{
    int min_bal;
    float fine;

public:
    Current()
    {
        min_bal = 1000;
        fine = 500;
    }

    void withdraw() override
    {
        Account::withdraw();
        min_bal_check();
    }

    void min_bal_check()
    {
        if (AccessBal() < min_bal)
        {
            bal -= fine;
            cout << "Fine of Rs." << fine << " imposed due to balance below minimum.\n";
        }
    }

    void provide_cheque_book()
    {
        cout << "Cheque book provided.\n";
    }
};

int main()
{
    char acc_type;
    cout << "\n-------- Welcome to ABC Bank ---------\n";
    cout << "Enter account type (S for Savings, C for Current): ";
    cin >> acc_type;

    cout << "\n-----------------------------\n";
    switch (acc_type)
    {
    case 'S':
    case 's':
    {
        Saving s;
        s.init();
        cout << "Savings Account Details:\n";
        cout << "-----------------------------\n";
        s.getdata();
        s.deposit();
        s.cal_int();
        s.withdraw();
        cout << "-----------------------------\n";
        break;
    }
    case 'C':
    case 'c':
    {
        Current c;
        c.init();
        cout << "Current Account Details:\n";
        cout << "-----------------------------\n";
        c.getdata();
        c.deposit();
        c.withdraw();
        c.provide_cheque_book();
        cout << "-----------------------------\n";
        break;
    }
    default:
        cout << "Invalid account type.\n";
    }

    return 0;
}

