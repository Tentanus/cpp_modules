#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

typedef struct Data
{
	int data;
	int x;
	int y;
} Data;

std::ostream &operator<<(std::ostream &os, const Data &ptr);

#endif
