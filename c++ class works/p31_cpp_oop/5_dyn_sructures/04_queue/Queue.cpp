#include "Queue.h"

template<typename T>
Queue<T>::Queue():
	list{ List<T>{} }
{
}

template<typename T>
Queue<T>::Queue(const Queue<T>& obj):
	list{ obj.list }
{}

template<typename T>
Queue<T>::Queue(Queue<T> && obj):
	list{ obj.list }
{}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& obj)
{
	if (this == &obj)
		return *this;

	this->list = obj.list;

	return *this;
}

template<typename T>
Queue<T>& Queue<T>::operator=(Queue<T>&& obj)
{
	this->list = obj.list;

	return *this;
}

template<typename T>
void Queue<T>::enqueue(const T& val)
{
	this->list.pushBack(val);
}

template<typename T>
T Queue<T>::dequeue()
{
	return this->list.popFront();
}

template<typename T>
bool Queue<T>::isEmpty()
{
	return this->list.isEmpty();
}

template<typename T>
int Queue<T>::getCount()
{
	return this->list.getCount();
}

template<typename T>
void Queue<T>::show()
{
	std::cout << "QUEUE:\n";

	this->list.show();
}
