#include "Serializer.hpp"

//HELPER FUNCTIONS

//MEMBER FUNCTIONS

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

//GETTERS & SETTERS

//CONSTRUCTORS & DESTRUCTORS

Serializer &Serializer::operator = (const Serializer &orig)
{
	(void)orig;
	//std::cout << "Some Serializer was copy-referred." << std::endl;
	return (*this);
}

Serializer::Serializer(const Serializer &orig)
{
	(void)orig;
	//std::cout << "Some Serializer was referred." << std::endl;
}

Serializer::Serializer(void)
{
	//std::cout << "Some Serializer was hired." << std::endl;
}

Serializer::~Serializer(void)
{
	//std::cout << "Some Serializer was fired" << std::endl;
}

//OVERLOAD OPERATIONS

//EXCEPTIONS

Serializer::OutsideScopeException::OutsideScopeException(const std::string &reason)
{
	std::ostringstream out;
	out << reason;
	_msg = out.str();
}

Serializer::OutsideScopeException::~OutsideScopeException() throw()
{
	//std::cout << "Error message destroyed" << std::endl;
}

const char *Serializer::OutsideScopeException::what() const throw()
{
	return (this->_msg.c_str());
}