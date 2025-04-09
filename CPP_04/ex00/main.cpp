#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main()
{
	const Animal* Costa = new Animal();
	const Animal* Bobi = new Dog();
	const Animal* Tareco = new Cat();
	std::cout << "Bobi: " << Bobi->getType() << std::endl;
	std::cout << "Tareco: "<< Tareco->getType() << std::endl;
	Bobi->makeSound();
	Tareco->makeSound();
	Costa->makeSound();
	delete Costa;
	//delete Bobi;
	delete Tareco;

	const WrongAnimal* Emplastro = new WrongAnimal();
	const WrongAnimal* Grump = new WrongCat();
	std::cout << "Bobi: " << Bobi->getType() << std::endl;
	std::cout << "Grumpy: "<< Grump->getType() << std::endl;
	Bobi->makeSound();
	Grump->makeSound();
	Emplastro->makeSound();
	delete Emplastro;
	delete Bobi;
	delete Grump;

	return 0;
}

/*int	main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	return 0;
}*/