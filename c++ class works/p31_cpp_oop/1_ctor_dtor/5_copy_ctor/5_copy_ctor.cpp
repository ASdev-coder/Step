#include <iostream>


#pragma region Intro
//class Point
//{
//private:
//    int x;
//    int y;
//public:
//    Point(int x, int y) :
//        x{ x },
//        y{ y }
//    {}
//};
//
//
//
//int main()
//{
//    /* int a{ 12 };
//     int b{ a };*/
//
//    Point a{ 3, 5 };
//    Point b{ a };       // Происходит побитовое копирование
//
//    Point c{ 0, 0 };
//    c = a;              // Происходит побитовое копирование
//}
#pragma endregion


#pragma region Copy ctor

//class Box
//{
//private:
//	int val;
//	int* ptr;
//
//public:
//	Box(int val, int ptrVal):
//		val{ val },
//		ptr{ new int{ptrVal} }
//	{}
//
//	void setPtrVal(int ptrVal)
//	{
//		*(this->ptr) = ptrVal;
//	}
//	int getPtrVal() const
//	{
//		return *(this->ptr);
//	}
//};
//
//
//int main()
//{
//	Box a{ 2, 5 };
//	Box b{ a };
//
//	std::cout << a.getPtrVal() << '\n';
//	std::cout << b.getPtrVal() << '\n';
//
//	a.setPtrVal(1000);
//
//	std::cout << a.getPtrVal() << '\n';
//	std::cout << b.getPtrVal() << '\n';
//
//	return 0;
//}




//class Box
//{
//private:
//	int val;
//	int* ptr;
//
//public:
//	Box(int val, int ptrVal) :
//		val{ val },
//		ptr{ new int{ptrVal} }
//	{}
//
//	// Неявный "конструктор копирования" выглядит так:
//	/*Box(const Box& obj):
//		val{obj.val},
//		ptr{obj.ptr}
//	{}*/
//
//	Box(const Box& obj) :
//		val{ obj.val },
//		ptr{ new int{*(obj.ptr)} }
//	{}
//
//	void setPtrVal(int ptrVal)
//	{
//		*(this->ptr) = ptrVal;
//	}
//	int getPtrVal() const
//	{
//		return *(this->ptr);
//	}
//};
//
//
//int main()
//{
//	Box a{ 2, 5 };
//	Box b{ a };
//
//	std::cout << a.getPtrVal() << '\n';
//	std::cout << b.getPtrVal() << '\n';
//
//	a.setPtrVal(1000);
//
//	std::cout << a.getPtrVal() << '\n';
//	std::cout << b.getPtrVal() << '\n';
//
//	return 0;
//}





//class Box
//{
//private:
//	int* ptr;
//
//public:
//	Box(int val):
//		ptr{ new int{ val } }
//	{}
//
//	Box(const Box& obj):
//		ptr{ new int { *(obj.ptr) }}
//	{}
//
//	~Box()
//	{
//		if (this->ptr != nullptr)
//			delete this->ptr;
//	}
//};
//
//void test()
//{
//	/*Box a{ 1 };
//	Box b{ a };*/
//
//
//	Box* a = new Box{ 1 };
//	Box* b = new Box{ *a };
//
//	delete a;
//	delete b;
//}
//
//int main()
//{
//	test();
//
//	return 0;
//}

#pragma endregion


#pragma region Examples

//class Box
//{
//public:
//	int val{};
//	Box()
//	{}
//	Box(const Box& obg)
//	{
//		std::cout << "copy ctor\n";
//	}
//};
//
//void f1(Box b)		// Box b{ a }
//{
//
//}
//
//Box f2()
//{
//	return Box{};
//}
//
//int main()
//{
//	/*Box a{};
//
//	Box b{ a };
//
//	f1(a);*/
//}





#pragma endregion


