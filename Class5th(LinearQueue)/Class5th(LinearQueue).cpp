#include <iostream>

using namespace std;

#define SIZE 5

template <typename T>

class Linearqueue
{
private:
    int rear;
    int front;
    int size;
    T container[SIZE];
public:
    Linearqueue()
    {
        rear = 0;
        front = 0;
        size = 0;

        for (int i = 0; i < SIZE; i++)
        {
            container[i] = NULL;
        }

    }

    bool Empty()
    {
        if (rear == front)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void Push(T data)
    {
        if (size < SIZE)
        {
            container[rear] = data;
            rear++;
            size++;
        }
        else
        {
            cout << "queue is full" << endl;
        }

    }

    void Pop()
    {
        if (Empty())
        {
            cout << "queue is empty" << endl;
        }
        else
        {
            container[front] = NULL;
            front++;
            size--;
        }
    }

    T& Front()
    {
        return container[front];
    }

    T& Back()
    {
        return container[rear - 1];
    }

    void Size()
    {
        cout << "Size 의 값은 : " << size << endl;
    }

    void show()
    {
        for (int i = 0; SIZE > i; i++)
        {
            cout << container[i] << endl;
        }
    }

};

int main()
{
    Linearqueue<int> a;

    a.Push(10);
    a.Push(20);
    a.Push(30);
    a.Push(40);
    a.Push(50);

    a.show();
    a.Size();



    cout << "front는 : " << a.Front() << endl;
    cout << "back는 : " << a.Back() << endl;

    a.Pop();

    a.show();


    return 0;
}