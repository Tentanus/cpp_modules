#include "MutantStack.hpp"
#include <iostream>
#include <iterator>
#include <string>

int main(void)
{
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);

		std::cout << "top: "  << mstack.top() << "\n";
		std::cout << "size: " << mstack.size() << "\n";
		std::cout << "pop" << "\n";
		mstack.pop();
		std::cout << "size: " << mstack.size() << "\n\n";

		std::cout << "================================================="
				  << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		std::cout << "top: "  << mstack.top() << "\n";
		std::cout << "size: " << mstack.size() << "\n";

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		int i = 0;
		while (it != ite)
		{
			std::cout << "stk [" << i << "]: \t" << *it << std::endl;
			i++;
			it++;
		}
		std::stack<int> s(mstack);

		mstack.pop();
		std::cout << "================================================="
				  << std::endl;

		it = mstack.begin();
		ite = mstack.end();
		i = 0;

		while (it != ite)
		{
			std::cout << "stk [" << i << "]: \t" << *it << std::endl;
			i++;
			it++;
		}
		return 0;
	}
	std::cout << "================================================="
			  << std::endl;
}
