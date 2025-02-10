#pragma once

#include <iostream>

template<class T>
class Container
{
private:
	int count;
	T* arr;

	void clearMemory();

public:
	Container(int count = 10);

	Container(const Container<T>& obj);

	Container(Container<T>&& obj);

	Container<T>& operator=(const Container<T>& obj);

	Container<T>& operator=(Container<T>&& obj);

	~Container();
};

// #include "Container.inl"					// ;-(