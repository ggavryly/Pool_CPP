# include <iostream>
# include <fstream>
int main(int ar, char **argv)
{
	if (ar == 1)
	{
		std::string tmp = "";
		while (std::getline(std::cin, tmp))
			std::cout << tmp << std::endl;
	}
	for (int i = 1; i < ar; i++)
	{
		std::ifstream input_file;
		std::string tmp = "";
		input_file.open(argv[i]);
		if (input_file.is_open())
		{
			while (std::getline(input_file, tmp))
				std::cout << tmp << "\n";
		}
		input_file.close();
	}
	return (0);
}