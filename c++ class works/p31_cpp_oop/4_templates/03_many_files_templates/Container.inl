#include "Container.h"

template<class T>
void Container<T>::clearMemory()
{
	if (this->arr != nullptr)
		delete[] this->arr;
}

template<class T>
Container<T>::Container(int count) :
	count{ count },
	arr{ new T[count] {} }
{}

template<class T>
Container<T>::Container(const Container<T>& obj) :
	count{ obj.count },
	arr{ new T[obj.count] {} }
{
	for (int i{}; i < this->count; ++i)
		this->arr[i] = obj.arr[i];
}

template<class T>
Container<T>::Container(Container<T>&& obj) :
	count{ obj.count },
	arr{ obj.arr }
{
	obj.arr = nullptr;
}

template<class T>
Container<T>& Container<T>::operator=(const Container<T>& obj)
{
	if (this == &obj)
		return *this;

	this->clearMemory();

	this->count = obj.count;
	this->arr = new T[this->count]{};

	for (int i{}; i < this->count; ++i)
		this->arr[i] = obj.arr[i];

	return *this;
}

template<class T>
Container<T>& Container<T>::operator=(Container<T>&& obj)
{
	this->clearMemory();

	this->count = obj.count;
	this->arr = obj.arr;

	obj.arr = nullptr;

	return *this;
}

template<class T>
Container<T>::~Container()
{
	this->clearMemory();
}
