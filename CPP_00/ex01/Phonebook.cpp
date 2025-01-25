#include "Phonebook.hpp"
#include "Contacts.hpp"

void PhoneBook::add_contact(Contact new_contact)
{
	if (num_contacts < 8)
	{
		contacts[num_contacts] = new_contact;
		num_contacts++;
	}
	else
	{
		full = true;
		contacts[0] = new_contact;
		num_contacts = 1;
	}
	std::cout << "Contact was successfully added to slot number " << itoa(num_contacts) << "!\n" << std::endl;
}

std::string PhoneBook::itoa(int n)
{
	size_t	count;
	long	c;

	count = 2;
	c = (long)n;
	if (n < 0)
	{
		c *= -1;
		count++;
	}
	while (c >= 10)
	{
		c /= 10;
		count++;
	}
	char	final_num[count];
	c = (long)n;
	count--;
	final_num[count] = '\0';
	count--;
	if (n < 0)
	{
		c *= -1;
		final_num[0] = '-';
	}
	if (n == 0)
		final_num[0] = '0';
	while (c > 0)
	{
		final_num[count] = (c % 10) + '0';
		c /= 10;
		count--;
	}
	return (std::string(final_num));
}

void PhoneBook::display_contacts(void)
{
	int	tab_height;

	if (num_contacts == 0)
	{
		std::cout << "The phonebook is still empty :o Try adding a contact!\n" << std::endl;
		return ;
	}
	if (full)
		tab_height = 8;
	else
		tab_height = num_contacts;
	std::cout << "Your contact list:\n";
	std::cout << "|" << std::setw(10) << "Index";
	std::cout << "|" << std::setw(10) << "First Name";
	std::cout << "|" << std::setw(10) << "Last Name";
	std::cout << "|" << std::setw(10) << "Nickname" << "|\n";
	for (int i = 0; i < tab_height; ++i)
	{
		std::cout << "|";
		std::cout << std::right << std::setw(10) << (i + 1);
		std::cout << "|";
		std::cout << std::right << std::setw(10) << shorter_string(contacts[i].get_info("First Name"), 10);
		std::cout << "|";
		std::cout << std::right << std::setw(10) << shorter_string(contacts[i].get_info("Last Name"), 10);
		std::cout << "|";
		std::cout << std::right << std::setw(10) << shorter_string(contacts[i].get_info("Nickname"), 10);
		std::cout << "|\n";
	}
	std::cout << std::endl;
	std::cout << "Enter:\n -An index number in order to see a contact's full info; or\n -BACK, to return to the previous menu" << std::endl;
	std::string input;
	while (std::getline(std::cin, input))
	{
		input = capitalize(input);
		if (input == "BACK")
			return ;
		else if (!contacts->validate_number(input))
		{
			std::cout << "That is not a valid input >:( Try again" << std::endl;
			continue ;
		}
		int index = atoi(input.c_str());
		if (index > 8 || index <= 0)
			std::cout << "That is not a valid index number, and you know it >:( Try again" << std::endl;
		else if (index > tab_height)
			std::cout << "I'm sorry, that contact has not been added yet :/ Try a different number" << std::endl;
		else
		{
			display_info(index - 1);
			break ;
		}
	}
	display_contacts();
}

void PhoneBook::display_info(int index)
{
	std::cout << "First Name:      ";
	std::cout << std::right  << std::setw(20) << contacts[index].get_info("First Name") << std::endl;
	std::cout << "Last Name:       ";
	std::cout << std::right << std::setw(20) << contacts[index].get_info("Last Name") << std::endl;
	std::cout << "Nickname:        ";
	std::cout << std::right << std::setw(20) << contacts[index].get_info("Nickname") << std::endl;
	std::cout << "Phone Number:    ";
	std::cout << std::right << std::setw(20) << contacts[index].get_info("Phone Number") << std::endl;
	std::cout << "Darkest Secret:  ";
	std::cout << std::right << std::setw(20) << contacts[index].get_info("Darkest Secret") << std::endl;
	std::cout << "\n";
}

std::string PhoneBook::capitalize(std::string str)
{
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (std::isalpha(str[i]))
			str[i] = std::toupper(str[i]);
	}
	return (str);
}

std::string PhoneBook::shorter_string(const std::string& str, int limit)
{
	if (str.length() <= (size_t)limit)
		return (str);
	else
		return (str.substr(0, limit - 2) + ".");
}
