#pragma once

#include "ListItem.h"

template<class T>
class List
{
private:
	ListItem<T>* head;
	ListItem<T>* tail;
	int count;

	void clearMemory()
	{
		if (this->head == nullptr || this->tail == nullptr)
			return;

		ListItem<T>* iterator{ this->head };
		ListItem<T>* next = iterator->getNext();

		while (iterator != nullptr)
		{
			delete iterator;

			iterator = next;

			if (next != nullptr)
				next = next->getNext();
		}

		this->head = nullptr;
		this->tail = nullptr;
		this->count = 0;
	}

	ListItem<T>* findListItem(int index)
	{
		if (index > this->count - 1 || index < 0)
			return nullptr;				// TODO: throw exception

		ListItem<T>* target{ this->head };

		for (int i{}; i < index; ++i)
			target = target->getNext();

		return target;
	}

public:

	// ctors
	List():
		head{ nullptr },
		tail{ nullptr },
		count{ 0 }
	{}

	List(const List<T>& obj):
		List()
	{
		if (obj.count == 0)
			return;

		ListItem<T>* objCurrent{ obj.head };


		for (int i{}; i < obj.count; ++i)
		{
			this->pushToTail(objCurrent->getVal());

			objCurrent = objCurrent->getNext();
		}
	}

	List(List<T>&& obj):
		head{obj.head},
		tail{obj.tail},
		count{count}
	{
		obj.head = nullptr;
		obj.tail = nullptr;
	}

	/*List(const std::initializer_list& inList);*/


	// operators
	T& operator[](int index)
	{
		ListItem<T>* target = this->findListItem(index);

		// if (target == nullptr)							// TODO: throw exception

		return target->getVal();
	}
	/*const T& operator(int index) const;
	List<T>& operator=(const List<T>& obj);
	List<T>& operator=(List<T>&& obj);*/

	// methods
	void pushToTail(const T& value)
	{
		ListItem<T>* newItem = new ListItem<T>{ value };

		if (this->isEmpty())
			this->head = newItem;
		else
			this->tail->setNext(newItem);

		this->tail = newItem;

		++this->count;
	}
	void pushToHead(const T& value)
	{
		ListItem<T>* newItem = new ListItem<T>{ value };

		if (this->isEmpty())
			this->tail = newItem;
		else
			newItem->setNext(this->head);

		this->head = newItem;

		++this->count;
	}
	/*void insert(const T& value, int index);

	T popFromTail();
	T popFromHead();
	T peak(int index);

	void swap(int indexA, int indexB);								********

	void remove(int index);*/

	bool isEmpty()
	{
		return this->count == 0;
	}
	/*int getCount();
	void clear();*/

	void render()
	{
		std::cout << "count: " << this->count << '\n';
		std::cout << "HEAD = " << this->head << '\n';
		std::cout << "TAIL = " << this->tail << '\n';
		std::cout << "List: ";

		if (this->isEmpty())
			std::cout << "is empty\n\n";
		else
			std::cout << '\n';

		ListItem<T>* iterator{ this->head };

		while (iterator != nullptr)
		{
			iterator->renderInfo();
			iterator = iterator->getNext();
		}

		std::cout << "\n\n";
	}

	~List()
	{
		this->clearMemory();
		std::cout << "~List()\n\n";
	}
};

