#ifndef MATERIA_HPP
#define MATERIA_HPP

#include "AMateria.hpp"

class Materia : public AMateria
{
  public:
	Materia(std::string const &type);
	Materia(const Materia &rhs);
	Materia &operator=(const Materia &rhs);
	~Materia();
};

#endif // !MATERIA_HPP
