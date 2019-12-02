#include <iostream>
#include <string>
template <typename T>
void	iter(T *array, size_t len, void (*f)(T const &))
{
	for (size_t i = 0; i < len; i++)
		f(array[i]);
}
template <typename T>
void makaka_add(T const &a)
{
	std::cout << "Makaka: " << a << std::endl;
}

int main()
{
	int		a[10] = {0,1,2,3,4,5,6,7,8,9};
	float	b[5] = {0.1f, 0.2f, 0.3f, 0.4f, 0.5f};

	iter<int>(a, 10, makaka_add);
	iter<float>(b, 5, makaka_add);
}
