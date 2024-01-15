#ifndef DOG_HPP
#define DOG_HPP

#include <AAnimal.hpp>
#include <Brain.hpp>

class Dog : public AAnimal
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
