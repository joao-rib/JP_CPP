#pragma once

#include "Contacts.hpp"
#include <iostream>
#include <locale>
#include <iomanip>
#include <cstdlib>

class PhoneBook
{
private:
	Contact contacts[8];
	int num_contacts;
	bool full;
public:
	PhoneBook() : num_contacts(0), full(false) {};
	void add_contact(Contact new_contact);
    std::string itoa(int num);
	void display_contacts(void);
	void display_info(int index);
	std::string capitalize(std::string str);
	std::string shorter_string(const std::string& str, int limit);
};