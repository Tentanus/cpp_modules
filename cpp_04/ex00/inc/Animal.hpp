#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
  protected:
	std::string _type;

  public:
	Animal();
	Animal(const Animal &inp);
	~Animal();

	Animal operator=(Animal &inp);

	std::string get_type() const;
	void set_type(std::string type);
};

#endif // !ANIMAL_HPP
