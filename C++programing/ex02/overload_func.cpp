#include "overload_func.h"

void printType(int intNumber)
{
    //cout << "type is " << typeid(intNumber).name() << endl;
    cout << "Type is int" << endl;
}


void printType(double doubleNumber)
{
     //cout << "type is " << typeid(doubleNumber).name() << endl;
     cout << "Type is double" << endl;
}


void printType(float floatNumber)
{
     //cout << "type is " << typeid(floatNumber).name() << endl;
     cout << "Type is float" << endl;
}


void printType(string stringinput)
{
     //cout << "type is " << typeid(stringinput).name() << endl;
     cout << "Type is string" << endl;
}
