#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("Barret");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	me->unequip(0);
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->unequip(1);
	me->equip(tmp);
	me->unequip(3);
	ICharacter* Cloud = new Character("Cloud");
	ICharacter* Sephiroth = new Character("Sephiroth");
	me->use(0, *Sephiroth);
	me->use(1, *Cloud);
	me->use(2, *Sephiroth);
	me->use(3, *Cloud);
	delete Cloud;
	delete Sephiroth;
	delete me;
	delete src;
	return 0;
}

/*$> clang++ -W -Wall -Werror *.cpp
$> ./a.out | cat -e
* shoots an ice bolt at bob *$
* heals bob's wounds *$*/
