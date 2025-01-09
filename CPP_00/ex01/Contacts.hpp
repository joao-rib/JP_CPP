#pragma once

#include "Phonebook.hpp"
#include <iostream>
#include <locale>
/*# include <string>
# include <cstring>
# include <cstdlib>
# include <limits>
# include <cctype>
# include <iomanip>*/

class Contact 
{
private:
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string phonenumber;
	std::string darkestsecret;
public:
	Contact();
	void Contact::create_contact(void);
	void Contact::write_value(std::string& field, const std::string& nametype);
	bool Contact::validate_number(std::string str);
};