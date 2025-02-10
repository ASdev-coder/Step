#include <iostream>

//class DbConnection
//{
//private:
//    static DbConnection* instance;
//
//    DbConnection()
//    {}
//
//public:
//    static DbConnection* getInctance()
//    {
//        if (DbConnection::instance == nullptr)
//            DbConnection::instance = new DbConnection();
//
//        return DbConnection::instance;
//    }
//
//    DbConnection(const DbConnection&) = delete;
//    DbConnection& operator=(const DbConnection&) = delete;
//
//    void connect()
//    {
//        std::cout << "connect()\n";
//    }
//};
//
//DbConnection* DbConnection::instance = nullptr;
//
//
//int main()
//{
//    // DbConnection* a = new DbConnection{};   // ERROR
//
//    DbConnection* conn1 = DbConnection::getInctance();
//    DbConnection* conn2 = DbConnection::getInctance();
//    DbConnection* conn3 = DbConnection::getInctance();
//
//    std::cout << conn1 << '\n';
//    std::cout << conn2 << '\n';
//    std::cout << conn3 << '\n';
//
//    // DbConnection* hackDb = new DbConnection{ *conn1 };  // :-(
//    // std::cout << hackDb << '\n';
//}



//class IRenderable
//{
//public:
//	virtual std::string render() = 0;
//};
//
//class Unit: public IRenderable
//{
//public:
//	virtual std::string render() override
//	{
//		return "Unit render()\n";
//	}
//};
//
//class Tree: public IRenderable
//{
//public:
//	virtual std::string render() override
//	{
//		return "Tree render()\n";
//	}
//};
//
//class Renderer
//{
//private:
//	static Renderer* instance;
//	Renderer()
//	{}
//public:
//	static Renderer* getInstance()
//	{
//		if (Renderer::instance == nullptr)
//			Renderer::instance = new Renderer{};
//
//		return Renderer::instance;
//	}
//	Renderer(const Renderer&) = delete;
//	Renderer& operator=(const Renderer&) = delete;
//	
//	void Render(IRenderable* obj)
//	{
//		std::cout << obj->render() << '\n';
//	}
//};
//
//Renderer* Renderer::instance = nullptr;
//
//int main()
//{
//	Renderer* renderer1 = Renderer::getInstance();
//	std::cout << renderer1 << '\n';
//	renderer1->Render(new Unit{});
//	//
//	//
//	Renderer* renderer2 = Renderer::getInstance();
//	std::cout << renderer2 << '\n';
//	renderer2->Render(new Tree{});
//}


