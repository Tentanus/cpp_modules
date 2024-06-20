#include "MutantStack.hpp"
#include <iterator>
#include <iostream>
#include <string>

int main(void)
{
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);

        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
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
        return 0;
    }
    std::cout << "=================================================" << std::endl;
}
