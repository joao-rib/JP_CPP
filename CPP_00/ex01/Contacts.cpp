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
