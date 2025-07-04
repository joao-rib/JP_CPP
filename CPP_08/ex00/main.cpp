#include "easyfind.hpp"

int	main(void)
{

	//VECTORS
	std::vector<int>			vec_values;
	//std::vector<std::string>	vec_names;
	std::vector<float>			vec_float;

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
	vec_float.push_back(21.10);
	vec_float.push_back(10.00);
	vec_float.push_back(1989.85);

	try {
		::easyfind(vec_values, 10);
		//::easyfind(vec_names, 10);
		::easyfind(vec_float, 10);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "10 was found in vec_values, not in vec_names or vec_float." << std::endl;

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
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "10 was found in list_values, not in list_names." << std::endl;

	return 0;
}
