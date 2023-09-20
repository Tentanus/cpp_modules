#ifndef CAT_HPP
#define CAT_HPP

#include <Animal.hpp>

class Cat : public Animal
{
  public:
	Cat();
	Cat(Cat &inp);
	~Cat();

	Cat operator=(const Cat &inp);
};

#endif // !CAT_HPP
