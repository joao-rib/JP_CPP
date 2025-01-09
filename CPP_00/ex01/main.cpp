#include <iostream>
#include <locale>
#include "Phonebook.hpp"
#include "Contacts.hpp"

std::string capitalize(std::string str)
{
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (std::isalpha(str[i]))
			str[i] = std::toupper(str[i]);
	}
	return (str);
}

void print_prompt(void)
{
	std::cout << "1 - Enter \"ADD\" in order to add a new contact;\n";
	std::cout << "2 - Enter \"SEARCH\" in order to display one of your contacts;\n";
	std::cout << "3 - Enter \"EXIT\" in order to exit this phonebook. Forever." << std::endl;
}

int	main(void)
{
	system("clear");
	std::cout << "Thank you for opening a new phonebook! :D They're rare these days\n\n";
	print_prompt();
	std::string input;
	Contact contact;
	PhoneBook phonebook; //WIP create PhoneBook class
	while (std::getline(std::cin, input))
	{
		capitalize(input);
		if (input == "EXIT")
		{
			std::cout << "Thank you for using our services :) Bye!" << std::endl;
			return (0);
		}
		else if (input == "ADD")
		{
			system("clear");
			contact.create_contact();
			phonebook.add_contact(); // WIP Let's add
		}
		else if (input == "SEARCH")
		{
			system("clear");
			; // WIP Let's search
		}
		else
			std::cout << "Command not found ¯\\_(ツ)_/¯ Try something else\n" << std::endl;
		print_prompt();
	}
	return (0);
}
