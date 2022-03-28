#include "vector.h"
#include <iostream>
#include<algorithm>

Vector::Vector() : m_data(nullptr), m_size(0)
{
}

Vector::Vector(int size) : m_size(size)
{
     m_data = new int[m_size];
}

Vector::Vector(int size, int value) : m_size(size)
{
    m_data = new int[m_size];
    for (int i = 0; i < m_size; ++i)
    {
        m_data[i] = value;
    }
}

Vector::Vector(const Vector &copySource)
{
    m_size = copySource.m_size;
    m_data = new int[m_size];
    for (int index = 0; index < m_size; ++index)
    {
        m_data[index] = copySource.m_data[index];
    }
}

Vector& Vector::operator=(const Vector &copySource)
{
}

Vector::Vector(Vector &&moveSource):m_data(nullptr), m_size(0)
{
    if(this != &moveSource)
    {
        delete [] m_data;
        m_data = moveSource.m_data;
        m_size = moveSource.m_size;
        moveSource.m_data = nullptr;
        moveSource.m_size = 0;
    }
}

Vector& Vector::operator=(Vector&& moveSource)
{
}

Vector::~Vector()
{
    delete [] m_data;
}

void Vector::push_back(int val)
{
     int *new_data = new int[m_size+1];
     if (m_data != nullptr) {
         memcpy(new_data, m_data, m_size*sizeof(int));
         delete [] m_data;
     }
     new_data[m_size] = val;
     m_data = new_data;
     m_size = m_size + 1;
}

int Vector::pop_back()
{
    int *new_data = new int[m_size-1];
    int val = -1;
    if (m_data == nullptr) {
        std::cout << "WARNING: Array already empty" << std::endl;
    }
    else {
         memcpy(new_data, m_data, (m_size-1)*sizeof(int));
         val = m_data[m_size-1];
         delete [] m_data;
    }
    m_data = new_data;
    m_size = m_size - 1;
    return val;
}

void Vector::clear()
{   
    m_data = nullptr;
    m_size = 0; 
}

int Vector::size()
{
    return m_size;
}

int Vector::at(int index)
{
    if (m_data == nullptr) {
        std::cout << "WARNING: Array is empty!" << std::endl;
        return -1;
    }
    else if (index < 0 || index >= m_size) {
        std::cout << "WARNING: Index out of range!" << std::endl;
        return -1;
    }
    return m_data[index];
}
