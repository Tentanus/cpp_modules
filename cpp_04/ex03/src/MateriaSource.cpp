
#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _slots()
{
#ifdef MSG
	std::cout << "Called\tMateriaSource\tConstructor:\tNamed" << std::endl;
#endif

	for (size_t idx = 0; idx < MATERIASOURCE_MAX; idx++)
		_slots[idx] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &rhs)
{
#ifdef MSG
	std::cout << "Called\tMateriaSource\tConstructor:\tCopy" << std::endl;
#endif

	for (size_t idx = 0; idx < MATERIASOURCE_MAX; idx++)
		if (_slots[idx])
			_slots[idx] = rhs._slots[idx];
}

MateriaSource::~MateriaSource()
{
#ifdef MSG
	std::cout << "Called\tMateriaSource\tDeconstructor" << std::endl;
#endif

	for (size_t idx = 0; idx < MATERIASOURCE_MAX; idx++)
		if (_slots[idx])
			delete _slots[idx];
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
#ifdef MSG
	std::cout << "Called\tMateriaSource\tCopy Assignment operator" << std::endl;
#endif
	if (this == &rhs)
		return (*this);

	for (size_t idx = 0; idx < MATERIASOURCE_MAX; idx++)
		if (_slots[idx])
			_slots[idx] = rhs._slots[idx];
	return (*this);
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (m == NULL)
	{
		std::cout << "MateriaSource can't learn this the VOID Materia."
				  << std::endl;
		return;
	}

	size_t idx = 0;
	while (_slots[idx] != NULL && idx < MATERIASOURCE_MAX)
		idx++;

	if (idx == MATERIASOURCE_MAX)
	{
		std::cout
			<< "MateriaSource has no more slots and the Materia has evaporated."
			<< std::endl;
		delete m;
		return;
	}

	_slots[idx] = m;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	size_t idx = 0;
	while (idx < MATERIASOURCE_MAX)
	{
		if (_slots[idx] != NULL && _slots[idx]->getType() == type)
			break;
		idx++;
	}

	if (idx == MATERIASOURCE_MAX)
	{
		std::cout << "MateriaSource does not contain this Materia."
				  << std::endl;
		return (NULL);
	}

	return (_slots[idx]->clone());
}

void MateriaSource::showMateria()
{
	for (size_t idx = 0; idx < MATERIASOURCE_MAX; idx++)
		if (_slots[idx])
			std::cout << "\t[" << idx << "] : " << _slots[idx]->getType()
					  << std::endl;
		else
			std::cout << "\t[" << idx << "] : - EMPTY -" << std::endl;
}
