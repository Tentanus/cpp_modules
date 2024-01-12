#ifndef DOG_HPP
#define DOG_HPP

#include <Animal.hpp>

class Dog : public Animal
{
  private:
	Brain *_brain;

  public:
	Dog();
	Dog(Dog &inp);
	~Dog();

	Dog operator=(const Dog &inp);

	void MakeNoise();
	void AddIdea(const std::string idea);
	const std::string readBrain(int index);
};

#endif //! DOG_HPP
