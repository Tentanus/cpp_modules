#include "RPN.hpp"
#include <stack>

void RPN::push(int val)
{
	if (static_cast<int>(val) >= '0' && static_cast<int>(val) <= '9')
		_stack.push(static_cast<int>(val) - '0');
	else
		throw std::runtime_error("non-digit value");
}

int RPN::getStackSize() const
{
	return (_stack.size());
}

int RPN::getTop() const
{
	if (_stack.empty())
		throw std::runtime_error("no value in stack");
	if (_stack.size() > 1)
		throw std::runtime_error("more than one value in stack");
	return (_stack.top());
}

void RPN::print() const
{
	std::stack<int> cp = _stack;
	for (std::stack<int> tmp = cp; !tmp.empty(); tmp.pop())
		std::cout << tmp.top() << " ";
	std::cout << std::endl;
}

void RPN::add()
{
	if (getStackSize() < 2)
		throw std::runtime_error("not enough values in stack to add");
	int lhs = _stack.top();
	_stack.pop();
	int rhs = _stack.top();
	_stack.pop();
	lhs += rhs;
	_stack.push(lhs);
}

void RPN::subtract()
{
	if (getStackSize() < 2)
		throw std::runtime_error("not enough values in stack to subtract");
	int lhs = _stack.top();
	_stack.pop();
	int rhs = _stack.top();
	_stack.pop();
	rhs -= lhs;
	_stack.push(rhs);
}

void RPN::multiply()
{
	if (getStackSize() < 2)
		throw std::runtime_error("not enough values in stack to multiply");
	int lhs = _stack.top();
	_stack.pop();
	int rhs = _stack.top();
	_stack.pop();
	lhs *= rhs;
	_stack.push(lhs);
}

void RPN::divide()
{
	if (getStackSize() < 2)
		throw std::runtime_error("not enough values in stack to divide");
	int lhs = _stack.top();
	_stack.pop();
	int rhs = _stack.top();
	_stack.pop();
	rhs /= lhs;
	_stack.push(rhs);
}

//-------------------Orthodox Canonical Form-------------------//

RPN::RPN()
{
#ifdef MSG
	std::cout << "Called\tRPN\tConstructor:\tDefault" << std::endl;
#endif
}

RPN::RPN(const RPN &rhs)
{
#ifdef MSG
	std::cout << "Called\tRPN\tConstructor:\tCopy" << std::endl;
#endif
	_stack = rhs._stack;
}

RPN &RPN::operator=(const RPN &rhs)
{
#ifdef MSG
	std::cout << "Called\tRPN\tCopy Assignement Operator" << std::endl;
#endif
	if (&rhs == this)
		return (*this);
	_stack = rhs._stack;
	return (*this);
}

RPN::~RPN()
{
#ifdef MSG
	std::cout << "Called\tRPN\tDeconstuctor" << std::endl;
#endif
}
