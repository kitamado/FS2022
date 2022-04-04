#ifndef ACCOUNT_H
#define ACCOUNT_H


class Account
{
protected:
    double m_balance;
public:
    Account(double balance);
    void credit(double val);
    void debit(double val);
    void printBalance();
};

#endif // ACCOUNT_H
