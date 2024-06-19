#include <iostream>

using namespace std;

#define SIZE 5
template <typename T>
class CircleQueue
{
private:
    int front;
    int rear;
    int size;
    T container[SIZE];
public:
    CircleQueue()
    {
        front = 0;
        rear = SIZE - 1;
        size = SIZE - 1;

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
            if (rear % SIZE == 0)
            {
                rear = rear - 1;
            }
            size++;
        }
        else
        {
            cout << "queue is full" << endl;
        }
    }

};

int main()
{

    CircleQueue<int> a;

    a.Push(10);


    return 0;
}