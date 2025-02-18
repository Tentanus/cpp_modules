#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

class NotFoundException : public std::exception
{
  public:
	virtual const char *what() const throw()
	{
		return "Not found in Container";
	};
};

template <typename Container>
typename Container::iterator easyfind(Container &container, int value)
{
	typename Container::iterator it =
		std::find(container.begin(), container.end(), value);
	if (it == container.end())
	{
		throw NotFoundException();
	}
	return it;
}

#endif // !EASYFIND_HPP
