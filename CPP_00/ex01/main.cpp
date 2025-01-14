#include "Phonebook.hpp"
#include "Contacts.hpp"

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
	PhoneBook phonebook;
	while (std::getline(std::cin, input))
	{
		input = phonebook.capitalize(input);
		if (input == "EXIT")
		{
			std::cout << "Thank you for using our services :) Your contacts are now lost forever. Bye!" << std::endl;
			return (0);
		}
		else if (input == "ADD")
		{
			system("clear");
			contact.create_contact();
			phonebook.add_contact(contact);
		}
		else if (input == "SEARCH")
		{
			system("clear");
			phonebook.display_contacts();
		}
		else
			std::cout << "Command not found ¯\\_(ツ)_/¯ Try something else\n" << std::endl;
		print_prompt();
	}
	return (0);
}
