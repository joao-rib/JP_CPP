#pragma once

#include "Contacts.hpp"
#include <iostream>
#include <locale>
#include <cstdlib>
/*# include <string>
# include <cstring>
# include <cstdlib>
# include <limits>
# include <cctype>
# include <iomanip>
#include <cstdlib>*/

class PhoneBook
{
private:
	Contact contacts[8];
	int num_contacts;
	bool full = false;
public:
	PhoneBook() : num_contacts(0) {};
	void add_contact(Contact new_contact);
    std::string itoa(int num);
	void display_contacts(void);
};