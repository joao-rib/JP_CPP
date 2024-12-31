#include "Phonebook.hpp"
#include "Contacts.hpp"

int PhoneBook::is_digit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}

int	PhoneBook::not_a_digit(std::string input)
{
	for(int i = 0; input[i]; i++)
	{
		if (!is_digit(input[i]))
			return 0;
	}
	return 1;
}

int	PhoneBook::stoi(std::string input)
{
	int	i;
	int	num;
	i = 0;
	num = 0;
	while ((input[i] >= 9 && input[i] <= 13) || (input[i] == 32))
		i++;
	while (isdigit(input[i]))
	{
		num = num * 10 + input[i] - 48;
		i++;
	}
	return (num);
}

Contact& PhoneBook::get_contact(int index)
{
    return contacts[index];
}

void PhoneBook::add_contact(Contact new_contact)
{
    if (n_contacts < 8)
    {
    	contacts[n_contacts] = new_contact;
        if (n_contacts < 8)
            n_contacts++;
        else
            std::cout << "PhoneBook is full. Replacing the last contact.\n";
    }
    else
    {
		int oldIndex = 0;
        contacts[oldIndex] = new_contact;
		oldIndex++;
        std::cout << "Contact added successfully by replacing the last one!\n";
    }
}

int PhoneBook::get_ncontacts() const
{
    return n_contacts;
}

void PhoneBook::utils(void)
{
	std::cout << "Not a valid index. \n";
	std::cout << "( ͡ಥ ͜ʖ ͡ಥ)\n";
	std::cout << "Please try a number between 0 and " << get_ncontacts() - 1 << "\n";
}

int PhoneBook::newheader(void)
{
	std::string line;
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "If you want to go back to Main \n";
	std::cout << "Please type 'BACK' or 'back' \n";
	std::cout << "Or please press any key to go back to the seletion option\n";
	std::getline(std::cin, line);
	// if (std::cin.eof())
	// 	exit(0);
	if (line == "BACK" || line == "back")
		return 1;
	return 0;
}
void PhoneBook::phonebook_header(void)
{
	while (1)
	{
		int index;
		std::string line;
		std::cout << "\n";
		std::cout << "-Please choose an index to see the full info ＼(｀0´)／\n";
		std::getline(std::cin, line);
		index = stoi(line);
		if(!not_a_digit(line) || line.length() == 0)
		{
			utils();
			continue;
		}
		if (index > get_ncontacts() - 1)
		{
			utils();
			continue;
		}
		if (index >= 0 && index <= get_ncontacts())
		{
			if (display_contacts(index))
				if (newheader())
					break ;
		}
	}
}

std::string truncate_string(const std::string& str, size_t width)
{
	if (str.length() <= width)
		return str;
	else
		return str.substr(0, width - 2) + ".";
}

void PhoneBook::show_phonebook(void)
{
	int n_contacts = get_ncontacts();
	if (n_contacts == 0)
	{
		std::cout << "\n";
		std::cout << "		You have no contacts at the moment (⋟﹏⋞) \n";
		std::cout << "\n";
		std::cout << "\n";
		return;
	}
	std::cout << "Your contacts:\n";
	std::cout << "|";
	std::cout << std::setw(10) << "Index";
	std::cout << "|";
	std::cout << std::setw(10) << "First Name";
	std::cout << "|";
	std::cout << std::setw(10) << "Last Name";
	std::cout << "|";
	std::cout << std::setw(10) << "Nickname";
	std::cout << "|\n";
	for (int i = 0; i < n_contacts; ++i)
	{
		Contact& contact = get_contact(i);
		std::cout << "|";
		std::cout << std::right << std::setw(10) << i;
		std::cout << "|";
		std::cout << std::right << std::setw(10) << truncate_string(contact.get_firstname(), 10);
		std::cout << "|";
		std::cout << std::right << std::setw(10) << truncate_string(contact.get_lastname(), 10);
		std::cout << "|";
		std::cout << std::right << std::setw(10) << truncate_string(contact.get_nickname(), 10);
		std::cout << "|\n";
	}
	phonebook_header();
}