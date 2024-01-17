
#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

#include <iostream>
#include <string>

#define MATERIASOURCE_MAX 4

class MateriaSource : public IMateriaSource
{
  protected:
	AMateria *_slots[MATERIASOURCE_MAX];

  public:
	MateriaSource();
	MateriaSource(const MateriaSource &rhs);
	virtual ~MateriaSource();
	MateriaSource &operator=(const MateriaSource &rhs);

	void learnMateria(AMateria *m);
	AMateria *createMateria(std::string const &type);

	virtual void showMateria();
};

#endif // !MATERIASOURCE_HPP
