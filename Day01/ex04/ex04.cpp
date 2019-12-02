#include <iostream>

int main(void)
{
	std::string *a = new std::string("HI THIS IS BRAIN");
	std::string &b = *a;
	std::cout << *a << " {Pointer}" << std::endl;
	std::cout << b << " {Reference}" << std::endl;
	delete a;
}