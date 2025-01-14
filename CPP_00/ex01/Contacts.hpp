#pragma once

#include "Phonebook.hpp"
#include <iostream>
#include <locale>
#include <iomanip>
#include <cstdlib>

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
	void write_value(std::string& variable, const std::string& field);
	bool validate_number(std::string str);
	std::string get_info(const std::string& field);
};