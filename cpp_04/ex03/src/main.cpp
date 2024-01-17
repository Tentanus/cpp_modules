
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

#include <string>

#define MSG_BORDER                                                             \
	"=----------------------------------------------------------="

int main()
{
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(NULL);

	std::cout << "\nsrc MateriaSource contains:" << std::endl;
	src->showMateria();

	std::cout << "\n" << MSG_BORDER << "\n" << std::endl;

	ICharacter *me = new Character("me");

	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	std::cout << "\n" << MSG_BORDER << "\n" << std::endl;

	ICharacter *bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);

	std::cout << "\n" << MSG_BORDER << "\n" << std::endl;

	delete bob;
	delete me;
	delete src;

	return 0;
}
