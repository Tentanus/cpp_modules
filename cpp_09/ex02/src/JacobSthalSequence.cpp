#include "JacobSthalSequence.hpp"

size_t JacobSthalSequence::next()
{
	size_t tmp = nbr_2 + (2 * nbr_1);
	nbr_1 = nbr_2;
	nbr_2 = tmp;
	return (tmp);
}

//-------------------   Getters  -------------------//

JacobSthalSequence::JacobSthalSequence() : nbr_1(1), nbr_2(0)
{
}

JacobSthalSequence::~JacobSthalSequence()
{
}



// 1	2	3	4	5	6	7
// 2  	2	6	10	22	42	86
