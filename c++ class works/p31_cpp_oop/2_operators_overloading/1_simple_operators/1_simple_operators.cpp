#include <iostream>


#pragma region арифметические + унарные

//class Point
//{
//private:
//	int x;
//	int y;
//public:
//	Point():
//		x{},
//		y{}
//	{}
//	Point(int x, int y):
//		x{x},
//		y{y}
//	{}
//	int getX() const
//	{
//		return this->x;
//	}
//	int getY() const
//	{
//		return this->y;
//	}
//	void setX(int val)
//	{
//		this->x = val;
//	}
//	void setY(int val)
//	{
//		this->y = val;
//	}
//	void show()
//	{
//		std::cout << "(" << this->x << ";" << this->y << ")\n";
//	}
//
//	// ----- binary +
//	Point operator+(const Point& p) 
//	{
//		/*Point res{};
//		res.x = this->x + p.x;
//		res.y = this->y + p.y;
//
//		return res;*/
//
//		return Point{ this->x + p.x, this->y + p.y };
//	}
//
//	Point operator+(int val)
//	{
//		return Point{ this->x + val, this->y + val };
//	}
//
//	// ----- unary -
//	Point operator-()
//	{
//		return Point{ -this->x, -this->y };
//	}
//};
//
//
////// ----- binary +
////Point operator+(const Point& a, const Point& b)
////{
////	return Point{ a.getX() + b.getX(), a.getY() + b.getY()};
////}
////
////Point operator+(const Point& a, int val)
////{
////	return Point{ a.getX() + val, a.getY() + val };
////}
////
////// ----- unary -
////Point operator-(const Point& a)
////{
////	return Point{ -a.getX(), -a.getY()};
////}
//
//
//int main()
//{
//	//Point a{ 3, 4 };
//	//Point b{ 7, 8 };
//	//a.show();
//	//b.show();
//
//
//	//Point c{ a + b };			// a.operator+(b)
//	//c.show();
//
//	//Point d{ a + 100 };			// a.operator+(100)
//	//d.show();
//
//	//Point e{ -a };
//	//e.show();
//
//
//
//
//
//	/*Point a{ 3, 4 };
//	Point b{ 7, 8 };
//
//	Point c{ a.operator+(b) };
//	Point d{ a + b };*/
//
//
//
//
//	Point a{ 3, 4 };
//	Point b{ 5, 6 };
//	Point c{ 7, 1 };
//
//	Point d{ a + b + -c };
//	d.show();
//
//	return 0;
//}

#pragma endregion



#pragma region TASK_1
class Block
{
private:
	int count;
	int* arr;

public:
	Block();
	Block(int count, const int* arr);
	Block(const Block& obj);

	int get(int id);
	void set(int id, int val);

	void setSize(int size);

	void show();

	Block operator+(const Block& b);	// [1, 3, 4] + [5, 1, 2, 4] ==> [1, 3, 4, 5, 1, 2, 4]

	const Block& operator+(int val)			// [1, 3, 4] + 10 ==> [11, 13, 14]
	{
		for (int i{}; i < this->count; ++i)
			this->arr[i] += val;

		return *this;
	}

	int operator+();					// +[1, 3, 4] ==> 8

	~Block();

};

int main()
{
	Block a{};

	Block b{ a + 100 };



}

#pragma endregion



