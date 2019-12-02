#ifndef PHONE_BOOK
# define PHONE_BOOK
#include "Contact.hpp"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <iomanip>

struct PhoneBook
{
	Contact				contact_list[8];
	static std::string	field_names[11];
	static size_t		contact_num;
	void Add_Contact();
	void Print_Contact(size_t index, size_t rows);
	void Search_Contact();
	void Help();
	void Exit();
};

#endif