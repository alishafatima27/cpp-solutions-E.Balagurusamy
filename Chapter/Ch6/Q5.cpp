// Modify the program of Exercise 6.4 to demonstrate the use of pointers to access the members.

/* Approach : Instead of creating Book objects directly, I created pointers to Book objects: 
           Book *b1, *b2;.

   When initializing the Book objects, I used the new operator to allocate memory and create instances 
   of the Book class using pointers.

   Accessing member functions and variables of the Book class is done using the -> operator instead 
   of the '.' operator.
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
    void update_price(float new_price)
    {
        price = new_price ; 
    }
    static int s_trans ; 
    static int un_trans ; 

public:
    Book(const char* t, const char* a, const char* pub, float pr, int sp); // Parametrized Constructor
    const char* getTitle(); // Function to access the title of the book
    const char* getAuthor(); // Function to access the author of the book
    void display(); // Function to display details of the book
    void isAvail(); // Function to check if stock is available
    int getStock(); // Function to access stock count
    int cal(int copy); // Function to calculate total price
    void purchase(int copy); // Function to simulate a purchase
    static void displayT_Stats(); 
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

int Book::s_trans = 0;
int Book::un_trans = 0;

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

void Book::purchase(int copy)
{
    if (copy <= stock_pos)
    {
        cout << "Purchase successful." << endl;
        s_trans++;
        stock_pos -= copy;
        cout << "Stock left : " << stock_pos ; 
    }
    else
    {
        cout << "Purchase unsuccessful. Not enough stock." << endl;
        un_trans++;
    }
}

void Book::displayT_Stats()
{
    cout << "Transaction Statistics:\n";
    cout << "Successful Transactions: " << s_trans << endl;  
    cout << "Unsuccessful Transactions: " << un_trans << endl;
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
    //Book objects with initial details using pointers
    Book *b1 , *b2 ; 
    b1 =new  Book("Pride and Prejudice", "Jane Austen", "Penguin Books", 600.0, 8);
    b2 = new Book("Introduction to Data Structures", "Thomas H. Cormen", "MIT Press", 750.0, 5);

    // Input variables for user input
    char title[100];
    char author[100];
    int copies;

    cout << "Enter title: ";
    cin.getline(title, 100);

    cout << "Enter author: ";
    cin.getline(author, 100);

    // Check if the input matches b1's details
    if (strcmp(b1->getTitle(), title) == 0 && strcmp(b1->getAuthor(), author) == 0)
    {
        b1->display();
        b1->isAvail();
        cout << "Enter number of copies: ";
        cin >> copies;
        if (copies <= b1->getStock())
        {
            cout << "Copies are available." << endl;
            cout << "Total amount: Rs." << b1->cal(copies) << "/-" << endl;
            b1->purchase(copies);
            b1->displayT_Stats();
        }
        else
        {
            cout << "\nRequired copies not in stock\n";
        }
    }
    else
    {
        // Check if the input matches b2's details
        if (strcmp(b2->getTitle(), title) == 0 && strcmp(b2->getAuthor(), author) == 0)
        {
            b2->display();
            b2->isAvail();
            cout << "Enter number of copies: ";
            cin >> copies;
            if (copies <= b2->getStock())
            {
                cout << "Copies are available." << endl;
                cout << "Total amount: Rs." << b2->cal(copies) << "/-" << endl;
                b2->purchase(copies);
                b2->displayT_Stats();
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
