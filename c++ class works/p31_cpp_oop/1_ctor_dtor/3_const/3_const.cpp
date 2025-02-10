#include <iostream>

#pragma region Intro

//int main()
//{
//	int val{ 45 };
//	const int cVal{ 23 };
//
//	int* a{ &val };
//	int* const b{ &val };
//	const int* c{ &val };
//	const int* const d{ &val };
//
//	// int* a{ &cVal };// ERROR
//	// int* const b{ &cVal };// ERROR
//	const int* c{ &cVal };
//	const int* const d{ &cVal };
//
//	int& e{ val };
//	const int& f{ val };
//	const int& g{ cVal };
//	const int& h{ 12 };
//
//}

#pragma endregion


#pragma region const object

//class Point
//{
//public:
//	int x;
//	int y;
//
//	Point() :
//		x{},
//		y{}
//	{}
//	Point(int x, int y):
//		x{x},
//		y{y}
//	{}
//	void setX(int x)
//	{
//		this->x = x;
//	}
//};
//
//int main()
//{
//	const Point a{ 4, 5 };
//	// a.x = 33;		// ERROR
//	// a.setX(33);		// ERROR
//
//	std::cout << a.x;
//
//	return 0;
//}

#pragma endregion


#pragma region Константный метод (Метод с константным this)

//class Box
//{
//private:
//	int val;
//public:
//	Box(int val):
//		val{val}
//	{}
//
//	void show1()							// void show(Box* const this)
//	{
//		std::cout << "Val = " << this->val << '\n';
//	}
//
//	void show2() const						// void show(const Box* const this)
//	{
//		// this->val = 12;		// ERROR
//		std::cout << "Val = " << this->val << '\n';
//	}
//};
//
//int main()
//{
//
//	const Box a{ 101 };
//	Box b{ 102 };
//
//	// a.show1();		// ERROR
//	a.show2();
//
//	b.show1();
//	b.show2();
//
//	return 0;
//}

#pragma endregion


#pragma region Методы, возвращающие const

//class Box
//{
//private:
//	int x;
//public:
//	Box():
//		x{}
//	{}
//
//	int getX() const
//	{
//		return this->x;
//	}
//
//	const int getConstX() const
//	{
//		return this->x;
//	}
//
//	void setX(int val)
//	{
//		this->x = val;
//	}
//};
//
//void main()
//{
//	Box a{};
//
//	int val1{ a.getX() };				// int val1{ int temp{ 0 } };			условно
//	int val2{ a.getConstX() };			// int val2{ const int temp{ 0 } };		условно
//
//
//	const int x{ 34 };
//	int y{ x };
//}



//class Box
//{
//private:
//	int x;
//public:
//	Box():
//		x{}
//	{}
//
//	const int* const test() const
//	{
//		// this->x = 45;		// ERROR
//
//		const int* const result{ &x };
//		return result;
//	}
//};
//
//int main()
//{
//	Box box{};
//
//	// int* ptr{ box.test() };		// ERROR --> int* ptr{ const int* const result{ 0xAAAFFF }; }
//
//	const int* ptr{ box.test() };
//}

#pragma endregion


#pragma region Overloading (Перегрузка)

//void f(int a, int b)
//{}
//
//void f(int a, int b, int c)
//{}
//
//void f(std::string a, int* ptr)
//{}
//
//void f(int* ptr, std::string a)
//{}



//class Point
//{
//private:
//	int x;
//	int y;
//public:
//	Point(int x, int y):
//		x{x},
//		y{y}
//	{}
//
//	int getX() const
//	{
//		return this->x;
//	}
//
//	int getY() const
//	{
//		return this->y;
//	}
//
//	int f()
//	{
//		return 12;
//	}
//
//	int f() const
//	{
//		return 101;
//	}
//};
//
//int main()
//{
//	Point a{ 1, 2 };
//	const Point b{ 3, 4 };
//
//	std::cout << a.f() << '\n';
//	std::cout << b.f() << '\n';
//
//	return 0;
//}

#pragma endregion
