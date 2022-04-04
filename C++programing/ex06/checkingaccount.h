#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include "account.h"

class CheckingAccount : public Account
{
private:
    double m_fee;

public:
    CheckingAccount(double balance, double fee);
    void debit(double val);
};

#endif // CHECKINGACCOUNT_H
