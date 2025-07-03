#include "easyfind.hpp"

//
//HELPER FUNCTIONS
//

//
//MEMBER FUNCTIONS
//

template<typename T>
typename T::iterator	easyfind(T& int_container, int num)
{
	if (int_container.empty())
		throw ::NoOccurrenceException(" cannot be found in an empty container.", num);

	if (typeid(*int_container.begin()) != typeid(int))
		throw ::NoOccurrenceException(" cannot be found in a non-int container.", num);

	typename T::iterator result = std::find(int_container.begin(), int_container.end(), num);

	if (int_container.end() == result)
		throw ::NoOccurrenceException(" was not found in this container.", num);
	
	return (result);
}

//
//GETTERS & SETTERS
//

//
//CONSTRUCTORS & DESTRUCTORS
//

//
//OVERLOAD OPERATIONS
//

//
//EXCEPTIONS
//

NoOccurrenceException::NoOccurrenceException(const std::string reason, int num)
{
	std::ostringstream out;
	out << "Value " << num << reason;
	_msg = out.str();
}

NoOccurrenceException::~NoOccurrenceException() throw()
{
	//std::cout << "Error message destroyed" << std::endl;
}

const char *NoOccurrenceException::what() const throw()
{
	return (this->_msg.c_str());
}