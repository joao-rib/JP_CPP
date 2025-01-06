#pragma once

#include "Phonebook.hpp"
# include <iostream>
# include <string>
# include <cstring>
# include <cstdlib>
# include <limits>
# include <cctype>
# include <iomanip>

// by default classes start private
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
	std::string get_firstname(void) const;
    std::string get_lastname(void) const;
    std::string get_nickname(void) const;
    std::string get_phonenumber(void) const;
    std::string get_darkest(void) const;
    void set_first(std::string input);
    void set_last(std::string input);
    void set_nick(std::string input);
    void set_phone(std::string input);
    void set_daskest(std::string input);
    void contacts(void);
    void set_firstname(void);
    void set_lastname(void);
    void set_nickname(void);
    int check_number(std::string input);
    void set_phonenumber(void);
    void set_darkestsecret(void);
};