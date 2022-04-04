#include <iostream>

class Base 
{
//private:
protected:
	int m_x;
public:
	Base(int x): m_x(x)
	{
		std::cout << "Base()\n";
	}
	~Base()
	{
		std::cout << "~Base()\n";
	}

	void print() { std::cout << "Base: " << m_x << '\n'; }
};

class Derived: public Base
{
public:
	Derived(int y): Base(y)
	{
		std::cout << "Derived()\n";
	}
	~Derived()
	{
		std::cout << "~Derived()\n";
	}

	void print() { std::cout << "Derived: " << m_x << '\n';}
};

int main() 
{
	Derived d(5);
	d.print();
}