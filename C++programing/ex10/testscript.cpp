#include <iostream>
#include "uniqueptr.h"
#include "sharedptr.h"

using namespace std;

UniquePtr<double> checkMove(UniquePtr<double> UP)
{
    *UP += 1;
    return UP;
}

int main()
{
    cout << "*** Test Unique Pointer ***" << endl << endl;
    UniquePtr<double> up1(new double(3.1415));
    cout << "Value of up1: " << *up1 << endl << endl;

    {   // Create scope to check move-assign
        UniquePtr<double> up2(new double(23));
        cout << "Value of up2: " << *up2 << endl << endl;
        up1 = std::move(up2);
    }
    cout << "Value of up1 after move: " << *up1 << endl << endl;
    UniquePtr<double> up2 = checkMove(std::move(up1));
    cout << "Value of up1 after check move: " << *up2 << endl << endl;


    cout << "*** Test SharedPointer ***" << endl << endl;

    SharedPtr<int> sp1;
    cout << "UseCount of sp1: " << sp1.useCount() << endl << endl;

    SharedPtr<int> sp2(new int(42));
    cout << "UseCount of sp2: " << sp2.useCount() << endl;
    cout << "Value of sp2 is: " << *sp2 << endl << endl;

    {  // Create scope to check copy constructor
        SharedPtr<int> sp3(sp2);
        cout << "UseCount after copy: sp2: " << sp2.useCount() << " sp3: " << sp3.useCount() << endl;
        cout << "Values after copy: sp2: " << *sp2 << " sp3: " << *sp3 << endl << endl;

    }
    cout << "UseCount of sp2: " << sp2.useCount() << endl << endl;

    {   // Create scope to check assignment operator call
        SharedPtr<int> sp3 = sp2;
        cout << "UseCount after copy assign: sp2: " << sp2.useCount() << " sp3: " << sp3.useCount() << endl;
        cout << "Values after copy assign: sp2: " << *sp2 << " sp3: " << *sp3 << endl << endl;
    }
    cout << "UseCount of sp2: " << sp2.useCount() << endl;

    return 0;
}
