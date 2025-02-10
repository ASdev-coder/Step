#include <iostream>

#pragma region intro
//// l-value
//// r-value
////          pr-value
////          x-value
////          gl-value
//
//
//class Point
//{
//private:
//    int x;
//    int y;
//public:
//    Point(int x = 0, int y = 0):
//        x{x},
//        y{y}
//    {}
//};
//
//void render(Point p)
//{
//
//}
//
//int main()
//{
//    // l-value
//
//    int a{};
//    std::cout << &a;
//    a = 45;
//
//    const int b{};
//    // b = 45;              // ERROR
//
//    // r-value
//    5;
//
//    int a{ 5 };
//    int res = a + 3;
//
//    render(Point{ 3, 4 });
//
//}
//
//
//
//class Container
//{
//private:
//    int count;
//    int** arr;
//public:
//
//};
//
//int main()
//{
//    std::cout << "Hello World!\n";
//}
//
#pragma endregion


#pragma region Theory
// ====== l-value references =======
//int a{ 4 };
//const int b{ 45 };
//
//int& ref1 = a;					// неконстантное l-value
//
//const int& ref2 = a;			// неконстантное l-value
//const int& ref3 = b;			// константное l-value
//const int& ref4 = 34;			// r-value
//
//void func0(int& ref)
//{
//
//}
//void func(const int& ref)
//{
//
//}
//
//int main()
//{
//	int a = 45;
//	const int b = 56;
//
//	func0(a);
//	// func0(b);	// ERROR
//	// func0(12);	// ERROR
//
//	func(a);
//	func(b);
//	func(12);
//}




// ====== r-value references ======
//int main()
//{
//	int a{ 7 };
//
//	// int&& rref = a;		// ERROR
//	int&& rref = 45;
//	rref = 17;
//}




// ====== example_1 =======
//class Box
//{
//public:
//	int val;
//	Box(int val = 0):
//		val{val}
//	{}
//};
//
//int main()
//{
//	Box a{ 12 };
//	const Box b{ 34 };
//
//	Box& ref1 = a;
//	// Box& ref1 = b;		// ERROR
//
//	const Box& ref2 = a;
//	const Box& ref3 = b;
//	const Box& ref4 = { 101 };
//	const Box& ref5 = Box{ 101 };
//
//	// ref4.val = 110;					// ERROR
//
//
//
//
//	Box&& ref6 = { 102 };
//	ref6.val = 150;				// :-)
//	std::cout << &ref6;
//
//	const Box&& ref7 = Box{ 3 };
//
//
//	int&& r = 12;
//	std::cout << &r;
//}
#pragma endregion


#pragma region funcs overloading example

//void func(const int& ref)
//{
//	std::cout << "l-value ref\n";
//}
//
//void func(int&& rref)
//{
//	std::cout << "r-value ref\n";
//}
//
//int main()
//{
//	int a{ 7 };
//	const int b{ 9 };
//
//	func(a);
//	func(b);
//	func(7);
//}

#pragma endregion


#pragma region BIG example :-)

class Student
{
private:
	static int maxId;

	int id;
	std::string email = "no_email";
	int gCount{ 0 };
	int* grades{ nullptr };

public:
	// явный конструктор
	explicit Student(const std::string& email = "no_email", int gCount = 0) :
		id{ ++Student::maxId },
		email{ email },
		gCount{gCount},
		grades{ new int[gCount] {} }
	{
		std::cout << "explicit ctor\n";
	}

	// конструктор копирования
	Student(const Student& obj):
		id{ ++Student::maxId },
		email{ obj.email },
		gCount{ obj.gCount },
		grades{ new int[gCount] {} }
	{
		for (int i{}; i < this->gCount; ++i)
			this->grades[i] = obj.grades[i];

		std::cout << "copy ctor\n";
	}

	// конструктор переноса (перемещения)
	Student(Student&& s):
		id{ ++Student::maxId },
		email{ s.email },
		gCount{s.gCount},
		grades{s.grades}
	{
		s.grades = nullptr;
	}

	// оператор присваивания копированием
	Student& operator=(const Student& obj)
	{
		if (this == &obj)
			return *this;

		this->email = obj.email;
		this->gCount = obj.gCount;

		if (this->grades != nullptr)
			delete[] this->grades;

		this->grades = new int[this->gCount];
		for (int i{}; i < this->gCount; ++i)
			this->grades[i] = obj.grades[i];

		std::cout << "copy assign\n";

		return *this;
	}

	// оператор присваивания переносом
	Student& operator=(Student&& obj)
	{
		this->email = obj.email;
		this->gCount = obj.gCount;

		if (this->grades != nullptr)
			delete[] this->grades;

		this->grades = obj.grades;
		obj.grades = nullptr;

		std::cout << "move assign\n";

		return *this;
	}

	void setEmail(const std::string& email)
	{
		this->email = email;
	}

	~Student()
	{
		if (this->grades != nullptr)
			delete[] this->grades;
	}
};

int Student::maxId{ 0 };

Student generate()
{
	std::cout << "--> generate\n";

	Student res{ "vasia", 10 };
	// res.setEmail("petya@mail.com");

	return res;
}

int main()
{
	// Student a{};

	// Student b{ a };

	// Student c{ Student{} };

	// Student c{ generate() };


	/*Student a{"vasia@mail.com", 10};

	Student b{};

	b = a;

	b = Student{ "petya@mail.com", 20 };*/



	/*Student a{};

	for (int i{ 0 }; i < 5; ++i)
		a = generate();*/
}


#pragma endregion










