#include "MutantStack.hpp"
#include <iterator>
#include <iostream>
#include <string>

int main(void)
{
    MutantStack<int> stk;

    stk.push(1);
    stk.push(2);
    stk.push(3);

    for (const auto it = stk.cbegin() ; it != stk.cend() ; it++)
    {
        std::cout << "stk : \t" << *it << std::endl;
    }

}