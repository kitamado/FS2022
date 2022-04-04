#include "account.h"
#include "checkingaccount.h"
#include <iostream>

using namespace std;

CheckingAccount::CheckingAccount(double balance, double fee) : Account(balance), m_fee(fee)
{
}

void CheckingAccount::debit(double val)
{
    if (val+m_fee <= m_balance)
    {
        m_balance = m_balance - m_fee - val;
    } else {
        cout << "Waring: Not enough funds!" << endl;
    }
}
