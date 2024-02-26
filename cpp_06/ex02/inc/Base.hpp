#ifndef BASE_HPP
#define BASE_HPP

#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unistd.h>

class Base
{
  public:
	virtual ~Base();
	static Base *generate(void);
	static void identify(Base *ptr);
	static void identify(Base &ref);

  private:
};

#endif // !BASE_HPP
