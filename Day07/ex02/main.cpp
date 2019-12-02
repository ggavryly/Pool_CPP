#include "Array.hpp"

class Pudel
{
public:
	Pudel() : i(new int[100]) {}
	~Pudel() { delete [] i; }

	int *i;
	Pudel(Pudel const & ref) {
		i = new int[100];
		for (int index = 0; index < 100; ++index) {
			i[index] = ref.i[index];
		}
	}
};

int main()
{
	Array<Pudel>a(24);
//	for (int i = 0; i < 24; ++i) {
//		a[i] = i;
//	}
	Array<Pudel> b = a;
	Array<double> c;
	Array<char> ch;

	b = a;
	try {

		a[25];
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	system("leaks 'Piscine'");
	return 0;
}