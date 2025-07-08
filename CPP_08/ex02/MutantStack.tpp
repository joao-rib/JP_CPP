#include "MutantStack.hpp"

//
//HELPER FUNCTIONS
//

//
//MEMBER FUNCTIONS
//

//
//GETTERS & SETTERS
//

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(void)
{
	return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end(void)
{
	return (this->c.end());
}

template<typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::begin(void) const
{
	return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::end(void) const
{
	return (this->c.end());
}

template<typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rbegin(void)
{
	return (this->c.rbegin());
}

template<typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rend(void)
{
	return (this->c.rend());
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::rbegin(void) const
{
	return (this->c.rbegin());
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::rend(void) const
{
	return (this->c.rend());
}

//
//CONSTRUCTORS & DESTRUCTORS
//

template<typename T>
MutantStack<T> &MutantStack<T>::operator = (const MutantStack &orig)
{
	if (this != &orig)
		std::stack<T>::operator=(orig);
	//std::cout << "MutantStack copy assignment constructed";
	return (*this);
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &orig): std::stack<T>(orig)
{
	//std::cout << "MutantStack copy constructed";
}

template<typename T>
MutantStack<T>::MutantStack(void)
{
	//std::cout << "MutantStack constructed";
}

template<typename T>
MutantStack<T>::~MutantStack(void)
{
	//std::cout << "MutantStack destructed";
}

//
//OVERLOAD OPERATIONS
//

/*template<typename T>
T&	MutantStack<T>::operator [] (long index)
{
	if (index >= this->size() || index < 0)
		throw OutOfBoundsException(*this, index);
	return (_values[index]);
}

template<typename T>
const T&	MutantStack<T>::operator [] (long index) const
{
	if (index >= this->size() || index < 0)
		throw OutOfBoundsException(*this, index);
	return (_values[index]);
}*/

//
//EXCEPTIONS
//

/*template<typename T>
MutantStack<T>::OutOfBoundsException::OutOfBoundsException(const MutantStack &arr, long pos)
{
	std::ostringstream out;
	out << "Position "<< pos << " lies outside of the bounds of an MutantStack of size " << arr.size();
	_msg = out.str();
}

template<typename T>
MutantStack<T>::OutOfBoundsException::~OutOfBoundsException() throw()
{
	//std::cout << "Error message destroyed" << std::endl;
}

template<typename T>
const char *MutantStack<T>::OutOfBoundsException::what() const throw()
{
	return (this->_msg.c_str());
}*/
