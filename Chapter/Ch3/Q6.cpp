/* This program takes the input from the user of Player's Name , runs , innings, times not out and then give the average batting 
   in a well formated tabular form .
*/
#include <iostream>
#include <iomanip>
using namespace std;

struct PlayersData {
    string name;
    int runs;
    int innings;
    int t_not_out;
    float average;
};

int main() {
    int n;
    cout << "Enter the number of Players: ";
    cin >> n;
    PlayersData Player[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter the Details of Player " << i + 1 << ":\n";
        cout << "Name: ";
        cin >> Player[i].name;
        cout << "Runs: ";
        cin >> Player[i].runs;
        cout << "Innings: ";
        cin >> Player[i].innings;
        cout << "Times Not Out: ";
        cin >> Player[i].t_not_out;

        // Calculate batting average for each player
        
        if (Player[i].innings - Player[i].t_not_out > 0) {
            
            /*static_cast<double> is used to perform a type conversion from integers to double
              if both operands are integers, the result will also be an integer, 
              and any fractional part will be truncated (rounded down). 
              This behavior is known as integer truncation. */
            
            Player[i].average = static_cast<double>(Player[i].runs) / (Player[i].innings - Player[i].t_not_out);
        } else {
            Player[i].average = 0;    // To avoid division by zero
        }
        cout << endl;
    }

    cout << "--------------------------------------------------------------------------------------------\n";
    cout << "Name\t\t| Runs\t\t| Innings\t| Times Not Out\t| Average\n";
    cout << "--------------------------------------------------------------------------------------------\n";

    for (int i = 0; i < n; i++) {
        cout << setw(15) << left << Player[i].name <<"\t|  ";
        cout <<  Player[i].runs <<"\t\t|  ";
        cout <<  Player[i].innings <<"\t\t|  ";
        cout <<  Player[i].t_not_out <<"\t\t|  ";
        cout << fixed << setprecision(2) << Player[i].average << endl; // fixes the batting average to 2 decimal points
        cout << "--------------------------------------------------------------------------------------------\n";
    }

    return 0;
}
