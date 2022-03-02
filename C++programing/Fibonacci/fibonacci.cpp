#include "fibonacci.h"


int Fibonacci::fibonacci(int f, int fprev) {
    // add a breakpoint at next line and use debugger. It exceed the upper integer limit after 46 iterations.
    int tmp = f + fprev;
    if (tmp < f)
        return -1;
    return tmp;
}


