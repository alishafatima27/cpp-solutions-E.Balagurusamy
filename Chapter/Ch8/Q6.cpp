/* In Exercise 8.3, the classes teacher, officer and typist are derived from the class staff. 
   As we know, we can use container classes in place of inheritance in some situations. 
   Redesign the program of Exercise 8.3 such that the classes teacher, officer and typist contain objects of staff.
*/


#include <iostream>
#include <string>
using namespace std;

class Staff
{
protected:
    int code;

public:
    string name;
    void getdata();
    void display();
};

void Staff::getdata()
{
    cin.ignore();
    cout << "Enter name : ";
    getline(cin, name);
    cout << "Enter code : ";
    cin >> code;
}

void Staff::display()
{
    cout << "\nName : " << name << endl;
    cout << "Code : " << code << endl;
}

class Teacher
{
private:
    Staff staff; // Container class 
    string pub, sub;
public:
    void getdata();
    void display();
};

void Teacher::getdata()
{
    staff.getdata(); // Accessing function of container class thorugh its object 
    cout << "Enter subject : ";
    cin >> sub;
    cout << "Enter publication : ";
    cin >> pub;
}

void Teacher::display()
{
    staff.display();
    cout << "Subject : " << sub << endl << "Publication : " << pub << endl;
}

class Typist
{
private:
    Staff staff;
    int speed;

public:
    void getdata();
    void display();
};

void Typist::getdata()
{
    staff.getdata();
    cout << "Enter speed : ";
    cin >> speed;
}

void Typist::display()
{
    staff.display();
    cout << "Speed : " << speed << endl;
}

class Regular
{
private:
    Typist typist;

public:
    void getdata();
    void display();
};

void Regular::getdata()
{
    typist.getdata();
}

void Regular::display()
{
    typist.display();
    cout << "Type : Regular" << endl;
}

class Casual
{
private:
    Typist typist;
    int daily_wage;

public:
    void getdata();
    void display();
};

void Casual::getdata()
{
    typist.getdata();
    cout << "Enter daily wage : ";
    cin >> daily_wage;
}

void Casual::display()
{
    typist.display();
    cout << "Daily Wage : " << daily_wage << endl;
}

class Officer
{
private:
    Staff staff;
    char grade;

public:
    void getdata();
    void display();
};

void Officer::getdata()
{
    staff.getdata();
    do
    {
        cout << "Enter grade (A / B / C) : ";
        cin >> grade;
    } while (grade != 'A' && grade != 'a' && grade != 'B' && grade != 'b' && grade != 'C' && grade != 'c');
}

void Officer::display()
{
    staff.display();
    cout << "Grade : " << grade << endl;
}

int main()
{
    cout << "\n------ Database Employee Management System --------\n";

    int choice;
    cout << "1. Add Teacher" << endl;
    cout << "2. Add Typist" << endl;
    cout << "3. Add Officer" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        Teacher t;
        t.getdata();
        t.display();
        break;
    }
    case 2:
    {
        int ch;
        cout << "1. Regular: \n";
        cout << "2. Casual : \n";
        cin >> ch;

        while (ch != 1 && ch != 2)
        {
            cout << "Invalid choice. Please enter 1 for Regular or 2 for Casual: ";
            cin >> ch;
        }

        if (ch == 1)
        {
            Regular r;
            r.getdata();
            r.display();
        }
        else if (ch == 2)
        {
            Casual c;
            c.getdata();
            c.display();
        }
        break;
    }
    case 3:
    {
        Officer o;
        o.getdata();
        o.display();
        break;
    }
    default:
        cout << "Invalid choice." << endl;
        break;
    }

    return 0;
}
