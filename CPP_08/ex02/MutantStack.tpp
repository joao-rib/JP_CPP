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

//
//EXCEPTIONS
//


