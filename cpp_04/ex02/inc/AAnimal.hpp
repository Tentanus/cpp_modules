#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>

class AAnimal
{
  private:
	AAnimal(const AAnimal &inp);

  protected:
	std::string _type;

  public:
	AAnimal();
	virtual ~AAnimal();

	std::string get_type() const;
	virtual void set_type(std::string type);

	virtual void MakeNoise() = 0;
};

#endif // !ANIMAL_HPP
