// 2.3 order of construction & destruction
#include <iostream>

class A
{
protected: // or public
	 int m_A;
public:
	A(int a): m_A(a)
	{
		//std::cout << "A()\n";
	}
	~A()
	{
		//std::cout << "~A()\n";
	}
};

class B: private A // here in private mode we derive the sub class B from a private base class A. 
				   // Then both public member and protected members of the base class will become private in derived class.
				   // so no matter class C derived B in which mode, 'm_A' is already private and inaccessible 
{
public:
	B(int a): A(a)
	{
		//std::cout << "B()\n";
	}
	~B()
	{
		//std::cout << "~B()\n";
	}
	void print()
	{
		printf("%d\n", m_A);
	}
};

class C: public B // or protected, private. 
{
public:
	C(int a): B(a) 
	{
		//std::cout << "C()\n";
	}
	~C()
	{
		//std::cout << "~C()\n";
	}

	// void print()
	// {
	// 	printf("%d\n", m_A);
	// }
};



int main() 
{
	B b(3);
	b.print();
	C c(2);
	// c.print();
}


