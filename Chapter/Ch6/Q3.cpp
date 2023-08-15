/*
A book shop maintains the inventory of books that are being sold at the shop. 
The list includes details such as author, title, price, publisher and stock position. 
Whenever a customer wants a book, the sales person inputs the title and
author and the system searches the list and displays whether it is available or not. 
If it is not, an appropriate message is displayed. 
If it is, then the system displays the book details and requests for the number of copies
required. 
If the requested copies are available, the total cost of the requested copies is displayed; 
otherwise the message "Required copies not in stock" is displayed.

Design a system using a class called books with suitable member functions and constructors. 
Use new operator in constructors to allocate memory space required.
*/ 


#include <iostream>
#include <cstring>

using namespace std;

class Book {
private:
    char *author;
    char *title;
    float price;
    char *publisher;
    int stockPosition;

public:
    Book(const char *a, const char *t, float p, const char *pub, int stock) :
        price(p), stockPosition(stock) {
        
        author = new char[strlen(a) + 1];
        strcpy(author, a);

        title = new char[strlen(t) + 1];
        strcpy(title, t);

        publisher = new char[strlen(pub) + 1];
        strcpy(publisher, pub);
    }

    ~Book() {
        delete[] author;
        delete[] title;
        delete[] publisher;
    }

    bool isAvailable() const {
        return stockPosition > 0;
    }

    void displayDetails() const {
        cout << "Author: " << author << endl;
        cout << "Title: " << title << endl;
        cout << "Price: Rs" << price << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Stock Position: " << stockPosition << " copies" << endl;
    }

    float calculateCost(int numCopies) const {
        return price * numCopies;
    }

    void sellCopies(int numCopies) {
        if (numCopies <= stockPosition) {
            cout << "Total Cost: Rs" << calculateCost(numCopies) << endl;
            stockPosition -= numCopies;
        } else {
            cout << "Required copies not in stock" << endl;
        }
    }

    const char* getTitle() const {
        return title;
    }

    const char* getAuthor() const {
        return author;
    }
};

int main() {
    Book book1("Jane Austen", "Pride and Prejudice", 499.99, "Vintage Classics", 5);
    Book book2("Faiz Ahmed Faiz", "Selected Poetry", 299.99, "Penguin Books", 3);
    Book book3("Robert Jordan", "The Eye of the World", 599.99, "Tor Books", 7);

    char title[100];
    char author[100];

    cout << "Enter book title: ";
    cin.getline(title, 100);

    cout << "Enter author name: ";
    cin.getline(author, 100);

    if (strcmp(book1.getTitle(), title) == 0 && strcmp(book1.getAuthor(), author) == 0 && book1.isAvailable()) {
        cout << "Book available. Details:" << endl;
        book1.displayDetails();
        int numCopies;
        cout << "Enter number of copies required: ";
        cin >> numCopies;
        book1.sellCopies(numCopies);
    } else if (strcmp(book2.getTitle(), title) == 0 && strcmp(book2.getAuthor(), author) == 0 && book2.isAvailable()) {
        cout << "Book available. Details:" << endl;
        book2.displayDetails();
        int numCopies;
        cout << "Enter number of copies required: ";
        cin >> numCopies;
        book2.sellCopies(numCopies);
    } else if (strcmp(book3.getTitle(), title) == 0 && strcmp(book3.getAuthor(), author) == 0 && book3.isAvailable()) {
        cout << "Book available. Details:" << endl;
        book3.displayDetails();
        int numCopies;
        cout << "Enter number of copies required: ";
        cin >> numCopies;
        book3.sellCopies(numCopies);
    } else {
        cout << "Book not available." << endl;
    }

    return 0;
}

