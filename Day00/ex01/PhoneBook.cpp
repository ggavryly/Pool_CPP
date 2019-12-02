#include "PhoneBook.hpp"
std::string PhoneBook::field_names[11] = {
		"First name",
		"Last name",
		"Nickname",
		"Login",
		"Postal Address",
		"Email Address",
		"Phone Number",
		"Birthday Date",
		"Favorite Meal",
		"Underwear Color",
		"Darkest Secret"
};
size_t PhoneBook::contact_num = 0;

void PhoneBook::Add_Contact()
{
	std::cout << "Creating new contact..." << std::endl;
	Contact c;
	if (PhoneBook::contact_num < 8)
	{
		for (size_t i = 0; i < 11; i++)
		{
			std::string tmp;
			std::cout << i + 1 << "." << "Please enter your " << PhoneBook::field_names[i] << std::endl;
			while (std::getline(std::cin, tmp))
			{
				if (!tmp.empty())
					break;
				else
				{
					std::cout << "Field cannot be empty" << std::endl;
					std::cout << "Please enter your " << PhoneBook::field_names[i] << std::endl;
				}
			}
			c.fields[i] = tmp;
			c.contact_index = PhoneBook::contact_num;
			PhoneBook::contact_list[c.contact_index % 8] = c;
		}
		PhoneBook::contact_num++;
		std::cout << "The contact has been successfully created" << std::endl;
	}
	else
		std::cout << "Error: Phone Book full" << std::endl;
	PhoneBook::Help();
}

void PhoneBook::Print_Contact(size_t index, size_t rows)
{
	for (size_t j = 0; j < rows; j++)
	{
		if (PhoneBook::contact_list[index].fields[j].size() > 10)
			std::cout << "  " << PhoneBook::contact_list[index].fields[j].substr(0, 9) << ".";
		else
		{
			std::cout << std::setw(12);
			std::cout << PhoneBook::contact_list[index].fields[j];
		}
		std::cout << "|";
	}
	std::cout << std::endl;
}

void PhoneBook::Help()
{
	std::cout << "Please type your command:\n"
			  "1.ADD(add new contact to phone book)\n"
	 		  "2.SEARCH(print all persons in phone book then you type index of the contact you are interested in)\n"
	  		  "3.EXIT(quits the program)" << std::endl;
}

void PhoneBook::Search_Contact()
{
	std::string	tmp;
	if (PhoneBook::contact_num != 0)
	{
		std::cout << "Your's Phone Book" << std::endl;
		std::cout << "------------------------------------------------" << std::endl;
		std::cout << "| Index | First Name | Last  Name |  Nickname  |" << std::endl;
		for (size_t i = 0; i < PhoneBook::contact_num; i++)
		{
			std::cout << "|   " << i  << "   |";
			PhoneBook::Print_Contact(i, 3);
		}
		std::cout << "------------------------------------------------" << std::endl;
		std::cout << std::endl;
		std::cout << "Please enter the index of the contact you are interested in" << std::endl;
		std::getline(std::cin, tmp);
		if (std::isdigit(tmp[0]))
		{
			if (std::stoi(tmp) >= 0 && std::stoi(tmp) <= 8)
			{
				size_t index = std::stoi(tmp);
				std::cout << "----------------------------------"
						  << std::endl;
				for (size_t i = 0; i < 11; i++)
					std::cout << "|" << PhoneBook::field_names[i] << ": "<< PhoneBook::contact_list[index].fields[i] << " " << std::endl;
				std::cout << "----------------------------------" << std::endl;
			}
			else
				std::cout << "Please enter index correct index from 0 to 8" << std::endl;
		}
		else
		{
			std::cout << "Error: Wrong Index " << std::endl;
		}
	}
	else
		std::cout << "Please add at least one contact befor use SEARCH command" << std::endl;
}

void PhoneBook::Exit()
{
	std::string tmp;
	std::cout << "Are you sure you want to quit the program? (yes/no)" << std::endl;
	std::getline(std::cin, tmp);
	if (tmp[0] == '1' || tmp[0] == 'y' || tmp[0] == 'Y')
		exit(0);
}