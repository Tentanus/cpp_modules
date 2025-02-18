#ifndef JACOBSTHALSEQUENCE_HPP
#define JACOBSTHALSEQUENCE_HPP

#include <cstddef>

class JacobSthalSequence
{
  private:
	size_t nbr_1;
	size_t nbr_2;

	JacobSthalSequence(const JacobSthalSequence &rhs) = delete;
	JacobSthalSequence &operator=(const JacobSthalSequence &rhs) = delete;

  public:
	JacobSthalSequence();
	~JacobSthalSequence();

	size_t next();
};

#endif // JACOBSTHALSEQUENCE_HPP



/*
	5, 9, 6, 12, 21, 56, 54, 32, 98, 58, 78

	
*/
