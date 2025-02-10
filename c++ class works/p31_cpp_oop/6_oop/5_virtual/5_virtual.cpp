#include <iostream>

#pragma region Intro
//class Parent
//{
//protected:
//    int val;
//public:
//    Parent(int val):
//        val {val}
//    {}
//    int getVal() const
//    {
//        return this->val;
//    }
//};
//
//class Child : public Parent
//{
//private:
//    int cVal{};
//public:
//    Child(int val):
//        Parent{val}
//    {}
//    int getNegative()
//    {
//        return -this->val;
//    }
//};
//
//class Grandson : public Child
//{
//private:
//    int gVal{};
//public:
//    Grandson(int val):
//        Child{val}
//    {}
//    int getRandom()
//    {
//        return 134;
//    }
//};
//
//
//
//
//int main()
//{
//    /*Child c{ 12 };
//    std::cout << c.getVal() << '\n';
//    std::cout << c.getNegative() << '\n';*/
//
//
//    //Child* c = new Child{ 12 };
//    //std::cout << c->getVal() << '\n';
//    //std::cout << c->getNegative() << '\n';
//
//    //Parent* p = c;
//    //std::cout << p->getVal() << '\n';
//    //// std::cout << p->getNegative() << '\n';  // ERROR
//
//
//
//    //Grandson* g = new Grandson{ 12 };
//    //std::cout << g->getRandom() << 'n';
//    //std::cout << g->getNegative() << 'n';
//    //std::cout << g->getVal() << 'n';
//
//    //Child* c = g;
//    //// std::cout << c->getRandom() << 'n';         // ERROR
//    //std::cout << c->getNegative() << 'n';
//    //std::cout << c->getVal() << 'n';
//
//    //Parent* p = g;
//    //// std::cout << p->getRandom() << 'n';          // ERROR
//    //// std::cout << p->getNegative() << 'n';        // ERROR
//    //std::cout << p->getVal() << 'n';
//
//
//    // ERROR
//    /*Parent p{ 34 };
//    Child* c = &p;*/
//
//}

#pragma endregion


#pragma region Objects array

//class Unit
//{
//private:
//	int hp;
//public:
//	Unit(int hp):
//		hp{hp}
//	{}
//	void attack()
//	{
//		std::cout << "Unit attack()\n";
//	}
//};
//
//class Archer : public Unit
//{
//public:
//	Archer(int hp):
//		Unit{hp}
//	{}
//	void attack()
//	{
//		std::cout << "Archer attack()\n";
//	}
//};
//
//class Warrior : public Unit
//{
//public:
//	Warrior(int hp) :
//		Unit{ hp }
//	{}
//	void attack()
//	{
//		std::cout << "Warrior attack()\n";
//	}
//};
//
//int main()
//{
//	Unit** units = new Unit*[4]
//	{
//			new Archer{100},
//			new Archer{110},
//			new Warrior{150},
//			new Warrior{170},
//	};
//
//	for (int i{}; i < 4; ++i)
//		units[i]->attack();
//}

#pragma endregion


#pragma region Разминка
//class Unit
//{
//private:
//	int id;
//public:
//	Unit(int id) :
//		id{ id }
//	{}
//};
//
//class Archer : public Unit
//{
//private:
//	int hp;
//public:
//	Archer(int id, int hp) :
//		Unit{ id },
//		hp{ hp }
//	{}
//};
//
//int main()
//{
//	Archer a{ 101, 150 };
//
//	std::cout << &a << '\n';
//
//	/*int* ptr = &a;
//	std::cout << ptr[0] << ' ' << ptr[1] << '\n';*/
//
//	std::cout << "test";
//}
#pragma endregion


#pragma region Virtual

//class Unit
//{
//private:
//	int hp;
//public:
//	Unit(int hp):
//		hp{hp}
//	{}
//	virtual void attack()
//	{
//		std::cout << "Unit attack()\n";
//	}
//};
//
//class Archer : public Unit
//{
//public:
//	Archer(int hp):
//		Unit{hp}
//	{}
//	void attack()
//	{
//		std::cout << "Archer attack()\n";
//	}
//};
//
//class Warrior : public Unit
//{
//public:
//	Warrior(int hp) :
//		Unit{ hp }
//	{}
//	void attack()
//	{
//		std::cout << "Warrior attack()\n";
//	}
//};
//
//int main()
//{
//	Unit** units = new Unit*[4]
//	{
//			new Archer{100},
//			new Archer{110},
//			new Warrior{150},
//			new Warrior{170},
//	};
//
//	for (int i{}; i < 4; ++i)
//		units[i]->attack();
//}






