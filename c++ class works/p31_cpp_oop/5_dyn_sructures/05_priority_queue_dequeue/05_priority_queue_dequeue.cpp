#include <iostream>

enum Priority
{
    LOW = 0,
    NORMAL = 1,
    HIGH = 2,
};


// === T ===
// 1. default ctor
// 2. copy ctor
// 3. dtor
// 4. operator<<


// TODO: specialization for pointers (where T is pointer)
template<class T>
class QueueItem
{
private:
    static const int DEFAULT_PRIORITY = 0;

    T val;
    int priority;

public:
    QueueItem<T>():
        val{ T{} },
        priority{ QueueItem<T>::DEFAULT_PRIORITY }
    {}

    QueueItem<T>(const T& val, int priority):
        val{ val },
        priority{ priority }
    {}

    int getPriority() const
    {
        return this->priority;
    }

    const T& getValue() const
    {
        return this->val;
    }

    friend std::ostream& operator<<(std::ostream& out, const QueueItem<T>& obj)
    {
        out << obj.val << '(' << obj.priority << ") ";

        return out;
    }
};

template<class T, int step = 10>
class Queue
{
private:
    static const int NO_INDEX = -1;

    int count;
    QueueItem<T>** arr;
    int capacity;
    int priorityCount;
    int* prs;

    void resetPrs()
    {
        for (int i{}; i < this->priorityCount; ++i)
            prs[i] = Queue<T>::NO_INDEX;
    }
    void resetState()
    {
        this->count = 0;
        this->arr = nullptr;
        this->capacity = 0;
        this->priorityCount = 0;
        this->prs = nullptr;
    }
    void clearMemeory(bool withResetState = false)
    {
        if (this->arr != nullptr)
        {
            for (int i{}; i < this->count; ++i)
            {
                if (this->arr[i] != nullptr)
                    delete this->arr[i];
            }

            delete[] this->arr;
        }

        if (this->prs != nullptr)
            delete[] this->prs;

        if (withResetState)
            this->resetState();
    }
    bool isNotAllocated()
    {
        return this->arr == nullptr;
    }
    bool isFull()
    {
        return this->count == this->capacity;
    }
    void reallocateMemory()
    {
        if (this->isNotAllocated())
        {
            this->arr = new QueueItem<T>*[step] {};
            this->capacity = step;

            return;
        }

        this->capacity += step;

        QueueItem<T>** temp = new QueueItem<T>*[this->capacity];

        for (int i{}; i < this->count; ++i)
            temp[i] = this->arr[i];

        delete[] this->arr;

        this->arr = temp;
    }

    int findTargetPriority()
    {
        int targetPriority = Queue<T>::NO_INDEX;        // -1

        for (int i{ this->priorityCount - 1 }; i >= 0; --i)
        {
            if (this->prs[i] != Queue<T>::NO_INDEX)
            {
                targetPriority = i;
                break;
            }
        }

        return targetPriority;
    }

    void updatePrs(int targetIndex, int targetPriority)
    {
        for (int i{}; i < this->priorityCount; ++i)
        {
            if (this->prs[i] > targetIndex)
                --this->prs[i];
        }

        this->prs[targetPriority] = -1;

        for (int i{ targetIndex }; i < this->count; ++i)
        {
            if ((this->arr[i])->getPriority() == targetPriority)
            {
                this->prs[targetPriority] = i;

                return;
            }
        }
    }

public:
    Queue(int priorityCount = 3):
        count{ 0 },
        arr { nullptr },
        capacity { 0 },
        priorityCount{ priorityCount },
        prs{ new int[priorityCount] }
    {
        this->resetPrs();
    }

    Queue(const Queue<T>& obj):
        count{ obj.count },
        arr{ new QueueItem<T>*[obj.capacity]},
        capacity{ obj.capacity },
        priorityCount{ obj.priorityCount },
        prs{ new int[obj.priorityCount] }
    {
        for (int i{}; i < this->count; ++i)
            this->arr[i] = new QueueItem<T>{ *(obj.arr[i]) };

        for (int i{}; i < this->priorityCount; ++i)
            this->prs[i] = obj.prs[i];
    }

