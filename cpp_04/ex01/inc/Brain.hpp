#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
  private:
	static const int _max_idea = 100;

	std::string _idea[_max_idea + 1];
	int _current_idea;

  public:
	Brain();
	Brain(const Brain &rhs);
	~Brain();

	Brain &operator=(const Brain &rhs);

	void AddIdea(const std::string bulb);
	const std::string GetIdea(int index);
};

#endif // !BRAIN_HPP
