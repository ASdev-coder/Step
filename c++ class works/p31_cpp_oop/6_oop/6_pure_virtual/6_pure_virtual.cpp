#include <iostream>


#pragma region Pure virtual

//// abstract class
//// нельзя создавать объекты
//class Parent
//{
//public:
//    virtual void f1()
//    {
//        std::cout << "Parent::f1()\n";
//    }
//
//    virtual void f2() = 0;              // Чистая виртуальная ф-ция (абстрактная)
//
//    // void f3() = 0;                      // ERROR
//};
//
//// Дефолтная реализация чистой виртуальной ф-ции
//void Parent::f2()
//{
//    std::cout << "default action\n";
//    std::cout << "default action\n";
//    std::cout << "default action\n";
//    std::cout << "default action\n";
//}
//
//class Child : public Parent
//{
//public:
//    virtual void f1() override
//    {
//        std::cout << "Child::f1()\n";
//    }
//    virtual void f2() override
//    {
//        Parent::f2();
//        std::cout << "Child::f2()\n";
//    }
//};
//
//
//
//int main()
//{
//    //Parent* a = new Parent{};       // ERROR
//    //a->f1();
//    //a->f2();
//
//    Parent* b = new Child{};
//    b->f1();
//    b->f2();
//}

#pragma endregion


#pragma region Example

//enum Mode
//{
//	ZIP,
//	RAR,
//};
//
//class Archiver
//{
//private:
//	Mode mode;
//public:
//	Archiver(Mode mode = Mode::ZIP):
//		mode{mode}
//	{}
//
//	virtual void setMode(Mode mode)
//	{
//		this->mode = mode;
//	}
//
//	virtual void compress() = 0;
//
//	virtual void decompress() = 0;
//};
//
//
//class ZipArchiver: public Archiver
//{
//public:
//	ZipArchiver() :
//		Archiver{ Mode::ZIP }
//	{}
//
//	virtual void compress() override
//	{
//		std::cout << "ZipArchiver::compress()\n";
//	}
//
//	virtual void decompress() override
//	{
//		std::cout << "ZipArchiver::decompress()\n";
//	}
//};
//
//class RarArchiver: public Archiver
//{
//public:
//	RarArchiver():
//		Archiver{ Mode::RAR }
//	{}
//
//	virtual void compress() override
//	{
//		std::cout << "RarArchiver::compress()\n";
//	}
//
//	virtual void decompress() override
//	{
//		std::cout << "RarArchiver::decompress()\n";
//	}
//};
//
//int main()
//{
//
//	Archiver* a = new ZipArchiver{};
//	a->compress();
//
//	a = new RarArchiver{};
//	a->compress();
//
//
//}


#pragma endregion


#pragma region Интерфейсный класс (интерфейс, контракт)
// абстрактный класс без полей (как правило) и содержащий только ЧВФ

class ILogger
{
public:
	virtual void save() = 0;
	virtual int getState() = 0;

	virtual ~ILogger() {}
};

class TelegramLogger: public ILogger
{
	virtual void save() override
	{
		std::cout << "Telegram SAVE\n";
	}
	virtual int getState() override
	{
		return 100;
	}
};

class FileLogger: public ILogger
{
	virtual void save() override
	{
		std::cout << "File SAVE\n";
	}
	virtual int getState() override
	{
		return 500;
	}
};



void execute(ILogger* logger)
{
	logger->save();
}

int main()
{
	execute(new TelegramLogger{});

}







#pragma endregion





