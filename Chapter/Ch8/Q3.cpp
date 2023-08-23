/* An educational institution wishes to maintain a database of its employees. 
   The database is divided into a number of classes whose hierarchical relationships are shown in Fig. 8.14. 
                     __________
                    | Staff    |
                    |__________|
                    | code name|
                     __________
                      /  |  \
                    /    |    \
                  /      |      \
       ___________   ______   _______            
      |    Teacher| |Typist| |Officer|
      |___________| |______| |_______|
      |   Subject | | speed| | grade |
      |publication| |______| |_______|
      |___________|  /  \
                   /      \
             ________     ________       
            | Regular|   |Casual  |
            |________|   |________|            
                         | Daily  |
                         |________|
                        
                    
   The figure also shows the minimum information required for each class. 
   Specify all the classes and define functions to create the database and retrieve individual information as and when required.
*/


#include <iostream>
#include <string.h>
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
    cout << "Enter name : ";
    cin.ignore();
    getline(cin,name) ; 
    cout << "Enter code : ";
    cin >> code ; 
}

void Staff::display()
{
    cout << "\nName : " << name << endl ;
    cout << "Code : " << code << endl ;
}

class Teacher : private Staff
{
    string pub , sub ;   
public:
    void getdata();
    void display();
};

void Teacher ::getdata()
{
    Staff::getdata();
    cout << "Enter subject : ";
    cin >> sub;
    cout << "Enter publication : ";
    cin >> pub;
}

void Teacher ::display()
{
    Staff::display();
    cout << "Subject : " << sub << endl << "Publication : " << pub << endl;
}

class Typist : private Staff
{
    int speed ; 
    public :
    void getdata();
    void display();
};

void Typist ::getdata()
{
    Staff::getdata();
    cout << "Enter speed : ";
    cin >> speed;
}

void Typist ::display()
{
    Staff::display();
    cout << "Speed : " << speed << endl ;
}

class Regular : private Typist
{  
    public:
    void display();
};

void Regular ::display()
{
    Typist::display();
    cout << "Type : Regualar" <<  endl ;
}

class Casual : private Typist
{
    int daily_wage;
    public:
    void getdata();
    void display();
};

void Casual :: getdata()
{
    Typist::getdata();
    cout << "Enter daily wage : "; 
    cin >> daily_wage;
}
void Casual :: display()
{
    Typist::display();
    cout << "Daily Wage : " << daily_wage << endl ;
}

class Officer : private Staff
{
    char grade ; 
    public:
    void getdata()
    {
        Staff::getdata();
        do 
        {
            cout << "Enter grade : ";
            cin >> grade ;  
        }
        while (grade != 'A' || grade != 'a' || grade != 'B' || grade != 'b' || grade != 'C' || grade != 'c' );
    }
    void display()
    {
        Staff::display();
        cout<< "Grade : " << grade << endl ; 
    }
};

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
                r.display();
            }
         else if (ch == 2)
            {
                Casual c;
                c.getdata();
                c.display();
            }
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
