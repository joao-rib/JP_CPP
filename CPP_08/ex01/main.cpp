#include "Span.hpp"

int main()
{
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		//sp.addNumber(-34);

		unsigned int len = 10000;
		Span multi = Span(len);
		multi.addManyRandomNumbers(len);
		//sp.addNumber(42);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		std::cout << multi.shortestSpan() << std::endl;
		std::cout << multi.longestSpan() << std::endl;

		std::cout << sp[2] << std::endl;
		std::cout << multi[2] << std::endl;
		//std::cout << sp[8] << std::endl;
		//std::cout << multi[10000] << std::endl;
		//std::cout << sp[-2] << std::endl;
		//std::cout << multi[-2] << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}

/*
$> ./ex01
2
14
$>
*/
