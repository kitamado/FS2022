#ifndef FIBONACCI_H
#define FIBONACCI_H
#include <iostream>
#include <cmath>
#include <iomanip>

class Fibonacci
{
public:
    int f, fprev;
    static int fibonacci(int f, int fprev);
};

#endif // FIBONACCI_H
