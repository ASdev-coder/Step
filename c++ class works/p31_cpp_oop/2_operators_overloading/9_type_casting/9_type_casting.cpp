#include <iostream>

//class Box
//{
//private:
//	int val;
//public:
//	explicit Box(int val):
//		val{val}
//	{}
//	int getVal()
//	{
//		return this->val;
//	}
//	void setVal(int val)
//	{
//		this->val = val;
//	}
//	operator int()
//	{
//		return this->val;
//	}
//
//};
//
//
//int main()
//{
//	Box a{ 34 };
//	Box b{ 17 };
//
//	int v = (int)a;
//
//	std::cout << (int)a + (int)b;
//}




#pragma region Task
// Создать классы Circle, Square (на плоскости)
// Предусмотреть возможность приведения одного типа в другой и наоборот


class Point;
class Circle;
class Square;


class Point
{
private:
	int x;
	int y;
public:
	Point(int x, int y):
		x{x},
		y{y}
	{}
	int getX() { return this->x; }
	int getY() { return this->y; }
	void render() const
	{
		std::cout << "(" << this->x << ';' << this->y << ")";
	}
};

class Square
{
private:
	Point p;
	int size;
public:
	explicit Square(const Point& p, int size);
	void render() const;
	operator Circle();
};

class Circle
{
private:
	Point center;
	int r;
public:
	explicit Circle(const Point& p, int r);
	void render() const;
	operator Square();
};

Circle::Circle(const Point& p, int r):
	center{p},
	r{r}
{}

void Circle::render() const
{
	std::cout << "Circle center: ";
	this->center.render();
	std::cout << " Radius = " << this->r << "\n\n";
}

Circle::operator Square()
{
	Point p{ this->center.getX() - this->r, this->center.getY() - this->r };

	return Square{ p, 2 * this->r };
}



#pragma endregion

Square::Square(const Point& p, int size):
	p{p},
	size{size}
{}

void Square::render() const
{
	std::cout << "Square corner: ";
	this->p.render();
	std::cout << " Size = " << this->size << "\n\n";
}

Square::operator Circle()
{
	int r = this->size / 2;
	Point center{ this->p.getX() + r, this->p.getY() + r };

	return Circle{ center, r };
}


void action(Circle a)
{
	a.render();
}

int main()
{
	/*Circle a{ {6, 8}, 3 };
	a.render();

	Square b{ Point{4, 4}, 4 };
	b.render();

	Circle c{ (Circle)b };
	c.render();

	Square d{ (Square)a };
	d.render();*/


	// ==== buns ==== :-))
	
	// action(Square{ Point{4, 4}, 4 });

	Square d{ Circle { {6, 8}, 3 } };
	d.render();
}
