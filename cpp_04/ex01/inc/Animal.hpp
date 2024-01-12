#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <Brain.hpp>

#include <string>

class Animal
{
  private:
	Animal(const Animal &inp);
	Animal operator=(Animal &inp);

  protected:
	std::string _type;

  public:
	Animal();
	virtual ~Animal();

	std::string get_type() const;
	void set_type(std::string type);

	virtual void MakeNoise();
};

#endif // !ANIMAL_HPP
