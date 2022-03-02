#include <iostream>
#include "fibonacci.h"
using namespace std;


int main() {
    int f = 1;
    int fprev = 0;
    int exceed_it = 0;
    cout << fprev << endl;
    do{
        exceed_it++;
        cout << f << endl;
        if (fprev != 0) {
            cout << "Ratio: " << setprecision(17) << fixed << float(f)/fprev << " - Dev[%]:" << setprecision(17) << ((1+sqrt(5))/2-float(f)/fprev)/((1+sqrt(5))/2)*100 << endl;
        }
        int tmp = Fibonacci::fibonacci(f, fprev);
        if (tmp == -1) break;
        fprev = f;
        f = tmp;
    }while (true);
    cout << endl;
    cout << "At " << exceed_it << " iterations the fibonacci number exceed the integer upper limit" << endl;
    cout << "The upper limit of int in my system is " << numeric_limits<int>::max() << endl;
    cout << endl;

    return 0;
}
