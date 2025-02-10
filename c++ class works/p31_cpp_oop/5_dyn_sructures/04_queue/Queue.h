#pragma once

#include "List.h"

template<typename T>
class Queue
{
private:
	List<T> list;

public:
	Queue<T>();

	Queue<T>(const Queue<T>& obj);

	Queue<T>& operator=(const Queue<T>& obj);

	Queue<T>(Queue<T>&& obj);

	Queue<T>& operator=(Queue<T>&& obj);

	void enqueue(const T& val);

	T dequeue();

	bool isEmpty();

	int getCount();

	void show();
};


