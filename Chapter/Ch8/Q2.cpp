// Modify the program of Exercise 8.1 to include constructors for all the three classes.


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
    Account()
    {
        name = "";
        acc_num = 0;
        bal = 0;
        wd = 0;
        dep = 0;
    }

    void getdata()
    {
        cin.ignore();
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
    Saving() : rate(2.5) {}

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
    Current() : min_bal(1000), fine(500) {}

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
    cout << "--------- Welcome to ABC Bank ---------"
    cout << "Enter account type (S for Savings, C for Current): ";
    cin >> acc_type;

    cout << "\n-----------------------------\n";
    switch (acc_type)
    {
    case 'S':
    case 's':
    {
        Saving s;
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