//class A
//{
//public:
//	void getString()
//	{
//		std::cout << "String from A\n";
//	}
//};
//class B: public A
//{
//public:
//	void getString()
//	{
//		std::cout << "String from B\n";
//	}
//};
//class C: public B
//{
//public:
//	virtual void getString()
//	{
//		std::cout << "String from C\n";
//	}
//};
//class D: public C
//{
//public:
//	virtual void getString() override
//	{
//		std::cout << "String from D\n";
//	}
//};
//class E: public D
//{
//public:
//	virtual void getString() override
//	{
//		std::cout << "String from E\n";
//	}
//};
//
//
//int main()
//{
//	/*A* a = new E{};
//	a->getString();*/
//
//	/*C* c = new E{};
//	c->getString();*/
//
//	C* b = new E{};
//	b->getString();
//}







//class A
//{
//public:
//	void getString()
//	{
//		std::cout << "String from A\n";
//	}
//};
//class B: public A
//{
//public:
//	void getString()
//	{
//		std::cout << "String from B\n";
//	}
//};
//class C: public B
//{
//public:
//	virtual void getString()
//	{
//		std::cout << "String from C\n";
//	}
//};
//class D: public C
//{
//public:
//	virtual void getString() override final
//	{
//		std::cout << "String from D\n";
//	}
//};
//class E: public D
//{
//public:
//	virtual void getString() override			// ERRROR
//	{
//		std::cout << "String from E\n";
//	}
//};
//	
//	
//int main()
//{
//	
//}

#pragma endregion


#pragma region Ковариантный тип возврата

//class Parent
//{
//public:
//	virtual Parent* getPtr()
//	{
//		return this;
//	}
//	void showInfo()
//	{
//		std::cout << "From Parent\n";
//	}
//};
//
//class Child : public Parent
//{
//public:
//	virtual Child* getPtr() override
//	{
//		return this;
//	}
//	void showInfo()
//	{
//		std::cout << "From Child\n";
//	}
//};
//
//
//int main()
//{
//	Child c;
//	Parent* p = &c;
//
//	c.getPtr()->showInfo();
//	p->getPtr()->showInfo();
//}

#pragma endregion


#pragma region this для памяти

//class Box
//{
//public:
//	Box* getThis()			// Box* getThis(Box* const this)
//	{
//		return this;
//	}
//};
//
//int main()
//{
//	Box b;
//	std::cout << &b << '\n';
//	std::cout << b.getThis() << '\n';
//}

#pragma endregion


#pragma region Виртуальные деструкторы

//class Parent
//{
//public:
//
//	virtual ~Parent()
//	{
//		std::cout << "Parent dctor\n";
//	}
//};
//
//class Child : public Parent
//{
//private:
//	int count;
//	int* arr;
//
//public:
//	Child(int count):
//		count{count},
//		arr{new int[count]}
//	{}
//
//	virtual ~Child()
//	{
//		if (this->arr != nullptr)
//			delete[] this->arr;
//
//		std::cout << "Child dctor\n";
//	}
//};
//
//int main()
//{
//	/*Child* c = new Child{ 10 };
//	delete c;*/
//
//	Parent* p = new Child{ 10 };
//	delete p;
//}

#pragma endregion


#pragma region Игнорирование виртуальных ф-ций

//class A
//{
//public:
//	virtual void getString()
//	{
//		std::cout << "String from A\n";
//	}
//};
//class B: public A
//{
//public:
//	virtual void getString() override
//	{
//		std::cout << "String from B\n";
//	}
//};
//
//int main()
//{
//	A* a = new B{};
//	a->A::getString();
//
//
//}

#pragma endregion


#pragma region Указатель на ф-цию

//typedef int(*FuncPtr)(int, int);
//
//
//void render1()
//{
//	std::cout << "RENDER1\n";
//}
//void render2()
//{
//	std::cout << "RENDER1\n";
//}
//
//int add(int a, int b)
//{
//	return a + b;
//}
//
//
//int main()
//{
//	std::cout << render1 << '\n';
//
//	void(*fPtr1)() = render1;
//	void(*fPtr2)() = render2;
//	int(*fPtr3)(int, int) = add;
//
//	fPtr1();
//
//	
//	FuncPtr a{ add };
//	std::cout << a(3, 4);
//
//}

#pragma endregion



#pragma region Virtual table

class Parent
{
public:
	virtual void f1() { std::cout << "Parent::f1()\n"; }
	virtual void f2() { std::cout << "Parent::f2()\n"; }
};

class Child1 : public Parent
{
public:
	virtual void f1() override { std::cout << "Child1::f1()\n"; }
};

class Child2 : public Parent
{
public:
	virtual void f2() override { std::cout << "Child2::f2()\n"; }
};


int main()
{
	Parent* a = new Child1{};
	a->f2();
	a->f1();

	Child1 c;
	std::cout << sizeof(c);

	/*for (int i{}; i < 1000; ++i)
		Parent* a = new Child1{};*/
}

#pragma endregion




