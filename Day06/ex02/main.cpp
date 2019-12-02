#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
Base	*generate(void)
{
	Base *result = nullptr;
	static int a = 0;
	srand(time(nullptr));
	if (((rand() + a) % 2) == 0)
	{
		A *p = new A;
		result = dynamic_cast<Base *>(p);
	}
	else if (((rand() + a) % 5) == 0)
	{
		B *p = new B;
		result = dynamic_cast<Base *>(p);
	}
	else
	{
		C *p = new C;
		result = dynamic_cast<Base *>(p);
	}
	a++;
	return result;
}

void identify_from_pointer(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "This A class pointer" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "This B class pointer" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "This C class pointer" << std::endl;
}

void identify_from_reference(Base &p)
{
	if (&dynamic_cast<A &>(p))
		std::cout << "This A class pointer" << std::endl;
	else if (&dynamic_cast<B &>(p))
		std::cout << "This B class pointer" << std::endl;
	else if (&dynamic_cast<C &>(p))
		std::cout << "This C class pointer" << std::endl;
}

int main(void)
{
	Base *p = generate();
	Base &b = *generate();
	identify_from_pointer(p);
	identify_from_reference(b);
}