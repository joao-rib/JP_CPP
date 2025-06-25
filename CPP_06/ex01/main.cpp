#include "Serializer.hpp"

/*std::string capitalize(std::string str)
{
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (std::isalpha(str[i]))
			str[i] = std::toupper(str[i]);
	}
	return (str);
}*/

bool	is_numerical(std::string str)
{
	//if (str == "INF" || str == "-INF" || str == "INFF" || str == "-INFF" || str == "NAN" || str == "-NAN")
	//	return (true);
	int i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (false);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

int	main(int argc, char **argv)
{
try
{
	if (argc != 3)
		throw Serializer::OutsideScopeException("Please insert two arguments");
	else if (!is_numerical(argv[1]))
		throw Serializer::OutsideScopeException("First argument must be a number");

	Data* Data1 = new Data;
	Data1->serial_num = atoi(argv[1]);
	Data1->name = argv[2];

	std::cout << "Data:" << '\n' << "	Serial no.: " << Data1->serial_num << '\n' << "	Name: " << Data1->name << '\n' << std::endl;

	uintptr_t Address1 = Serializer::serialize(Data1);
	std::cout << "Data Address: " << Data1 << std::endl;
	std::cout << "uintptr Address: " << &Address1 << '\n' << std::endl;

	Data* Data2 = Serializer::deserialize(Address1);

	std::cout << "Data:" << '\n' << "	Serial no.: " << Data1->serial_num << '\n' << "	Name: " << Data1->name << '\n' << std::endl;
	std::cout << "Data, deserialized:" << '\n' << "	Serial no.: " << Data2->serial_num << '\n' << "	Name: " << Data2->name << '\n' << std::endl;

	std::cout << "Data Address: " << Data1 << std::endl;
	std::cout << "uintptr Address: " << &Address1 << std::endl;
	std::cout << "Deserialized Data Address: " << Data2 << std::endl;

	delete Data1;
}
catch(const std::exception& e)
{
	std::cerr << "Error: " << e.what() << std::endl;
}
	return 0;
}