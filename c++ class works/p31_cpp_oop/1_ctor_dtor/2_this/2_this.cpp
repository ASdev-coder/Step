#include <iostream>



//class Container
//{
//private:
//    int val;
//
//public:
//    Container(int val)
//    {
//        this->val = val;
//    }
//
//    void test()                     // test(Container* const this)
//    {
//        std::cout << "Val: " << this->val << '\n';
//    }
//};
//
//
//int main()
//{
//    Container a{ 34 };
//    Container b{ 54 };
//
//    a.test();                       // test(&a);
//    b.test();
//}



//class Role
//{
//
//};
//
//class User
//{
//private:
//	int id;
//	std::string email;
//	std::string password;
//	Role role;
//
//public:
//	User(int id, std::string& email, std::string& password, Role& role) :
//		id{ id }
//	{
//		this->email = email;
//		this->password = password;
//		this->role = role;
//	}
//};




#pragma region Chaining

//class Container
//{
//private:
//	int val;
//
//public:
//	Container(int val):
//		val{val}
//	{}
//
//	Container* add(int val)
//	{
//		this->val += val;
//
//		return this;
//	}
//
//	Container* sub(int val)
//	{
//		this->val -= val;
//
//		return this;
//	}
//
//	Container* mul(int val)
//	{
//		this->val *= val;
//
//		return this;
//	}
//
//	void show()
//	{
//		std::cout << "val: " << this->val << '\n';
//	}
//};
//
//int main()
//{
//	Container a{ 0 };
//	a.add(10);
//	a.mul(3);
//	a.sub(15);
//	a.show();
//
//	Container b{ 0 };
//	b.add(10)->mul(3)->sub(15)->show();
//}




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

	void show()
	{
		std::cout << this << '\n';
	}
};


int main()
{
	Point a{ 3, 4 };

	std::cout << &a << '\n';

	Point* ptr{ &a };
	std::cout << ptr << '\n';

	a.show();


}

#pragma endregion



