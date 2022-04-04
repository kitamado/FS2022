#include <iostream>
#include "checkingaccount.h"

int main()
{
  CheckingAccount myAccount(1000, 0.5);  // initial amount and fee
  myAccount.credit(250); // ok
  myAccount.printBalance(); // −> 1250
  myAccount.debit(1000); // ok
  myAccount.printBalance(); // −> 249.5
  myAccount.debit(249.5); // Waring : Not enough funds
  myAccount.debit(249); // ok
  myAccount.printBalance(); // −> 0
}

/* 2.2 Code Snippet
 * a) Base()
 *    Derived()
 *    Base()
 *    ~Base()
 *    ~Derived()
 *    ~Base()
 *
 * b)  Would not compile. Because 'm_x' is a 'private' member of Base, when calling d.print()
 *     this snippet tries to access m_x and thus produces an error.
 *
 *     If 'm_x' is declared as 'protected' then the output would be:
 *     Base()
 *     Derived()
 *     Derived: 5
 *     ~Derived()
 *     ~Base()
 *
 *  2.3 Order of Construction & Destruction
 *  - see 'dummyABC.cpp'
 *  - Construction: A(), C(), B(), ABC().
 *    Destruction: ~ABC(), ~B(), ~C(), ~A()
 *
 *  - The order of construction: Base constructor -> Derived constructor.
 *    And the order of base cTor is like class inheretance declaration.
 *
 *    The destruction order: Derived destructor -> Base destructor
 *    goes in exactly the reverse order of construction.
 *
 *  2.4 Access Specifiers
 *  - see 'access.cpp'
 *  - set 'public: type m_A' or 'protected type m_A' in class A so m_A is accessible by class B
 *    set class B: private A so m_A is private for class C
 *    class C can inherite B in any mode because for a private value in upper class it is inaccessible in derived class anyway.
 *
 *  - so for type m_A in class A there are two ways, public and protected. I think set m_A as protected is preferable
 *    in order to expose its member attribute only to the derived classes B
 */

