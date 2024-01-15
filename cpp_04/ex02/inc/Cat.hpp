#ifndef CAT_HPP
#define CAT_HPP

#include <AAnimal.hpp>
#include <Brain.hpp>

class Cat : public AAnimal
{
  private:
	Brain *_brain;

  public:
	Cat();
	Cat(Cat &inp);
	~Cat();

	Cat operator=(const Cat &inp);

	void MakeNoise();
	void AddIdea(const std::string idea);
	const std::string readBrain(int index);
};

#endif // !CAT_HPP
