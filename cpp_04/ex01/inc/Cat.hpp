#ifndef CAT_HPP
#define CAT_HPP

#include <Animal.hpp>
#include <Brain.hpp>

class Cat : public Animal
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
};

#endif // !CAT_HPP
