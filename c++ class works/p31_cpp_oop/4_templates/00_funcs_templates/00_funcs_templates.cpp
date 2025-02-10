#include <iostream>

#pragma region intro

//int max(int a, int b)
//{
//    return a > b ? a : b;
//}
//
//float max(float a, float b)
//{
//    return a > b ? a : b;
//}

//template<typename T>
//const T& max(const T& a, const T& b)
//{
//    return a > b ? a : b;
//}
//
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
//
//    bool operator>(const Point& p) const
//    {
//        return (this->x + this->y) > (p.x + p.y);
//    }
//
//    friend std::ostream& operator<<(std::ostream& out, const Point& p);
//};
//
//std::ostream& operator<<(std::ostream& out, const Point& p)
//{
//    out << '(' << p.x << ';' << p.y << ")\n";
//
//    return out;
//}
//
//
//
//int main()
//{
//    std::cout << max<int>(3, 4) << '\n';
//    std::cout << max<int>(5, 6) << '\n';
//
//    std::cout << max<double>(4.3, 5.6) << '\n';
//
//    Point a{ 3, 4 };
//    Point b{ 5, 6 };
//
//    std::cout << max<Point>(a, b) << '\n';
//}

#pragma endregion


#pragma region Task
// Создать шаблон ф-ции для вычисления ср. арифметического элементов 1-мерного массива

template<typename T, typename K>
K average(T* arr, int count)
{
	K sum{};									

	for (int i{}; i < count; ++i)
		sum += arr[i];

	return sum / count;
}

class Box
{
private:
	int val;
public:
	Box(int val = 0):
		val{val}
	{}

	Box& operator+=(const Box& b)
	{
		this->val += b.val;

		return *this;
	}

	operator double()
	{
		return (double)this->val;
	}

	friend Box operator/(const Box& a, int b);
	friend std::ostream& operator<<(std::ostream& out, const Box& b);
};

Box operator/(const Box& a, int b)
{
	return Box{ a.val / b };
}

std::ostream& operator<<(std::ostream& out, const Box& b)
{
	out << "VAL = " << b.val;

	return out;
}


int main()
{
	const int count = 5;

	int* arr1 = new int[count] {4, 5, 7, 1, 2};
	std::cout << average<int, double>(arr1, count) << '\n';

	Box* arr2 = new Box[count]{ Box{4}, Box{5}, Box{7}, Box{1}, Box{2} };

	std::cout << average<Box, Box>(arr2, count) << '\n';

	std::cout << average<Box, double>(arr2, count) << '\n';

	// average<Box, Bober>(arr2, count) << '\n';					:-)))
}

#pragma endregion


