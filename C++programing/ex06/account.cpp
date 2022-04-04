#include "account.h"
#include <iostream>

using namespace std;

Account::Account(double balance) : m_balance(balance)
{

}

void Account::credit(double val)
{
    m_balance += val;
}

void Account::debit(double val)
{
    if (val <= m_balance)
    {
        m_balance -= val;
    } else {
        cout << "Waring: Not enough funds!" << endl;
    }
}

void Account::printBalance()
{
    cout << "Your current balance is " << m_balance << endl;
}
