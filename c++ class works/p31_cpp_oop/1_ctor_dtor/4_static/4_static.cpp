#include <iostream>

#pragma region Static in functions

//int val{ 45 };
//
//int fn()
//{
//	// static int val{ 45 };
//
//	return ++val;
//}
//
//int main()
//{
//	std::cout << fn() << '\n';
//	std::cout << fn() << '\n';
//	std::cout << fn() << '\n';
//	std::cout << fn() << '\n';
//	std::cout << fn() << '\n';
//
//	return 0;
//}

#pragma endregion


#pragma region static fields

//class Container
//{
//private:
//	static int maxId;
//	static int stPrvVal;
//
//	int id;
//
//public:
//	Container():
//		id{ ++Container::maxId }
//	{}
//
//	void show()
//	{
//		std::cout << "id = " << this->id << '\n';
//	}
//};
//
//int Container::maxId{ 0 };
//int Container::stPrvVal{ 120 };
//
//int main()
//{
//	Container a{};
//	Container b{};
//	Container c{};
//	Container d{};
//
//	a.show();
//	b.show();
//	c.show();
//	d.show();
//
//	return 0;
//}

#pragma endregion


#pragma region Static methods

//class Container
//{
//private:
//	static int count;
//
//public:
//	int val;
//
//	static void init( int c)
//	{
//		Container::count = c;
//	}
//
//	static int getCount()
//	{
//		// std::cout << this << '\n';		// ERROR
//
//		return Container::count;
//	}
//};
//
//int Container::count = 0;
//
//int main()
//{
//	Container::init(10);
//	std::cout << Container::getCount();
//
//	return 0;
//}

#pragma endregion
