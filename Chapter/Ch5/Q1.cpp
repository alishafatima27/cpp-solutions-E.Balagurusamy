/* Define a class to represent a bank account. Include the following members:

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
#include <string>
using namespace std;

class BankAccount {
private:
    string depositorName;
    int accountNumber;
    string accountType;
    double balance;

public:
    // Constructor to initialize data members
    BankAccount(string name, int accNumber, string accType, double initialBalance) {
        depositorName = name;
        accountNumber = accNumber;
        accountType = accType;
        balance = initialBalance;
    }

    // Function to deposit an amount
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Amount deposited successfully. Current balance: Rs " << balance << endl;
        } else {
            cout << "Invalid amount. Deposit amount should be greater than 0." << endl;
        }
    }

    // Function to withdraw an amount after checking the balance
    void withdraw(double amount) {
        if (amount > 0) {
            if (balance >= amount) {
                balance -= amount;
                cout << "Amount withdrawn successfully. Current balance: Rs " << balance << endl;
            } else {
                cout << "Insufficient balance. Cannot withdraw Rs " << amount << endl;
            }
        } else {
            cout << "Invalid amount. Withdrawal amount should be greater than 0." << endl;
        }
    }

    // Function to display name and balance
    void displayInfo() {
        cout << "Depositor Name: " << depositorName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: Rs " << balance << endl;
    }
};

int main() {
    string name, accType;
    int accNumber;
    double initialBalance, amount;

    // Taking input from the user to create a bank account
    cout << "Enter Depositor Name: ";
    getline(cin, name);

    cout << "Enter Account Number: ";
    cin >> accNumber;

    cin.ignore(); // Ignore the newline character left in the input buffer

    cout << "Enter Account Type: ";
    getline(cin, accType);

    cout << "Enter Initial Balance: $";
    cin >> initialBalance;

    // Creating a BankAccount object and initializing with user-provided values
    BankAccount myAccount(name, accNumber, accType, initialBalance);

    // Displaying initial account information
    cout << "\nInitial Account Information:" << endl;
    myAccount.displayInfo();

    // Taking input from the user for deposit amount
    cout << "\nEnter the amount to deposit: $";
    cin >> amount;
    myAccount.deposit(amount);

    // Taking input from the user for withdrawal amount
    cout << "\nEnter the amount to withdraw: $";
    cin >> amount;
    myAccount.withdraw(amount);

    // Displaying updated account information
    cout << "\nUpdated Account Information:" << endl;
    myAccount.displayInfo();

    return 0;
}

