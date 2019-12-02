#include "main.hpp"
int main(void)
{
	PhoneBook	Phonebook;
	std::string	tmp;
	std::cout << "|--- Welcome to your magic phone book ---|" << std::endl;
	Phonebook.Help();
	while (std::getline(std::cin, tmp))
	{
		if (std::strstr(tmp.c_str(), "ADD"))
			Phonebook.Add_Contact();
		else if (std::strstr(tmp.c_str(), "SEARCH"))
			Phonebook.Search_Contact();
		else if (std::strstr(tmp.c_str(), "EXIT"))
			Phonebook.Exit();
		else
			std::cout << "There's no such command" << std::endl;
	}
	std::cout << std::endl;
	system("leaks Piscine C++");
	return 0;
}