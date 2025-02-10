#include <iostream>

//class Container
//{
//private:
//    int arr[10];
//
//public:
//    explicit Container()
//    {
//        for (int i{}; i < 10; ++i)
//            this->arr[i] = i * 10;
//    }
//
//    int& getElement(int index)
//    {
//        return this->arr[index];
//    }
//
//    void setElement(int index, int val)
//    {
//        this->arr[index] = val;
//    }
//
//    // для неконстантных объектов
//    int& operator[](const int id)
//    {
//        return this->arr[id];
//    }
//
//    // для неконстантных объектов
//    int& operator[](const std::string& id)
//    {
//        if (id == "one")
//            return this->arr[1];
//
//        return this->arr[0];
//    }
//
//    // для константных объектов
//    const int& operator[](const int id) const
//    {
//        return this->arr[id];
//    }
//};
//
//
//int main()
//{
//    // Container a{};
//
//    /*std::cout << a.getElement(2);
//
//    a.setElement(5, 200);
//
//    a.getElement(2) = 101;*/
//
//
//
//
//    /*Container container{};
//
//    std::cout << container[2];
//    container[2] = 101;
//
//    std::cout << container["one"] << '\n';
//    container["one"] = 1000;*/
//
//
//
//    const Container container{};
//
//    std::cout << container[2];
//    // container[2] = 200;             // ERROR
//}



#pragma region Practice

class Matrix
{
private:
	int size;
	int** arr;

public:
	Matrix(int size, int initVal = 1):
		size{size},
		arr{ new int* [size] {} }
	{
		for (int i{}; i < this->size; ++i)
		{
			this->arr[i] = new int[this->size] { };

			for (int j{}; j < this->size; ++j)
				this->arr[i][j] = initVal;
		}
	}

	void render()
	{
		for (int i{}; i < this->size; ++i)
		{
			for (int j{}; j < this->size; ++j)
				std::cout << this->arr[i][j] << ' ';

			std::cout << '\n';
		}

		std::cout << "\n\n";
	}

	/*int*& operator[](int index)
	{
		return this->arr[index];
	}*/

	int** operator[](int index)
	{
		return &this->arr[index];
	}
};

int main()
{
	Matrix m{ 10 };
	m.render();

	int* row = new int[10] {3, 4, 3, 4, 3, 4, 3, 4, 3, 4};


	// ====== int*& operator[](int index)
	/*int*& ref = m[2];

	delete[] ref;
	ref = row;

	m.render();*/


	// ====== // ====== int** operator[](int index)
	int** ptr = m[2];

	delete[] *ptr;
	*ptr = row;

	m.render();
}

#pragma endregion

