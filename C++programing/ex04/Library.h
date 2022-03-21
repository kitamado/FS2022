#ifndef LIBRARY_H
#define LIBRARY_H
#include "Book.h"
#include <iostream>
#include <vector>
using namespace std;

class Library
{
public:
    Library();
    void addBook(Book bk); // public member function to add new books
    void cleanup(); // public member function to clean up the library, i.e. to remove invalid book entries, using the above delete book function
    void printInventary(); // public member function to print the inventory, i.e. complete number, number of valid and number non-valid books
private:
    vector<Book> m_booksList; // private vector storing all the books

   void deleteBook(Book bk); // private member function to delete books
};

#endif // LIBRARY_H
