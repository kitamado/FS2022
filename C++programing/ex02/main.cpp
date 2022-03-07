#include <iostream>

#include "calculater.h"
#include "default_values.h"
#include "overload_func.h"
#include "monte_carlo_pi.h"

using namespace std;

int main()
{
    // ex 2.1
    cout << "2.1 Pass-by-Value & Pass-by-Reference" << endl;
    cout << "Enter two numbers: ";
    int varA{}, varB{}, result{};
    cin >> varA >> varB;
    //ex 2.1.1
    cout << "The sum is " << my_add1(varA, varB) << endl;
    //ex 2.1.2
    my_add2(varA, varB, result);
    cout << "The sum is " << result << endl;
    // ex 2.1.3
    cout << endl;
    cout << "2.1.3 What’s wrong here?" << endl;
    cout << "varible num should be passed by reference (&num), so defination void doubleNumber(int &num){num = num * 2;}" << endl;

    // ex 2.2
    cout << endl;
    cout << "2.2 Default Values" << endl;
    cout << "addNumbers(1, 2, 3, 4): " << addNumbers(1, 2, 3, 4) << endl;
    cout << "addNumbers(1, 2, 3): " << addNumbers(1, 2, 3) << endl;
    cout << "addNumbers(1, 2): " << addNumbers(1, 2) << endl;
    cout << "addNumbers(1): " << addNumbers(1) << endl;
    cout << "addNumbers(): " << addNumbers() << endl;

    // ex 2.3
    cout << endl;
    cout << "2.3 Function Overloading" << endl;
    int intNumber = 42;
    printType(intNumber); // −> Type is int
    float floatNumber = 1.666;
    printType(floatNumber); // −> Type is float
    double doubleNumber = 23.3421;
    printType(doubleNumber);
    string stringinput = "hello world";
    printType(stringinput);

    // ex 3.1 Setup Random Number Generator
    cout << endl;
    cout << "3 Calculate Pi" << endl;
    int n = 5000000;
    cout << "total round: " << n << endl;
    cout << "Simulated Pi: " << simulate_pi(n) << endl;


}
