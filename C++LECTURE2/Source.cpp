#include <iostream>

using namespace std;

template <typename T>
class Vector
{
private:
    int size;
    int capacity;
    T * container;
public:
    Vector()
    {
        size = 0;
        capacity = 0;
        container = nullptr;
    }
    
    void Resize(int newsize)
    {
        capacity = newsize;

        T* newContainer = new T[capacity];

        for (int i = 0; i < capacity ; i++)
        {
            newContainer[i] = NULL;
        }

        for (int i = 0; i < size; i++)
        {
            newContainer[i] = container[i];
        }

        if (container != nullptr)
        {
            delete[] container;
        }

        container = newContainer;

    }

    void PushBack(T data)
    {
        if (capacity <= 0)
        {
            Resize(1);
        }
        else if (size >= capacity)
        {
            Resize(capacity * 2);
        }
        container[size++] = data;
    }

    int& Size()
    {
        return size;
    }

    ~Vector()
    {
        if (container != nullptr)
        {
            delete[] container;
        }
    }

};

int main()
{
    Vector<int> vector;

    vector.PushBack(10);
    vector.PushBack(20);
    vector.PushBack(30);

    for (int i = 0; i < vector.Size(); i++)
    {
        cout << vector[i] << endl;
    }


    return 0;
}