#pragma region Task_1
// Создать класс Matrix, который будет описывать квадратную матрицу (дин массив)
// Под массив память выделять динамически
// Описать обычный конструктор и в нём инициализировать матрицу нулями
// Описать метод fill(), который будет заполнять матрицу случайными значениями
// Описать метод show()
// Определить конструктор копирования и деструктор
// Протестировать все возможные варианты вызова конструктора копирования
//		+ Инициализация на основе другого объекта
//		+ Передача в функцию "по значению"


class Matrix
{
private:
	int size;
	int** arr;

public:
	Matrix(int size):
		size{ size },
		arr{ new int* [size] }
	{
		for (int i{}; i < this->size; ++i)
			this->arr[i] = new int[this->size] {};
	}

	Matrix(const Matrix& obj) :
		size{ obj.size },
		arr{ new int* [obj.size] }
	{
		for (int i{}; i < this->size; ++i)
			this->arr[i] = new int[this->size];

		for (int i{}; i < this->size; ++i)
			for (int j{}; j < this->size; ++j)
				arr[i][j] = obj.arr[i][j];
	}

	void fill()
	{
		for (int i{}; i < this->size; ++i)
			for (int j{}; j < this->size; ++j)
				arr[i][j] = rand() % 10;
	}

	void show()
	{
		for (int i{}; i < this->size; ++i)
		{
			for (int j{}; j < this->size; ++j)
				std::cout << arr[i][j] << ' ';

			std::cout << '\n';
		}
	}

	~Matrix()
	{
		if (this->arr != nullptr)
		{
			for (int i{}; i < this->size; ++i)
				delete[] this->arr[i];

			delete[] arr;
		}
	}
};


void f()
{
	Matrix a{ 10 };
	a.fill();
	a.show();

	Matrix b{ a };
	std::cout << "\n\n";
	b.show();
}


int main()
{
	srand(time(0));

	f();
	


}



#pragma endregion


#pragma region Menu class

//#include <vector>
//
//class MenuItem
//{
//private:
//	std::string text;
//	bool isSelected{};
//
//public:
//	MenuItem(std::string text):
//		text{text}
//	{}
//
//};
//
//enum Direction
//{
//	VERTICAL,
//	HORIZONTAL,
//};
//
//class Menu
//{
//private:
//	std::vector<MenuItem> items;
//	MenuItem* activeItem;
//
//
//
//	void render()
//	{
//
//	}
//
//	void handleUserInput()
//	{
//
//	}
//	
//
//public:
//	//
//	//
//	//
//	void addItem(std::string text)
//	{
//		this->items.push_back(MenuItem{ text });
//	}
//	
//	MenuItem* handle(Direction direction)
//	{
//		// cycle
//			// render
//			// get input
//			// check return
//
//		while (true)
//		{
//			this->render();
//			this->handleUserInput();
//
//			
//
//		}
//
//
//
//	}
//};
//
//int main()
//{
//	Menu menu{};
//	menu.addItem("Home");
//	menu.addItem("Start");
//	menu.addItem("End");
//
//	menu.handle(Direction::VERTICAL);
//}



#pragma endregion



#pragma region Random class

//class Random
//{
//private:
//	int min;
//	int max;
//
//public:
//	Random(int min, int max):
//		min{min},
//		max{max}
//	{}
//
//	void setRange(int min, int max)
//	{
//		this->min = min;
//		this->max = max;
//	}
//
//	int getNext() const
//	{
//		return rand() % (max - min + 1) + min;
//	}
//
//	int* getArray(int count)
//	{
//		int* arr = new int[count];
//		for (int i{}; i < count; ++i)
//			arr[i] = getNext();
//	}
//};
//
//
//int main()
//{
//	srand(time(0));
//
//	Random random{ 0, 9 };
//	//
//	//
//	random.setRange(10, 99);
//
//	for (int i{}; i < 10; ++i)
//		std::cout << random.getNext() << '\n';
//
//	int* arr = random.getArray(1000);
//
//
//	return 0;
//}
//
//
//
//
//

#pragma endregion





