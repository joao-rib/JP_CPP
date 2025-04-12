#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

#include <fstream>
#include <streambuf>

int main()
{

	std::streambuf* orig_buf = std::cout.rdbuf();
	std::ofstream null_stream;
	null_stream.open("/dev/null");
	std::cout.rdbuf(null_stream.rdbuf()); // Silence output

	const Animal* animalArray[50];

	for (int i = 0; i < 50; i++)
	{
		if (i % 2 == 0)
			animalArray[i] = new Cat();
		else
			animalArray[i] = new Dog();
	}
	std::cout.rdbuf(orig_buf); // Restore output

	int	a1 = 25;
	int	a2 = 48;
	int i1 = 22;
	int i2 = 87;
	if (a1 >= 0 && a1 < 50)
	{
		animalArray[a1]->makeSound();
		std::cout << animalArray[a1]->getType() << " came up with " << animalArray[a1]->findIdea(i1) << std::endl;
	}
	if (a2 >= 0 && a2 < 50)
	{
		animalArray[a2]->makeSound();
		std::cout << animalArray[a2]->getType() << " came up with " << animalArray[a2]->findIdea(i2) << std::endl;
	}

	std::cout.rdbuf(null_stream.rdbuf()); // Silence output
	for (int i = 0; i < 50; i++)
		delete animalArray[i];
	std::cout.rdbuf(orig_buf); // Restore output
	return 0;
}

/*	Cat	*tareco = new Cat();
	Dog *bobi = new Dog();
	std::cout << "tareco came up with " << tareco->findIdea(0) << std::endl;
	std::cout << "bobi came up with " << bobi->findIdea(100) << std::endl;
	delete tareco;
	delete bobi;*/

/*int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	return 0;
}*/