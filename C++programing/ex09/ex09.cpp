#include <iostream>
#include <array>
#define SIZE 10
using namespace std;

template <typename T>
class Stack
{
public:
    Stack();
    void push(T ele);
    T pop();
    T peek();
    bool isFull();
    bool isEmpty();
    void print();
private:
    int m_top;
    std::array<T, SIZE> m_data;
};

//specialisation
template <>
std::string Stack<std::string>::pop()
{
    m_top--;
    return "";
}

template <typename T> Stack<T>::Stack() : m_top{-1} {}

template <typename T> void Stack<T>::push(T ele)
{
    if (isFull()) {
        std::cout << "Stack is full\n";
        return;
    }
    m_top = m_top + 1;
    m_data[m_top] = ele;
}

template <typename T> bool Stack<T>::isEmpty()
{
    if (m_top == -1) return 1;
    else return 0;
}

template <typename T> bool Stack<T>::isFull()
{
    if (m_top == (SIZE - 1)) return 1;
    else return 0;
}

template <typename T> T Stack<T>::pop()
{
    T popped = m_data[m_top];
    m_top--;
    return popped;
}


template <typename T> T Stack<T>::peek()
{
    T top = m_data[m_top];
    return top;
}

template <typename T> void Stack<T>::print()
{
    cout << "Elements in stack(from top to button): ";
    for (int i = m_top; i >= 0; i--)
    {
        cout << m_data[i] << " ";
    }
    cout << endl;
}

int main()
{
    Stack<int> integer_stack;
    Stack<double> double_stack;
    Stack<string> string_stack;

    // my QT creater doesn't have experimental todo in Help menu...
    integer_stack.push(1);
    integer_stack.push(2);
    integer_stack.push(3);
    integer_stack.push(11);
    integer_stack.push(22);
    integer_stack.push(33);

    double_stack.push(1.1);
    double_stack.push(1.2);
    double_stack.push(1.3);

    string_stack.push("This");
    string_stack.push("is");
    string_stack.push("a");
    string_stack.push("empty");
    string_stack.push("string");
    string_stack.push("");

    cout << integer_stack.pop() << " is removed from integer stack"
         << endl;

    cout << double_stack.pop() << " is removed from double stack "
         << endl;

    cout << string_stack.pop() << " is removed from string stack "
         << endl;

    cout << "Top element in integer stack is " << integer_stack.peek()
         << endl;

    cout << "Top element in double stack is " << double_stack.peek()
         << endl;

    cout << "Top element in string stack is " << string_stack.peek()
         << endl;

    integer_stack.print();
    return 0;
}
