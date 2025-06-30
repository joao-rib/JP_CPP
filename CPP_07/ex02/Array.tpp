#include "Array.hpp"

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
unsigned int	Array<T>::size(void) const
{
	return (this->_size);
}

//
//CONSTRUCTORS & DESTRUCTORS
//

template<typename T>
Array<T> &Array<T>::operator = (const Array &orig)
{
	if (this != &orig)
	{
		_size = orig.size();
		//if (this->_values)
		delete[] _values;
		_values = new T[this->size()];
		for (unsigned int i = 0 ; i < this->size() ; i++)
			_values[i] = orig._values[i];
	}
	//std::cout << this << " was copy assigned." << std::endl;
	return (*this);
}

template<typename T>
Array<T>::Array(const Array &orig): _values(NULL), _size(orig._size)
{
	_size = orig.size();
	//if (this->_values)
	delete[] _values;
	_values = new T[orig.size()];
	for (unsigned int i = 0 ; i < this->size() ; i++)
		_values[i] = orig._values[i];
	//std::cout << "Array of size " << this->size() << " was copy constructed." << std::endl;
}

template<typename T>
Array<T>::Array(unsigned int n): _size(n)
{
	_values = new T[this->size()];
	//std::cout << "Array of size " << this->size() << ", starting with " << *this->_values << ", was created" << std::endl;
}

template<typename T>
Array<T>::Array(void): _values(NULL), _size(0)
{
	//std::cout << "Empty array of nothing is created." << std::endl;
}

template<typename T>
Array<T>::~Array(void)
{
	//std::cout << "Array starting with " << *this->_values << " will be destroyed...";
	delete[] _values;
	//std::cout << "...done. All " << this->size() << " elements were destroyed" << std::endl;
}

//
//OVERLOAD OPERATIONS
//

template<typename T>
T&	Array<T>::operator [] (long index)
{
	if (index >= this->size() || index < 0)
		throw OutOfBoundsException(*this, index);
	return (_values[index]);
}

/*// T& operator[]( unsigned int index );
template <typename T>
T& Array<T>::operator[]( unsigned int index )
{
  if ( index >= _arraySize )
    throw Array::OutOfBoundsException();
  return _elements[index];
}


// const T& operator[]( unsigned int index ) const;
template <typename T>
const T& Array<T>::operator[]( unsigned int index ) const
{
  if ( index >= _arraySize )
    throw Array::OutOfBoundsException();
  return _elements[index];
}*/

//
//EXCEPTIONS
//

template<typename T>
Array<T>::OutOfBoundsException::OutOfBoundsException(const Array &arr, long pos)
{
	std::ostringstream out;
	out << "Position "<< pos << " lies outside of the bounds of an array of size " << arr.size();
	_msg = out.str();
}

template<typename T>
Array<T>::OutOfBoundsException::~OutOfBoundsException() throw()
{
	//std::cout << "Error message destroyed" << std::endl;
}

template<typename T>
const char *Array<T>::OutOfBoundsException::what() const throw()
{
	return (this->_msg.c_str());
}