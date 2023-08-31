// Modify the previous program to fill unused spaces with hyphens 


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
        cin.ignore(); // Clear newline left in buffer
        getline(cin, name);
        cout << "Enter code : ";
        cin >> code;
        cout << "Enter price : ";
        cin >> pr;
    }

    void display()
    {
        cout << "|" << left << setw(25) << setfill('-') << name
             << "|" << left << setw(20) << setfill('-') << code
             << "|" << fixed << setprecision(2) << left << setw(15) << setfill('-') << pr
             << "|" << endl;
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

    cout.fill('-');
    cout << "+" << setw(27) << "+" << setw(22) << "+" << setw(17) << "+" << endl;
    cout << "|" << left << setw(25) << "NAME"
         << "|" << left << setw(20) << "CODE"
         << "|" << left << setw(15) << "COST"
         << "|" << endl;
    cout << "+" << setw(27) << "+" << setw(22) << "+" << setw(17) << "+" << endl;
    cout.fill(' ');

    for (int i = 0; i < n; i++)
    {
        items[i]->display();
        delete items[i]; // Free memory
    }

    cout.fill('-');
    cout << "+" << setw(27) << "+" << setw(22) << "+" << setw(17) << "+" << endl;
    cout.fill(' ');

    return 0;
}
