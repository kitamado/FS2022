#include <iostream>
#include "Book.h"
#include "Library.h"
using namespace std;

int main()
{
   // You have a bag of books
    
    Book book0;
    Book book1("Sams Teach Yourself C++", "Siddharta Rao", "0-7897-5774-5"); 
    Book book2("C++ Primer", "Stanley B. Lippman", "0321714113"); 
    Book book3("The C++ Programming Language", "Bjarne Stroustrup","0321563840"); 
    Book book4("Programming Python", "Mark Lutz","0-596-15810-2"); 
    Book book5("TIBITS AT HOME", "Betty Bossy","1-234-567-8"); 
    Book book6("Thinking in Java", "","9780596009205"); 
    Book book7("Multiple View Geometry in Computer Vision", "","1139449141"); 
    Book book8("","Paul Kimmel","0-321-99278-4");

    // Bring all the books to the library
    Library lib; // Create instance of library
    lib.addBook(book1);
    lib.addBook(book2);
    lib.addBook(book3);
    lib.addBook(book4);
    lib.addBook(book5);
    lib.addBook(book6);
    lib.addBook(book7);
    lib.addBook(book8);

    // Give an overview
    lib.printInventary();

    // Clean non−valid book
    lib.cleanup();

    // Overview again
    lib.printInventary();


    // Now only C++ books are left in the library
    return 0;
}
