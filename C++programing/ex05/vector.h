#ifndef VECTOR_H
#define VECTOR_H


class Vector
{
public:
    // default constructor
    Vector();
    Vector(int size);
    Vector(int size, int value);
    // destructor
    ~Vector();
    // copy cTor
    Vector(const Vector& copySource);
    // copy assignment cTor
    Vector& operator=(const Vector& copySource);
    // move cTor
    Vector(Vector&& moveSource);
    // move assignment cTor
    Vector& operator=(Vector&& moveSource);

    // additional methods
    int at(int index);
    int size();
    void push_back(int val);
    int pop_back();
    void clear();
private:
    int* m_data;
    int m_size;
};

#endif // VECTOR_H
