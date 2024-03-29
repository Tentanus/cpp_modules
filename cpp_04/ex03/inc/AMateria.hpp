#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>

class ICharacter;

class AMateria
{
  protected:
	std::string _type;

  public:
	AMateria(std::string const &type);
	AMateria(const AMateria &rhs);
	virtual ~AMateria();
	AMateria &operator=(const AMateria &rhs);

	const std::string &getType() const; // Returns the materia type

	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};

#endif // !AMATERIA_HPP
