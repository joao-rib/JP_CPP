#include "Point.hpp"

int main (void)
{
	Point a(5, 2);
	Point b(5, 8);
	Point c(11, 2);
	Point d(8, 2.01);
	if (bsp(a, b, c, d))
		std::cout << "Tá dentro do triângulo. Muito bem!" << std::endl;
	else
		std::cout << "Errou feio. Errou rude. Tá mal. Tá errado." << std::endl;
	return (0);
}
