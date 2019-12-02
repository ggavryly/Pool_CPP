#include "Pony.hpp"

void ponyOnTheHeap(void)
{
	Pony *a = new Pony();
	a->scream();
	delete a;
}

void ponyOnTheStack(void)
{
	Pony a;
	a.scream();
}

int main(void)
{
	std::cout << "-----{Pony in the Heap}-----\n" << std::cout;
	ponyOnTheHeap();
	std::cout << "\n-----{Pony in the Stack}-----\n" << std::cout;
	ponyOnTheStack();
	return 0;
}