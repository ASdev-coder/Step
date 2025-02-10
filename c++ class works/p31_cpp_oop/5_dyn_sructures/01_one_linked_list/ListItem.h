#pragma once

template<class T>
class ListItem
{
private:
	T value;
	ListItem<T>* next;

public:
	ListItem():
		value{},
		next{ nullptr }
	{}

	ListItem(const T& value):
		value{value},
		next{ nullptr }
	{}

	ListItem(const ListItem<T>& obj):
		value{obj.value},
		next{ nullptr }
	{}

	void setNext(ListItem<T>* next)
	{
		this->next = next;
	}

	T& getVal()
	{
		return this->value;
	}

	ListItem<T>* getNext()
	{
		return this->next;
	}

	void renderInfo()
	{
		std::cout << "this = " << this << "\t\tval = " << value << "   \tnext = " << this->next << '\n';
	}

};

