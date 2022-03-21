#include "Library.h"
#include <algorithm>

Library::Library()
{

}

void Library::addBook(Book bk)
{
    m_booksList.push_back(bk);
}

void Library::deleteBook(Book bk)
{
    for (vector<Book>::iterator it = m_booksList.begin(); it != m_booksList.end(); ++it) {
        if (it->getISBN() == bk.getISBN()) {
            m_booksList.erase(it);
            break;
        }
    }
}

void Library::cleanup()
{

    std::vector<Book>::iterator it = m_booksList.begin();
    while(it != m_booksList.end())
    {
           if(!it->getValidity())
               deleteBook(*it);
           else it++;

     }
}

void Library::printInventary()
{
    cout << "Number of total books: " << m_booksList.size() << endl;
    int n_valid{0}, n_invalid{0};
    for (vector<Book>::iterator it = m_booksList.begin(); it != m_booksList.end(); ++it) {
        if (it->getValidity()) n_valid++;
        else n_invalid++;
    }
    cout << "Number of valid books: " << n_valid << endl;
    cout << "Number of invalid books: " << n_invalid << endl;
}
