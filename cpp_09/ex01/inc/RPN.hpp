#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <stddef.h>
#include <string>

class RPN
{
  private:
	std::stack<int> _stack;

  public:
	RPN();
	RPN(const RPN &rhs);
	RPN &operator=(const RPN &rhs);
	~RPN();

	void push(int val);
	int getStackSize() const;
	int getTop() const;

	void add();
	void subtract();
	void multiply();
	void divide();
	void print() const;
};

#endif // !RPN_HPP
