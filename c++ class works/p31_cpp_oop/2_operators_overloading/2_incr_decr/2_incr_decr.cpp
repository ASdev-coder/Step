#include <iostream>



//int main()
//{
//    int a{ 10 };
//    int b{ 100 };
//
//    std::cout << ++a << '\n';
//    std::cout << b++ << '\n';
//
//    std::cout << a << ' ' << b << '\n';
//
//}




//class Box // Значение val должно находиться в диапазоне [0;8]
//{
//private:
//	int val;
//
//public:
//	Box(int val = 0)
//	{
//		this->val = val > 8 || val < 0 ? 0 : val;
//	}
//	int getVal() const
//	{
//		return this->val;
//	}
//
//	// prefix increment
//	Box& operator++()
//	{
//		if (this->val == 8)
//			this->val = 0;
//		else
//			++this->val;
//
//		return *this;
//	}
//
//	// postfix increment
//	Box operator++(int)
//	{
//		//Box temp{ *this };
//		Box temp{ this->val };
//
//		++(*this);
//
//		return temp;
//	}
//
//	// prefix decrement
//	Box& operator--()
//	{
//		if (this->val == 0)
//			this->val = 8;
//		else
//			--this->val;
//
//		return *this;
//	}
//
//	// postfix decrement
//	Box operator--(int)
//	{
//		Box temp{ this->val };
//
//		--(*this);
//
//		return temp;
//	}
//
//	void show() const
//	{
//		std::cout << "VAL = " << this->val << '\n';
//	}
//};
//
//Box operator+(const Box& a, const Box& b)
//{
//	return Box{ a.getVal() + b.getVal() };
//}
//
//int main()
//{
//	/*Box a{ 10 };
//
//	++a;
//	a.show();*/
//
//
//	//Box a{ 5 };
//	//Box b{ a++ };
//	//b.show();			// 5
//	//a.show();			// 6
//
//
//	Box a{ 2 };
//	Box b{ 3 };
//
//	/*Box c{ ++a + b++ };
//	c.show();*/
//
//	Box c{ ++a + a++ };
//	c.show();
//
//
//	return 0;
//}






//class Container
//{
//private:
//	int count{};
//	int* arr{ nullptr };
//
//public:
//	Container(int count):
//		count{count},
//		arr{ new int[count] {} }
//	{}
//
//	Container(const Container& obj) :
//		count{ obj.count },
//		arr{ new int[obj.count] }
//	{
//		for (int i{}; i < this->count; ++i)
//			arr[i] = obj.arr[i];
//	}
//
//	Container& operator++()
//	{
//		if (this->arr != nullptr)
//			for (int i{}; i < this->count; ++i)
//				++this->arr[i];
//
//		return *this;
//	}
//
//	Container operator++(int)
//	{
//		Container tmp{ *this };
//
//		++(*this);
//
//		return tmp;
//	}
//
//	void show()
//	{
//		for (int i{}; i < this->count; ++i)
//			std::cout << this->arr[i] << ' ';
//		std::cout << "\n\n";
//	}
//
//	~Container()
//	{
//		if (this->arr != nullptr)
//			delete[] this->arr;
//	}
//
//};
//
//int main()
//{
//	Container a{ 10 };
//	++a;
//	a++;
//
//	a.show();
//	
//
//
//}





class Bober
{

};

class Stalevar
{

};

class Valenok
{

};


Valenok operator+(const Bober& a, const Stalevar& b)
{

}



