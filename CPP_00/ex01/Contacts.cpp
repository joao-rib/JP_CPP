#include "Phonebook.hpp"
#include "Contacts.hpp"

void Contact::create_contact(void)
{
	std::cout << "Adding new contact. Please fill in the required data:\n\n";
	std::cout << "First Name:\n";
	write_value(firstname, "first name");
	std::cout << "Last Name:\n";
	write_value(lastname, "last name");
	std::cout << "Nickname:\n";
	write_value(nickname, "preferred nickname");
	std::cout << "Phone Number:\n";
	write_value(phonenumber, "phone number");
	std::cout << "Darkest Secret:\n";
	write_value(darkestsecret, "darkest of secrets");
	std::cout << "\nContact successfully added!" << std::endl;
}

void Contact::write_value(std::string& variable, const std::string& field)
{
	std::string value;
	while(1)
	{
		std::getline(std::cin, value);
		if (value.length() == 0)
			std::cout << "You haven't entered your " << field << " yet! >:(\nTry again:\n";
		else if (field == "phone number" && !validate_number(value))
			std::cout << "Your phone number really needs to be a number :/ Or else the book melts.\nTry again:\n";
		else
		{
			variable = value;
			break;
		}
	}
}

bool Contact::validate_number(std::string str)
{
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}

/*void Contact::set_first(std::string input)
{
    firstname = input;
}
void Contact::set_last(std::string input)
{
    lastname = input;
}
void Contact::set_nick(std::string input)
{
    nickname = input;
}
void Contact::set_phone(std::string input)
{
    phonenumber = input;
}
void Contact::set_daskest(std::string input)
{
    darkestsecret = input;
}
std::string Contact::get_firstname(void) const
{
	return firstname;
}
std::string Contact::get_lastname(void) const
{
    return lastname;
}
std::string Contact::get_nickname(void) const
{
    return nickname;
}
std::string Contact::get_phonenumber(void) const
{
    return phonenumber;
}
std::string Contact::get_darkest(void) const
{
    return darkestsecret;
}

void Contact::set_firstname(void)
{
	std::string name;
	while(1)
	{
		std::getline(std::cin, name);
		if (name.length() == 0)
		{
			std::cout << "Please enter a valid Firstname\n";
			continue;
		}
		else
		{
			set_first(name);
			break;
		}
	}
}
void Contact::set_lastname(void)
{
	std::string name;
	while(1)
	{
		std::getline(std::cin, name);
		if (name.length() == 0)
		{
			std::cout << "Please enter a valid Lastname\n";
			continue;
		}
		else
		{
			set_last(name);
			break;
		}
	}
}
void Contact::set_nickname(void)
{
	std::string name;
	while(1)
	{
		std::getline(std::cin, name);
		if (name.length() == 0)
		{
			std::cout << "Please enter a valid Nickname\n";
			continue;
		}
		else
		{
			set_nick(name);
			break;
		}
	}
}

int Contact::check_number(std::string input)
{
	for(size_t i = 0; i < input.length(); i++)
	{
		if (!isdigit(input[i]))
			return 1;
	}
	return (0);
}
void Contact::set_phonenumber(void)
{
	std::string number;
	while(1)
	{
		std::getline(std::cin, number);
		if (check_number(number) || number.length() == 0)
			std::cout << "Please enter a valid number.\n";
		else
		{
			set_phone(number);
			break;
		}
	}
}
void Contact::set_darkestsecret(void)
{
		std::string name;
	while(1)
	{
		std::getline(std::cin, name);
		if (name.length() == 0)
		{
			std::cout << "Please enter a valid Nickname\n";
			continue;
		}
		else
		{
			set_daskest(name);
			break;
		}
	}
}

void Contact::contacts(void)
{
	std::cout << "- Type the info of the contact please\n";
	std::cout << "- First Name: \n";
	set_firstname();
	std::cout << "- Last Name:\n";
	set_lastname();
	std::cout << "- Nickname:\n";
	set_nickname();
	std::cout << "- Phone Number:\n";
	set_phonenumber();
	std::cout << "- Darkest Secret: \n";
	set_darkestsecret();
	std::cout << "- Done adding everything, Well done ( ˶˘ ³˘(˵ ͡° ͜ʖ ͡°˵)♡ \n";
}

int PhoneBook::display_contacts(int index)
{
	Contact& contact = get_contact(index);
	std::cout << "First Name:     " << contact.get_firstname() << "\n";
	std::cout << "Last Name:      " << contact.get_lastname() << "\n";
	std::cout << "Nick Name:      " << contact.get_nickname() << "\n";
	std::cout << "Phone Number:   " << contact.get_phonenumber() << "\n";
	std::cout << "Darkest secret: " << contact.get_darkest() << "\n";
	return 1;
}*/