    Queue(Queue<T>&& obj):
        count{ obj.count },
        arr{ obj.arr },
        capacity{ obj.capacity },
        priorityCount{ obj.priorityCount },
        prs{ obj.prs }
    {
        obj.arr = nullptr;
        obj.prs = nullptr;
    }

    Queue<T>& operator=(const Queue<T>& obj)
    {
        if (this == &obj)
            return *this;

        this->clearMemeory();

        this->count = obj.count;
        this->arr = new QueueItem<T>*[obj.capacity];
        this->capacity = obj.capacity;
        this->priorityCount = obj.priorityCount;
        this->prs = new int[obj.priorityCount];

        for (int i{}; i < this->count; ++i)
            this->arr[i] = new QueueItem<T>{ *(obj.arr[i]) };

        for (int i{}; i < this->priorityCount; ++i)
            this->prs[i] = obj.prs[i];

        return *this;
    }

    Queue<T>& operator=(Queue<T>&& obj)
    {
        this->clearMemeory();

        this->count = obj.count;
        this->arr = obj.arr;
        this->capacity = obj.capacity;
        this->priorityCount = obj.priorityCount;
        this->prs = obj.prs;

        obj.arr = nullptr;
        obj.prs = nullptr;

        return *this;
    }

    void enqueue(const T& val, int priority)
    {
        if (this->isNotAllocated() || this->isFull())
            this->reallocateMemory();

        this->arr[this->count] = new QueueItem<T>{ val, priority };

        if (this->prs[priority] == -1)
            this->prs[priority] = this->count;

        ++this->count;
    }

    T dequeue()
    {
        if (this->isEmpty())
        {
            // TODO: throw exception
            return T{};
        }

        int targetPriority = this->findTargetPriority();

        int targetIndex = this->prs[targetPriority];

        T val = this->arr[targetIndex]->getValue();

        delete this->arr[targetIndex];

        for (int i{ targetIndex }; i < this->count - 1; ++i)
            this->arr[i] = this->arr[i + 1];

        --this->count;
        
        this->updatePrs(targetIndex, targetPriority);

        return val;
    }



    bool isEmpty() const
    {
        return this->count == 0;
    }

    int getCount() const
    {
        return this->count;
    }

    int getCapacity() const
    {
        return this->capacity;
    }

    void show() const
    {
        std::cout << "prs: ";
        for (int i{}; i < this->priorityCount; ++i)
            std::cout << this->prs[i] << ' ';
        std::cout << '\n';

        std::cout << "capacity = " << this->capacity << '\n';
        std::cout << "count = " << this->count << '\n';
        std::cout << "arr:" << '\n';
        for (int i{}; i < this->count; ++i)
            std::cout << '\t' << * (this->arr[i]) << '\n';

        std::cout << "\n\n";
        
    }

    ~Queue()
    {
        this->clearMemeory();
    }
};







int main()
{
    /*Queue<int> q;
    q.enqueue(10, Priority::LOW);
    q.enqueue(20, Priority::HIGH);
    q.enqueue(30, Priority::NORMAL);
    q.enqueue(40, Priority::LOW);
    q.enqueue(50, Priority::NORMAL);
    q.enqueue(60, Priority::HIGH);

    q.show();

    std::cout << "DEQUEUE ==> " << q.dequeue() << "\n\n";
    q.show();

    std::cout << "DEQUEUE ==> " << q.dequeue() << "\n\n";
    q.show();

    std::cout << "DEQUEUE ==> " << q.dequeue() << "\n\n";
    q.show();

    std::cout << "DEQUEUE ==> " << q.dequeue() << "\n\n";
    q.show();*/



    Queue<int> q;
    q.show();

    q.enqueue(10, Priority::NORMAL);
    q.show();

    q.enqueue(20, Priority::NORMAL);
    q.show();

    q.enqueue(30, Priority::HIGH);
    q.show();
}

