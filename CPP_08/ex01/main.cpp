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

		/*srand(time(NULL));
		unsigned int len = 100000;
		Span sp = Span(len);
		for (unsigned int i = 0; i < len; i++) {
			sp.addNumber(rand());
		}*/
		//sp.addNumber(rand());

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
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
