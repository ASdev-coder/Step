#include <iostream>


class Parent
{
public:
    void render()
    {
        std::cout << "Parent render()\n";
    }
};

class Child : public Parent
{
public:
    void render()
    {
        //Parent::render();

        // this->render();

        

        Parent p;
        p.render();

        std::cout << "Child render()\n";
    }
};



int main()
{
    /*Parent p;
    p.render();*/

    Child c;
    c.render();
}


