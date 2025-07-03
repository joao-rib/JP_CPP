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
/*  typename T::iterator searchResult;
  searchResult = std::find( container.begin(), container.end(), value );

  if ( searchResult == container.end() )
    throw ::NotFoundException();

  return searchResult;*/

	/*typename T::iterator result = NULL;
	int cont_size = int_container.size();

	for (int i = 0; i < cont_size; i++) {
		if (int_container[i] == num)
			return (int_container[i]);
	}
	
	throw NoOccurrenceException(" was not found in this container.", num);*/

	typename T::iterator result = std::find(int_container.begin(), int_container.end(), num); //WIP analyse find, begin, end, size

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