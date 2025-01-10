#pragma once

#include "Phonebook.hpp"
#include <iostream>
#include <locale>
#include <cstdlib>
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
	Contact() {};
	void create_contact(void);
	void write_value(std::string& field, const std::string& nametype);
	bool validate_number(std::string str);
};