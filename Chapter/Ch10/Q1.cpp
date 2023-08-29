/* Write a program to read a list containing item name , item code , and cost 
   interactively and prduce a three column output as shown below.
   _____________________________________________________________________
  |         NAME         |         CODE         |         COST          |
  |______________________|______________________|_______________________|
  |      Turbo C++       |         1001         |         250.95        |
  |      C Primer        |         905          |         95.70         |
  |       ......         |          ...         |          ...          |
  |______________________|______________________|_____ _________________|
  
  */ 


#include <iostream>
#include <iomanip>
using namespace std;

class Item
{
    string name;
    int code;
    float pr;

public:
    void getdata()
    {
        cout << "Enter name : ";
        cin >> name;
        cout << "Enter code : ";
        cin >> code;
        cout << "Enter price : ";
        cin >> pr;
    }

    void display()
    {
        cout << left << setw(20) << setfill(' ') << name
             << left << setw(20) << setfill(' ') << code
             << fixed << setprecision(2) << left << setw(20) << setfill(' ') << pr
             << endl;
    }
};

int main()
{
    int n;
    cout << "Enter number of items : ";
    cin >> n;
    Item *items[n];
    for (int i = 0; i < n; i++)
    {
        items[i] = new Item();
        items[i]->getdata();
    }

    cout << "-----------------------------------------------------------------------" << endl;
    cout << "|         NAME         |         CODE         |         COST          |" << endl;
    cout << "-----------------------------------------------------------------------" << endl;

    for (int i = 0; i < n; i++)
    {
        items[i]->display();
        delete items[i]; // Free memory
    }

    cout << "-----------------------------------------------------------------------" << endl;

    return 0;
}

