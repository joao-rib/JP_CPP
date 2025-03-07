#include "Point.hpp"

int main (void)
{
	Point a(0, 0);
	Point b(5, 0);
	Point c(2, 4);
	Point d(1, 4);
	if (bsp(a, b, c, d))
		std::cout << "Tá dentro do triângulo. Muito bem!" << std::endl;
	else
		std::cout << "Errou feio. Errou rude. Tá mal. Tá errado." << std::endl;
	return (0);
}

/*int main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed temp1(5.05f);
	Fixed temp2(2);
	Fixed const b = temp1 * temp2;
	Fixed const c = temp1 + temp2;
	Fixed const d = temp1 - temp2;
	Fixed const e = temp1 / temp2;

	std::cout << temp1 << std::endl;
	std::cout << temp2 << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << e << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	if (Fixed::max(a, b) == a)
		std::cout << "a is bigger" << std::endl;
	else if (b > a)
		std::cout << "b is bigger, it figures" << std::endl;
	else
		std::cout << "b is bigger" << std::endl;
	return 0;
}*/
