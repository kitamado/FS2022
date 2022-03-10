#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <numeric>
// #include "function_to_be_fixed.cpp"

using namespace std;


int *allocateArray(const int length)
{
    // int temp[length];
    /* The memory location where temp points is released after function ends.
     * use new/delete[] insdead */
    int *temp = new int[length];
    return temp;
}


int main()
{
    int n{0};
    cout << "How many values do you want to enter?: ";
    cin >> n;
    int *unsafe_arr = new int[n];
    int sum1 = 0; // calculate results with index access using the operator []
    int sum2 = 0; // calculate results with pointer arithmetic using *
    int arr_min = 99999;
    int arr_max = -99999;
    // 2.1.1a
    for (int i = 0; i < n; i++)
    {
        cout << (i + 1) << ". value: ";
        cin >> unsafe_arr[i];
        sum1 += unsafe_arr[i];
    }
    cout << "-----------------------------" << endl;
    // 2.1.1b
    for (int i = 0; i < n; i++)
    {
        sum2 += *(unsafe_arr + i);
        if (arr_max < unsafe_arr[i])
            arr_max = unsafe_arr[i];
        if (arr_min > unsafe_arr[i])
            arr_min = unsafe_arr[i];
    }
    // delete array
    delete[] unsafe_arr;
    if (sum1 == sum2)
    {
        cout << "Results:" << endl
             << "Sum: " << sum1 << endl;
    }
    cout << "Min: " << arr_min << endl;
    cout << "Max: " << arr_max << endl;
    cout << "\n=================================\n"
         << endl;

    // 2.1.2
    cout << "Implement the program using smart pointer std::unique_ptr:\n"
         << endl;
    int size{0}, sum3{0}, arr_min2{99999}, arr_max2{-99999};
    cout << "How many values do you want to enter?: ";
    cin >> size;
    // Create unique pointer to int array
    std::unique_ptr<int[]> smartPtr(new int[size]);
    for (int i = 0; i < size; i++)
    {
        cout << (i + 1) << ". value: ";
        cin >> smartPtr[i];
        sum3 += smartPtr[i];
    }
    cout << "-----------------------------" << endl;
    for (int i = 0; i < size; i++)
    {
        if (arr_max2 < smartPtr[i])
            arr_max2 = smartPtr[i];
        if (arr_min2 > smartPtr[i])
            arr_min2 = smartPtr[i];
    }

    cout << "\nResults:" << endl
         << "Sum: " << sum3 << endl;

    cout << "Min: " << arr_min2 << endl;
    cout << "Max: " << arr_max2 << endl;

    // 2.1.3
    cout << "\n=================================\n"
         << endl;
    cout << "Implement the program using STL-container std::vector:" << endl;
    size = 0;
    int num_get{};
    cout << "How many values do you want to enter?: ";
    cin >> size;
    std::vector<int> vec_array;
    for (int i = 0; i < size; i++)
    {
        cout << (i + 1) << ". value: ";
        cin >> num_get;
        vec_array.push_back(num_get);
    }

    cout << "\nResults:" << endl
         << "Sum: " << std::accumulate(vec_array.begin(), vec_array.end(), 0) << endl;

    cout << "Min: " << *std::min_element(vec_array.begin(), vec_array.end()) << endl;
    cout << "Max: " << *std::max_element(vec_array.begin(), vec_array.end()) << endl;

    // 2.2.1 What’s wrong here?
    // cannot assign int value to int * point type, dereference needed
    int *pointToAnInt1 = new int;
    // pointToAnInt = 9;
    *pointToAnInt1 = 9;
    std::cout << "2.2.1 The value at pointToAnInt: " << *pointToAnInt1 << endl;
    delete pointToAnInt1;

    // 2.2.2 Why and where does the program crash?
    int *pointToAnInt2 = new int;
    int *pNumberCopy = pointToAnInt2;
    *pNumberCopy = 30;
    std::cout << *pointToAnInt2 << endl;
    delete pNumberCopy;
    /* the line below will cause program to crash, rasing error: pointer to be freed was not allocated
     * because pointToAnInt2 and pNumberCopy point to the same memory location, when pNumberCopy is freed
     * pointToAnInt2 also points to nowhere. Thus cannot be delete agian.
     */
    // delete pointToAnInt2;

    // 2.2.3   Fix the function!
    // see function_to_be_fixed.cpp
    int *alloc = allocateArray(10);
    delete[] alloc;

    // 2.2.4
    int array[5]{0, 1, 2, 3};
    // for (int count = 0; count <= 5; ++count)
    //  array doesn't have index 5
    for (int count = 0; count < 5; ++count)
        std::cout << array[count] << " ";

    cout << endl;
    return 0;
}
