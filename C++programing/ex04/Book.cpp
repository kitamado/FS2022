#include "Book.h"
#include <iostream>
#include <algorithm>

Book::Book() : m_title(""), m_author(""), m_isbn(""), m_isValid(false)// use initialiszer lists
{
    // std::cout << "Default Book called" << std::endl;
}

Book::Book(string title, string author, string isbn) :
    m_title(title),
    m_author(author),
    m_isbn(isbn),
    m_isValid(true)
{
    checkIntegrality(m_title, m_author);
    checkValidity(m_isbn);
   // std::cout << "Custom Book called" << std::endl;
}

bool Book::getValidity()
{
    if (m_isValid) return true;
    else return false;
}

void Book::displayInfo()
{
    std::cout << "Book title: "
                << m_title << endl 
                << "Author: "
                << m_author << endl
                << "ISBN: "
                << m_isbn << endl
                << "Validity status: "
                << m_isValid << std::endl;
}

void Book::checkIntegrality(string m_title, string m_author)
{
    if(m_title.empty() || m_author.empty()) m_isValid = false;
}

void Book::checkValidity(string m_isbn)
{
    string r_isbn = m_isbn;
   // std::cout << r_isbn << std::endl;
    r_isbn.erase(std::remove(r_isbn.begin(), r_isbn.end(), '-' ), r_isbn.end());
    //std::cout << r_isbn << " " << r_isbn.length() << std::endl;
    if (r_isbn.length() != 10) {
        m_isValid = false;
        return;
    }
    int isbn_sum{0}, digit{0};
    for (int i = 0; i < 10; i++) {
        digit = std::stoi(r_isbn.substr(i,1));
        isbn_sum += (i+1) * digit;
       // std::cout << i << " " << digit << " " << isbn_sum << std::endl;
    }

    if (isbn_sum % 11 != 0) m_isValid = false;
}

string Book::getISBN()
{
    return m_isbn;
}
