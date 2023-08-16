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

class Book
{
private:
    char *title, *author, *publisher; // Pointers to store book details
    float price;
    int stock_pos;

public:
    Book(const char* t, const char* a, const char* pub, float pr, int sp); // Parametrized Constructor
    const char* getTitle(); // Function to access the title of the book
    const char* getAuthor(); // Function to access the author of the book
    void display(); // Function to display details of the book
    void isAvail(); // Function to check if stock is available
    int getStock(); // Function to access stock count
    int cal(int copy); // Function to calculate total price
    ~Book(); // Destructor to release memory
};

Book::Book(const char* t, const char* a, const char* pub, float pr, int sp)
{
    // Dynamically allocate memory for each member string
    title = new char[strlen(t) + 1];
    strcpy(const_cast<char*>(title), t);

    author = new char[strlen(a) + 1];
    strcpy(const_cast<char*>(author), a);

    publisher = new char[strlen(pub) + 1];
    strcpy(const_cast<char*>(publisher), pub);

    price = pr;
    stock_pos = sp;
}

const char* Book::getTitle()
{
    return title;
}

const char* Book::getAuthor()
{
    return author;
}

void Book::display()
{
    cout << "\nDetails\n";
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Publisher: " << publisher << endl;
    cout << "Price: Rs." << price << "/-" << endl;
    cout << "Copies in Stock: " << stock_pos << endl;
}

void Book::isAvail()
{
    if (stock_pos > 0)
    {
        cout << "Stock is Available." << endl;
    }
    else
    {
        cout << "Stock not available." << endl;
    }
}

int Book::getStock()
{
    return stock_pos;
}

int Book::cal(int copy)
{
    return price * copy;
}

Book::~Book()
{
    // Destructor to release dynamically allocated memory
    delete[] author;
    delete[] title;
    delete[] publisher;
}

int main()
{
    // Create two Book objects with initial details
    Book b1("Pride and Prejudice", "Jane Austen", "Penguin Books", 600.0, 8);
    Book b2("Introduction to Data Structures", "Thomas H. Cormen", "MIT Press", 750.0, 5);

    // Input variables for user input
    char title[100];
    char author[100];
    int copies;

    cout << "Enter title: ";
    cin.getline(title, 100);

    cout << "Enter author: ";
    cin.getline(author, 100);

    // Check if the input matches b1's details
    if (strcmp(b1.getTitle(), title) == 0 && strcmp(b1.getAuthor(), author) == 0)
    {
        b1.display();
        b1.isAvail();
        cout << "Enter number of copies: ";
        cin >> copies;
        if (copies <= b1.getStock())
        {
            cout << "Copies are available." << endl;
            cout << "Total amount: Rs." << b1.cal(copies) << "/-" << endl;
        }
        else
        {
            cout << "\nRequired copies not in stock\n";
        }
    }
    else
    {
        // Check if the input matches b2's details
        if (strcmp(b2.getTitle(), title) == 0 && strcmp(b2.getAuthor(), author) == 0)
        {
            b2.display();
            b2.isAvail();
            cout << "Enter number of copies: ";
            cin >> copies;
            if (copies <= b2.getStock())
            {
                cout << "Copies are available." << endl;
                cout << "Total amount: Rs." << b2.cal(copies) << "/-" << endl;
            }
            else
            {
                cout << "\nRequired copies not in stock\n";
            }
        }
        else
        {
            cout << "\nBook not Found." << endl;
        }
    }

    return 0;
}
