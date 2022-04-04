// 2.3 order of construction & destruction
#include <iostream>

class A
{
public:
	A()
	{
		std::cout << "A()\n";
	}
	~A()
	{
		std::cout << "~A()\n";
	}
};

class B
{
public:
	B()
	{
		std::cout << "B()\n";
	}
	~B()
	{
		std::cout << "~B()\n";
	}
};

class C
{
public:
	C()
	{
		std::cout << "C()\n";
	}
	~C()
	{
		std::cout << "~C()\n";
	}
};

class ABC: public A, public C, public B
{
public:
	ABC()
	{
		std::cout << "ABC()\n";
	}
	~ABC()
	{
		std::cout << "~ABC()\n";
	}
};

int main() 
{
	ABC acb;
}

/* 
$ g++ -o dummy dummyABC.cpp 
$ ./dummy 
A()
C()
B()
ABC()
~ABC()
~B()
~C()
~A()
*/