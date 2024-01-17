#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
  public:
	Ice();
	Ice(const Ice &rhs);
	~Ice();
	Ice &operator=(const Ice &rhs);

	Ice *clone() const;

	void use(ICharacter &target);
};

#endif // !ICE_HPP
