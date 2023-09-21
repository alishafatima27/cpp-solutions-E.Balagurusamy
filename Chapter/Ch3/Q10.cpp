/* An electricity board changes the following rates to domestic users to discourage large consumption of electricity.
  for the first 100 units           - 60P per unit 
  for next 200 units                - 80P per unit 
  Beyond 300 units                  - 90P per unit
All users are charged a minimum of Rs. 50.00. 
If the total amount is more than Rs 300.00 then an additional surcharge of 15% is added.
Write a program to read the names of users and number of units consumed and print out the charges with names.
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    int numUsers;

    cout << "Enter the number of users: ";
    cin >> numUsers;

    for (int i = 0; i < numUsers; i++) {
        string userName;
        int unitsConsumed;
        float price = 50.00;

        cout << "Enter user name: ";
        cin.ignore(); // Clear the newline character from the buffer
        getline(cin, userName);

        cout << "Enter units consumed: ";
        cin >> unitsConsumed;

        // Calculate charges based on the given rates
           if(unitsConsumed <=100){
        price += unitsConsumed*0.60 ; 
    } 
        else {
            price += 100*0.60 ; 
            if (unitsConsumed <= 300){
                price += (unitsConsumed-100)*0.80;
            }
                else {
                    price += 200*0.80 ; 
                    if (unitsConsumed > 300){
                        price += (unitsConsumed - 300 )*0.90 ; 
                    }
                }
        }
    if (price > 300){
        price += price*0.15; 
    }

        cout << "Charges for " << userName << ": Rs. " << price << endl;
    }

    return 0;
}
