#ifndef ARRAY_TPP
#define ARRAY_TPP

//-------------------Orthodox Canonical Form-------------------//

template <typename T>
Array<T>::Array()
{
#ifdef MSG
	std::cout << "Called Array Constructor:\tDefault" << std::endl;
#endif
	_size = 1;
	_array = new T[_size];
}

template <typename T>
Array<T>::Array(unsigned int size)
{
#ifdef MSG
	std::cout << "Called Array Constructor:\tSize" << std::endl;
#endif
	_size = size;
	_array = new T[_size + 1];
}

template <typename T>
Array<T>::Array(const Array<T> &rhs)
{
#ifdef MSG
	std::cout << "Called Array Constructor:\tCopy" << std::endl;
#endif
	_size = rhs.size;
	_array = new T[_size + 1];

	for (size_t i = 0; i < _size; i++)
		_array[i] = rhs._array[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &rhs)
{
#ifdef MSG
	std::cout << "Called Array Assignment Operator" << std::endl;
#endif
	_size = rhs.size;
	_array = new T[_size + 1];

	for (size_t i = 0; i < _size; i++)
		_array[i] = rhs._array[i];
}
#endif // !ARRAY_TPP
