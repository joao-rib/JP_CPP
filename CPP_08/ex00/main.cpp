#include "easyfind.hpp"

int	main(void)
{

	//VECTORS
	std::vector<int>			vec_values;
	//std::vector<std::string>	vec_names;

	try {
		::easyfind(vec_values, 42);
		std::cout << "No values yet" << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	vec_values.push_back(21);
	vec_values.push_back(10);
	vec_values.push_back(1989);
	/*vec_names.push_back("Day");
	vec_names.push_back("Month");
	vec_names.push_back("Year");*/

	try {
		//::easyfind(vec_names, 10);
		::easyfind(vec_values, 10);
		std::cout << "10 was found in vec_values, not in vec_names" << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	//LISTS
	std::list<int>				list_values;
	//std::list<std::string>	list_names;

	list_values.push_back(21);
	list_values.push_back(10);
	list_values.push_back(1989);
	/*list_names.push_back("Day");
	list_names.push_back("Month");
	list_names.push_back("Year");*/

	try {
		//::easyfind(list_names, 10);
		::easyfind(list_values, 10);
		std::cout << "10 was found in list_values, not in list_names" << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
