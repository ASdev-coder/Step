#include <iostream>


#pragma region Обрезка

//class Parent
//{
//private:
//    int val;
//
//public:
//    Parent(int val) :
//        val{ val }
//    {}
//    int getVal()
//    {
//        return this->val;
//    }
//    virtual std::string getTitle()
//    {
//        return "Parent";
//    }
//};
//
//class Child : public Parent
//{
//public:
//    Child(int val) :
//        Parent{ val }
//    {}
//    virtual std::string getTitle() override
//    {
//        return "Child";
//    }
//};
//
//
//void func(Parent p)
//{
//    std::cout << p.getTitle() << '\n';
//}
//
//int main()
//{
//    Child child{ 34 };
//    std::cout << "title: " << child.getTitle() << " val: " << child.getVal() << '\n';
//
//    Parent* p = &child;
//    // Parent* p = new Child{ 34 };
//    std::cout << "title: " << p->getTitle() << " val: " << p->getVal() << '\n';
//
//    Parent pObj{ child };       // ОБРЕЗКА ОБЪЕКТА
//    std::cout << "title: " << pObj.getTitle() << " val: " << pObj.getVal() << '\n';
//
//    Child c{ 34 };
//    func(c);
//}

#pragma endregion


#pragma region Type casting

//int main()
//{
//	//int a = 45;
//	//int b = 6;
//	//// double res = (double)a / b;
//	//double res = static_cast<double>(a) / b;
//
//	//int val = 4500;
//	//std::cout << static_cast<char>(val);
//}

//class Parent
//{
//private:
//	int val;
//public:
//	Parent(int val) :
//		val{ val }
//	{}
//	virtual ~Parent() {}
//};
//
//class Child : public Parent
//{
//private:
//	std::string email;
//
//public:
//	Child(int val, const std::string& email) :
//		Parent{ val },
//		email{email}
//	{}
//
//	std::string getEmail() const
//	{
//		return this->email;
//	}
//};
//
//int main()
//{
//	Parent* p = new Child{ 150, "vasia@mail.com" };
//
//	// Child* c = p;		// ERROR
//
//	Child* c = dynamic_cast<Child*>(p);
//	if (c != nullptr)
//		c->getEmail();
//}

#pragma endregion


