#include <iostream>

//class Account
//{
//private:
//	int sum;
//
//public:
//	explicit Account(int sum = 1000):
//		sum{sum}
//	{}
//
//	int getSum() const
//	{
//		return this->sum;
//	}
//
//	bool operator>(const Account& b)
//	{
//		return this->sum > b.sum;
//	}
//
//	bool operator<(const Account& b)
//	{
//		// return this->sum < b.sum;
//
//		return !((*this) > b);
//	}
//
//	bool operator==(const Account& b)
//	{
//		return this->sum == b.sum;
//	}
//
//	bool operator!=(const Account& b)
//	{
//		return !((*this) == b);
//	}
//
//	bool operator>=(const Account& b)
//	{
//		return (*this) > b || (*this) == b;
//	}
//
//	bool operator<=(const Account& b)
//	{
//		return (*this) < b || (*this) == b;
//	}
//};
//
//bool operator==(const Account& a, int b)
//{
//	return a.getSum() == b;
//}
//
//int main()
//{
//	Account a{ 1000 };
//	Account b{ 2000 };
//	Account c{ 3000 };
//
//	std::cout << (a > b) << '\n';
//	std::cout << (a < b) << '\n';
//
//	std::cout << (a == 1000) << '\n';
//
//	return 0;
//}





// TASK

class Point
{

};

class Rectangle
{
private:
	Point p;
	int w;
	int h;

public:
	Rectangle(const Point& p, int w, int h);
	double getArea() const;
};

class Circle
{
private:
	Point center;
	int radius;

public:
	Circle(int x, int y, int radius);

	double getArea() const;
	bool operator==(const Circle& b);			// true, если окружности пересекаются
	bool operator==(const Rectangle& b);		// true, если окружности пересекаются***
};

bool operator>(const Circle& a, const Rectangle& b);		// площади
bool operator>(const Rectangle& b, const Circle& a);		// площади












