#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal
{
  private:
	WrongAnimal(const WrongAnimal &inp);
	WrongAnimal operator=(WrongAnimal &inp);

  protected:
	std::string _type;

  public:
	WrongAnimal();
	virtual ~WrongAnimal();

	std::string get_type() const;
	void set_type(std::string type);

	void MakeNoise();
};

#endif // !WRONGANIMAL_HPP
