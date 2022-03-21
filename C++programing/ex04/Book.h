#ifndef Book_H
#define Book_H
#include <iostream>
#include <string>
using namespace std;

class Book
{
public:
    Book(); // default constructor
    Book(string title, string author, string isbn); // custom constructor

    bool getValidity();   // 1. public member function to request the validity status of the book
    void displayInfo();             // 2. public member function printing out the book information, i.e. title, author, ISBN and validity status
    string getISBN(); // for class Librarg delete book compare

private:
    string m_title;
    string m_author;
    string m_isbn;
    bool m_isValid; // private boolean member holding the validity status of book: e.g isValid. If one or more book descriptions aren’t correct the book is marked as non-valid
    void checkIntegrality(string m_title, string m_author); // private member function checking the existence of title and author, i.e. no empty strings allowed
    void checkValidity(string m_isbn); // A private member function checking the validity of ISBN-10 (number of digits and check sum (see Eq.(2)) during construction.
};

#endif // Book_H


