/* Write a program that accepts a shopping list of five items from the keyboard and stores them in a vector.
   Extend the program to accomplish the following : 
        (a) To delete a specified item in the list.
        (b) To add an item at a specified location.
        (c) To add an item at the end.
        (d) To print the contents of the vector.
  */


#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> shoppingList(5);

    // Accepting five items from the keyboard
    cout << "Enter five items for your shopping list:" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "Item " << i + 1 << ": ";
        getline(cin, shoppingList[i]);
    }

    // Displaying the initial shopping list
    cout << "Your initial shopping list:" << endl;
    for (const string& item : shoppingList) {
        cout << item << endl;
    }

    // (a) Deleting a specified item
    string itemToDelete;
    cout << "Enter an item to delete from the list: ";
    getline(cin, itemToDelete);

    for (auto it = shoppingList.begin(); it != shoppingList.end(); ++it) {
        if (*it == itemToDelete) {
            shoppingList.erase(it);
            break;
        }
    }

    // (b) Adding an item at a specified location
    int position;
    cout << "Enter the position to add an item: ";
    cin >> position;
    cin.ignore(); // Clearing the newline character

    if (position >= 1 && position <= shoppingList.size() + 1) {
        cout << "Enter the item to add: ";
        string newItem;
        getline(cin, newItem);

        shoppingList.insert(shoppingList.begin() + position - 1, newItem);
    } else {
        cout << "Invalid position. Item not added." << endl;
    }

    // (c) Adding an item at the end
    cout << "Enter an item to add at the end: ";
    string newItemAtEnd;
    getline(cin, newItemAtEnd);
    shoppingList.push_back(newItemAtEnd);

    // (d) Printing the contents of the vector
    cout << "Your updated shopping list:" << endl;
    for (const string& item : shoppingList) {
        cout << item << endl;
    }

    return 0;
}
