#include <iostream>


#pragma region intro

template<typename T>
class Container
{
private:
	int count;
	T* arr;

	void clearMemory()
	{
		if (this->arr != nullptr)
			delete[] this->arr;
	}

public:
	Container(int count = 10):
		count{count},
		arr{ new T[count] {} }
	{}

	Container(const Container<T>& obj) :
		count{ obj.count },
		arr{ new T[obj.count] {} }
	{
		for (int i{}; i < this->count; ++i)
			this->arr[i] = obj.arr[i];
	}

	Container(Container<T>&& obj) :
		count{ obj.count },
		arr{ obj.arr }
	{
		obj.arr = nullptr;
	}

	Container<T>& operator=(const Container<T>& obj)
	{
		if (this == &obj)
			return *this;

		this->clearMemory();

		this->count = obj.count;
		this->arr = new T[this->count] {};

		for (int i{}; i < this->count; ++i)
			this->arr[i] = obj.arr[i];

		return *this;
	}

	Container<T>& operator=(Container<T>&& obj)
	{
		this->clearMemory();

		this->count = obj.count;
		this->arr = obj.arr;

		obj.arr = nullptr;

		return *this;
	}

	int getCount();
	void erase();
	void render();
	T& operator[](const int id);
	const T& operator[](const int id) const;

	~Container()
	{
		this->clearMemory();
	}
};

template<typename T>
int Container<T>::getCount()
{
	return this->count;
}


int main()
{
	Container<int>a{};
	Container<int>b{};

	Container<double>c{};


}
#pragma endregion

