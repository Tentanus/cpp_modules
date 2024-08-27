#include "JacobSthalSequence.hpp"

size_t JacobSthalSequence::next()
{
	n++;
	if (n == 1)
		return (nbr_1);
	else if (n == 2)
		return (nbr_2);

	size_t tmp = nbr_2 + (2 * nbr_1);
	nbr_1 = nbr_2;
	nbr_2 = tmp;
	return (tmp);
}

//-------------------   Getters  -------------------//

JacobSthalSequence::JacobSthalSequence() : nbr_1(2), nbr_2(2), n(0)
{
}

JacobSthalSequence::~JacobSthalSequence()
{
}
