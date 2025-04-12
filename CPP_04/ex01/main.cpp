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
	animalArray[25]->makeSound();
	animalArray[48]->makeSound();
	std::cout.rdbuf(null_stream.rdbuf()); // Silence output
	for (int i = 0; i < 50; i++)
		delete animalArray[i];
	std::cout.rdbuf(orig_buf); // Restore output
	return 0;
}

/*int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	return 0;
}*/