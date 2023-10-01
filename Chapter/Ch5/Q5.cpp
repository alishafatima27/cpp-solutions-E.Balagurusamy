/*Create two classes DM and DB which store the value of distances. 
  DM stores distances in meters and centimeters and 
  DB in feet and inches. 
  Write a program that can read values for the class objects and add one object of DM with another object of DB.

Use a friend function to carry out the addition operation. 
The object that stores the results may be a DM object or DB object, depending on the units in which the results are required.
The display should be in the format of feet and inches or meters and centimeters depending on the object on display.
*/

#include <iostream>
using namespace std;

class DB;

class DM {
    int meters;
    int centimeters;

public:
    void getDistance() {
        cout << "Enter distance in meters: ";
        cin >> meters;
        cout << "Enter distance in centimeters: ";
        cin >> centimeters;
    if(centimeters >=100)
    {
        meters += centimeters/100 ; 
        centimeters += centimeters%100; 
    }
    }

    void display() {
        cout << "Distance: " << meters << " meters and " << centimeters << " centimeters" << endl;
    }

    friend DM add(DM, DB);
};

class DB {
    int feet;
    int inches;

public:
    void getDistance() {
        cout << "Enter distance in feet: ";
        cin >> feet;
        cout << "Enter distance in inches: ";
        cin >> inches;
        if(inches > 12) 
        {   
            feet += inches/12; 
            inches += inches%12; 
        }
    }

    void display() {
        cout << "Distance: " << feet << " feet and " << inches << " inches" << endl;
    }

    friend DM add(DM, DB);
};

DM add(DM dm, DB db) {
    DM result;
    int totalCentimeters = (dm.meters * 100 + dm.centimeters) + ((db.feet * 12 + db.inches) * 2.54);
    
    result.meters = totalCentimeters / 100;
    result.centimeters = totalCentimeters % 100;

    return result;
}

int main() {
    DM dmObj;
    DB dbObj;
    dmObj.getDistance();
    dbObj.getDistance();

    DM result = add(dmObj, dbObj);

    cout << "Sum of distances:" << endl;
    result.display();

    return 0;
}

