#include <iostream>


class Container
{
private:
    int count{};
    int* arr{ nullptr };

public:
    Container():
        count{},
        arr{nullptr}
    {}
    Container(int count):
        count{count},
        arr{new int[count]{}}
    {
        std::cout << "Container(int count)\n";
    }
    Container(const std::initializer_list<int>& list):
        Container( (int)list.size() )
    {
        int i{};
        for (int val : list)
        {
            arr[i] = val;
            ++i;
        }
        std::cout << "initializer_list\n";
    }

    void render()
    {
        for (int i{}; i < this->count; ++i)
            std::cout << this->arr[i] << ' ';
    }

};

int main()
{
    // int a[5]{ 4, 5, 6, 1, 2 };

    // int* b = new int[5] { 4, 5, 6, 1, 2 };

    // Container c{ 3, 4, 5, 6, 7, 1, 2, 3, 4 };
    //c.render();

    Container d{ 10 };
    d.render();
}

