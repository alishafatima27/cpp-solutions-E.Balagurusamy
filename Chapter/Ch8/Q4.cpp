/* The database created in Exercise 8.3 does not include educational information of the staff. 
   It has been decided to add this information to teachers and officers (and not for typists)
   which will help the management in decision making with regard to training, promotion, etc. 
   Add another data class called education that holds two pieces of educational information, namely, 
   highest qualification in general education and highest professional qualification. 
   This class should be inherited by the classes teacher and officer. 
   Modify the program of Exercise 8.3 to incorporate these additions.
*/


#include <iostream>
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
    cin.ignore(); // clear the newline character from the buffer
    cout << "Enter name : ";
    getline(cin, name);
    cout << "Enter code : ";
    cin >> code;
}

void Staff::display()
{
    cout << "Name : " << name << endl;
    cout << "Code : " << code << endl;
}

class Education
{
protected:
    string genQual;
    string profQual;

public:
    void getdata();
    void display();
};

void Education::getdata()
{
    cout << "Enter general qualification : ";
    cin.ignore(); 
    getline(cin, genQual);
    cout << "Enter professional qualification : ";
    getline(cin, profQual);
}

void Education::display()
{
    cout << "General Qualification: " << genQual << endl;
    cout << "Professional Qualification: " << profQual << endl;
}

class Teacher : private Staff, private Education
{
    string pub, sub;
    int expYears;

public:
    void getdata();
    void display();
    bool isEligibleForTraining();
    bool isEligibleForPromotion();
};

void Teacher::getdata()
{
    Staff::getdata();
    Education::getdata();
    cout << "Enter subject : ";
    cin >> sub;
    cout << "Enter publication : ";
    cin >> pub;
    cout << "Enter years of experience: ";
    cin >> expYears;
}

void Teacher::display()
{
    Staff::display();
    Education::display();
    cout << "Subject : " << sub << endl
         << "Publication : " << pub << endl;
    cout << "Experience years: " << expYears << endl;
}

bool Teacher::isEligibleForTraining()
{
    return (genQual == "Postgraduate" || genQual == "postgraduate") && expYears < 3;
}

bool Teacher::isEligibleForPromotion()
{
    return expYears >= 3;
}

class Officer : private Staff, private Education
{
    char grade;
    int expYears;

public:
    void getdata();
    void display();
    bool isEligibleForTraining();
    bool isEligibleForPromotion();
};

void Officer::getdata()
{
    Staff::getdata();
    Education::getdata();
    do
    {
        cout << "Enter grade : ";
        cin >> grade;
    } while (grade != 'A' && grade != 'a' && grade != 'B' && grade != 'b' && grade != 'C' && grade != 'c');
    cout << "Enter years of experience: ";
    cin >> expYears;
}

void Officer::display()
{
    Staff::display();
    Education::display();
    cout << "Grade : " << grade << endl;
    cout << "Experience years: " << expYears << endl;
}

bool Officer::isEligibleForTraining()
{
    return (genQual == "Graduate" || genQual == "graduate") && expYears < 3;
}

bool Officer::isEligibleForPromotion()
{
    return expYears >= 3;
}

int main()
{
    cout << "\n------ Database employee management system --------\n";

    int choice;
    cout << "1. Add Teacher" << endl;
    cout << "2. Add Officer" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        Teacher t;
        t.getdata();
        t.display();
        if (t.isEligibleForTraining())
        {
            cout << "Eligible for training." << endl;
        }
        if (t.isEligibleForPromotion())
        {
            cout << "Eligible for promotion." << endl;
        }
        break;
    }
    case 2:
    {
        Officer o;
        o.getdata();
        o.display();
        if (o.isEligibleForTraining())
        {
            cout << "Eligible for training." << endl;
        }
        if (o.isEligibleForPromotion())
        {
            cout << "Eligible for promotion." << endl;
        }
        break;
    }
    default:
        cout << "Invalid choice." << endl;
        break;
    }

    return 0;
}
