#ifndef WRONGDOG_HPP
#define WRONGDOG_HPP

#include <WrongAnimal.hpp>

class WrongDog : public WrongAnimal
{
  public:
	WrongDog();
	WrongDog(WrongDog &inp);
	~WrongDog();

	WrongDog operator=(const WrongDog &inp);

	void MakeNoise();
};

#endif //! WRONGDOG_HPP
