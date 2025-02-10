#include <iostream>
// OOП
// -------------
// Наследование
// Инкапсуляция
// Полиморфизм
// Абстакций

// Принципы хорошей разработки
// ---------------------------
// 1. Переиспользование кода
// 2. Расширяемость

// Правила хорошего кода (основные)
// --------------------------------
// 1. Инкапсуляция изменений
// 2. Программирование на интерфейсах
    //class ILogger {};
    //class FileLogger : public ILogger{};
    //class TelegramLogger : public ILogger {};
    //
    //class Application
    //{
    //    ILogger* logger;
    //};
// 3. Композиция(агрегация) лучше наследования

// Принципы SOLID (еще: DRY/KISS...)
// === S - single responsibility principle
// :-(((
//class User {};
//class UserManager
//{
//    User createUser(const std::string& email)
//    {}
//    void saveUserToDb(User& user)
//    {}
//    void sendEmailToUser(User& user)
//    {}
//};

// :-)))
//class UserManager {};
//class UserRepository {};
//class Notifier{};

// === O - Open/Closed principle
//#include <vector>
//class IShape
//{
//public:
//    virtual double getArea() = 0;
//};
//class Rectangle : public IShape
//{
//public:
//    virtual double getArea() override
//    {
//        return 100;
//    }
//};
//class Circle : public IShape
//{
//public:
//    virtual double getArea() override
//    {
//        return 150.1;
//    }
//};
//class Triangle : public IShape
//{
//    ///
//};
//
//class AreaCalculator
//{
//public:
//    double calcTotlaAreas(std::vector<IShape*> shapes)
//    {
//        double sum = 0;
//        for (auto s : shapes)
//            sum += s->getArea();
//        return sum;
//    }
//};

// === L - Liskov Substitution Principle
// :-(((
//class IBird 
//{
//public:
//    virtual void fly() = 0;
//};
//
//class Eagle : public IBird
//{
//    virtual void fly() override
//    {
//        // fly
//    }
//};
//class Penguin : public IBird
//{
//    virtual void fly() override
//    {
//        // don't fly
//    }
//};

// :-)))
//class IBird 
//{
//public:
//    virtual void move() = 0;
//};
//class FlyingBird : public IBird
//{
//protected:
//    virtual void fly() {}
//public:
//    virtual void move() override
//    {
//        this->fly();
//    }
//};
//class SwimmingBird : public IBird
//{
//protected:
//    virtual void swim() {}
//public:
//    virtual void move() override
//    {
//        this->swim();
//    }
//};
//class Eagle : public FlyingBird
//{
//    virtual void fly() override
//    {
//        // fly
//    }
//};
//class Penguin : public SwimmingBird
//{
//protected:
//    virtual void swim() override 
//    {
//        // swim
//    }
//};
//
//
//int main()
//{
//    std::cout << "Hello World!\n";
//}



// === I - Interface segregation principle ===
// :-(((
//class ILogger
//{
//public:
//    virtual void log() = 0;
//    virtual void sendNotification() = 0;
//    virtual void writeToDB() = 0;
//};
//
//class FileLogger : public ILogger
//{
//    virtual void log() override
//    {}
//    virtual void sendNotification() override
//    {}
//    virtual void writeToDB() override
//    {
//        throw new std::exception("Not emplemented");
//    }
//};

//class ILogger
//{
//public:
//    virtual void log() = 0;
//};
//class INotifier
//{
//public:
//    virtual void sendNotification() = 0;
//};
//class IDbWorker
//{
//    virtual void writeToDB() = 0;
//};
//
//class FileLogger : public ILogger, INotifier
//{
//    virtual void log() override
//    {}
//    virtual void sendNotification() override
//    {}
//};
//class DbLOgger : public ILogger, IDbWorker
//{
//    virtual void log() override
//    {}
//    virtual void writeToDB() override
//    {}
//};


// === D --> Dependency Inversion Principle ===
