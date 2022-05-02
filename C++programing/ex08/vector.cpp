#include "vector.h"
#include <iostream>
#include <algorithm>

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



Vector &Vector::operator=(const Vector& copySource)
{
    if(this != &copySource){
        if(this->m_size != copySource.m_size){
            delete[] this->m_data;
            m_data = new int[copySource.m_size];
        }
        this->m_size = copySource.m_size;
        for(int i = 0; i < copySource.m_size;i++){
            this->m_data[i] = copySource.m_data[i];
        }
    }
    return *this;
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
    if ((moveSource.m_data != nullptr) && (this != &moveSource)){
        delete[] m_data;
        m_data = moveSource.m_data;
        m_size = moveSource.m_size;
        moveSource.m_size = 0;
        moveSource.m_data = nullptr;
    }
    return *this;
}

Vector::~Vector()
{
    delete [] m_data;
}

void Vector::push_back(int val)
{
     int *new_data = new int[m_size+1];
//     if (m_data != nullptr) {
//         memcpy(new_data, m_data, m_size*sizeof(int));
//         delete [] m_data;
//     }
     copy(m_data, m_data + m_size, new_data);
     delete [] m_data;
     new_data[m_size] = val;
     m_data = new_data;
     m_size = m_size + 1;
}

int Vector::pop_back()
{
    int *new_data = new int[m_size-1];
//    int val = -1;
//    if (m_data == nullptr) {
//        cout << "WARNING: Array already empty" << endl;
//    }
//    else {
//         memcpy(new_data, m_data, (m_size-1)*sizeof(int));
//         val = m_data[m_size-1];
//         delete [] m_data;
//    }
    int val = m_data[m_size-1];
    copy(m_data, m_data + m_size-1, new_data);
    delete[] m_data;
    m_data = new_data;
    m_size = m_size - 1;
    return val;
}

void Vector::clear()
{
    delete [] m_data;
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
        cout << "WARNING: Array is empty!" << endl;
        return -1;
    }
    else if (index < 0 || index >= m_size) {
        cout << "WARNING: Index out of range!" << endl;
        return -1;
    }
    return m_data[index];
}

ostream& operator<<(ostream& os, const Vector& vec)
{
    int n_values = min(vec.m_size,(int)5);

    os << "[";
    for (int i = 0; i < n_values; i++) {
        os << vec.m_data[i];
        if(i < n_values-1){
            os << ", ";
        }
    }
    os << "]";
    return os;
}


Vector Vector::operator+(const Vector &parameter)
{
    if(this->m_size != parameter.m_size){
        cerr << "Dimension mismatch" << endl;
        return Vector();
    }
    Vector result(this->m_size);
    for (int i = 0; i < this->m_size; i++) {
        result.m_data[i] = this->m_data[i]+parameter.m_data[i];
    }
    return result;
}

Vector Vector::operator*(const Vector &parameter)
{
    if(this->m_size != parameter.m_size){
        cerr << "Dimension mismatch" << endl;
        return Vector();
    }
    Vector result(this->m_size);
    for (int i = 0; i < this->m_size; i++) {
        result.m_data[i] = this->m_data[i]*parameter.m_data[i];
    }
    return result;
}
