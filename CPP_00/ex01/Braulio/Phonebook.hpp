#pragma once

#include "Contacts.hpp"
# include <iostream>
# include <string>
# include <cstring>
# include <cstdlib>
# include <limits>
# include <cctype>
# include <iomanip>
#include <cstdlib>

class PhoneBook
{
private:
	Contact contacts[8];
	int n_contacts;
public:
	PhoneBook() : n_contacts(0) {};
    int get_ncontacts() const;
    void add_contact(Contact new_contact);
    Contact& get_contact(int index);
    void show_phonebook(void);
    void phonebook_header(void);
    int display_contacts(int index);
    int is_digit(int c);
    int	stoi(std::string input);
    int	not_a_digit(std::string input);
    void utils(void);
    int newheader(void);
};