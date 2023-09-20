/* A table gives a list of car models and the number of units sold in each type in a specified period.
   Write a program to store this table in a suitable container, and display interactively the total 
   value of a particular model sold, given the unit-cost of that model.
*/


#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    // Create a map to store car models as keys and units sold as values
    map<string, int> carSales;

    // Populate the map with car models and units sold
    carSales["Model A"] = 100;
    carSales["Model B"] = 150;
    carSales["Model C"] = 75;
    carSales["Model D"] = 120;

    // Interactive calculation of total value for a given model
    string model;
    int unitCost;

    cout << "Enter the car model: ";
    getline(cin, model);

    // Check if the model exists in the map
    if (carSales.find(model) != carSales.end()) {
        cout << "Enter the unit cost for " << model << ": ";
        cin >> unitCost;

        int unitsSold = carSales[model];
        int totalValue = unitsSold * unitCost;

        cout << "Total value for " << model << " sold: Rs" << totalValue << endl;
    } else {
        cout << "Car model not found in the table." << endl;
    }

    return 0;
}
