#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

//HELPER FUNCTIONS

Base*	generate(void)
{
	std::srand(std::time(0));
	switch (std::rand() % 3)
	{
		case 0:
			std::cout << "Created as class A." << std::endl;
			return (new A);
		case 1:
			std::cout << "Created as class B." << std::endl;
			return (new B);
		case 2:
			std::cout << "Created as class C." << std::endl;
			return (new C);
		default:
			return NULL;
	}
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "This is indeed the A class." << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "This is indeed the B class." << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "This is indeed the C class." << std::endl;
	else
		std::cout << "This is... I don't know what this is." << std::endl;
}

void	identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "This is indeed the A class." << std::endl;
		return ;
	}
	catch(const std::exception& e)	{}
	
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "This is indeed the B class." << std::endl;
		return ;
	}
	catch(const std::exception& e)	{}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "This is indeed the C class." << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		std::cout << "This is... I don't know what this is." << std::endl;
	}
}

//MEMBER FUNCTIONS

//GETTERS & SETTERS

//CONSTRUCTORS & DESTRUCTORS

Base::~Base(void)
{
	//std::cout << this << " was shredded" << std::endl;
}

// OVERLOAD OPERATIONS

// EXCEPTIONS

