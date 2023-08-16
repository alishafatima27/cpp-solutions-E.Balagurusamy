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
    /* data */
    char *title, *author, *publisher ;
    float price ;
    int stock_pos ;
public:
    Book(char *t , char *a , char *pub , float pr , int sp ) ;
    const char* getTitle() ;
    const char* getAuthor() ;
    void display()
    {
        cout << "\nDetails\n" ;
        cout << "Title : " << title << endl ; 
        cout << "Author : " << author << endl ;
        cout << "Publisher : " << publisher << endl ; 
        cout << "Price : Rs."<<price<<"/-" << endl ;
        cout << "Copies in Stock : " << stock_pos << endl ; 
    }
    void isAvail()
    {
        if (stock_pos > 0)
        {
            cout << "Book is Available." ; 
        }
        else
        {
            cout << "Not available." ; 
        }
    }
    int getStock() ;
    int cal(int cop);
};

Book::Book(char *t , char *a , char *pub , float pr , int sp)
{
    title = new char[strlen(t)+1] ; 
    strcpy(title,t) ;

    author = new char[strlen(a)+1] ; 
    strcpy(author,a) ;

    publisher = new char[strlen(pub)+1] ; 
    strcpy(publisher,pub) ; 

    price = pr ; 

    stock_pos = sp ; 
}
const char * Book::getTitle()
{
   return title ;
}
const char * Book::getAuthor()
{
    return author ;
}
int Book::getStock()
{
    return stock_pos ;
}
int Book::cal(int copy)
{
    return price*copy ; 
}

Book::~Book()
{ 
        delete[] author ;
        delete[] title ;
        delete[] publisher ;
}
int main()
{
    Book b1("Pride and Prjudice","Jane Austen","Penguine books",600.0,8) ; 
    Book b2("Pride","Jane","Pub books",400.0,3) ;
    char title[100] ;
    char author[100] ;
    int copies ; 

    cout << "Enter title : " ;
    cin.getline(title,100) ;

    cout << "Enter author : " ;
    cin.getline(author,100) ;

    if (strcmp(b1.getTitle(), title) == 0 && (strcmp(b1.getAuthor(), author) == 0 ))
    {
        b1.display();
        b1.isAvail();
        cout << "Enter number of copies : ";
        cin >> copies ; 
        if (copies <= b1.getStock())
        {
            cout << "Copies available is available."; 
            cout << "Total amout : " << b1.cal(copies) ; 
        }
    }
    else
    {
        if ((strcmp(b2.getTitle(), title) == 0) && strcmp(b2.getAuthor(), author) == 0)
        {
            b2.display();
            b2.isAvail();
            if (copies <= b2.getStock())
        {
            cout << "Copies is available."; 
            cout << "Total amount : " << b1.cal(copies) ;
        }
        }
        else 
        {
            cout << "\nBook not Found." ;
        }
    }
}

