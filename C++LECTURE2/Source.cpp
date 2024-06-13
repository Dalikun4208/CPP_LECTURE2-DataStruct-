#include <iostream>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>

using namespace std;

template <typename T>
class DoubleLinkedList
{
private:
    int size;

    struct Node;

    Node* head;
    Node* tail;
public:

    struct Node
    {
        T data;
        Node* next;
        Node* previous;
    };

    DoubleLinkedList()
    {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    void PushBack(T data)
    {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
        newNode->previous = nullptr;

        if (tail == nullptr)
        {
            tail = newNode;
            head = tail;
        }
        else
        {
            tail->next = newNode;
            newNode->previous = tail;

            tail = newNode;

        }

        size++;

    }

    void PopBack()
    {
        if (tail == nullptr)
        {
            cout << "linked list is empty" << endl;
        }
        else 
        {
            Node* deleteNode = tail;
            if (head == nullptr)
            {
                head = nullptr;
                tail = nullptr;

                delete deleteNode;
            }
            else {
                tail->previous->next = nullptr;
                tail = tail->previous;

                delete deleteNode;
            }
            size--;
        }
    }

    void PushFront(T data)
    {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
        newNode->previous = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            head->previous = newNode;
            newNode->next = head;

            head = newNode;
        }
        size++;
    }

    void PopFront()
    {
        if (head == nullptr)
        {
            cout << "linked list is empty" << endl;
        }
        else
        {
            Node* deleteNode = head;
            if (head == tail)
            {
                head = nullptr;
                tail = nullptr;

                delete deleteNode;
            }
            else {

                head->next->previous = nullptr;
                head = head->next;

                delete deleteNode;

            }
            size--;
        }
    }

    void Insert(Node* position, T data)
    {
        if (head == nullptr)
        {
            PushBack(data);
        }
        else
        {
            Node* previousNode = position;
            Node* nextNode = position->next;

            if (nextNode == nullptr)
            {
                PushBack(data);
            }
            else if (previousNode->previous == nullptr)
            {
                PushFront(data);
            }
            else
            {
                Node* newNode = new Node;

                newNode->data = data;

                previousNode->next = newNode;
                nextNode->previous = newNode;

                newNode->next = nextNode;
                newNode->previous = previousNode;

                size++;
            }
        }
    }

    int& Size()
    {
        return size;
    }

    Node* Begin()
    {
        return head;
    }

    void Show()
    {
        Node* currentNode = head;

        while (currentNode != nullptr)
        {
            cout << currentNode->data << endl;
            currentNode = currentNode->next;
        }
    }

    ~DoubleLinkedList()
    {
        while (head != nullptr)
        {
            PopFront();
        }
    }

};


int main()
{

    DoubleLinkedList<int> List;

    List.PushBack(10);
    List.PushBack(20);
    List.PushBack(30);

    cout << "사이즈는 : " << List.Size() << endl;

    List.Show();

    cout << "다음" << endl;

    List.PopBack();

    List.Show();

    cout << "다음"  << endl;

    List.PopFront();

    List.Show();

    cout << "다음" << endl;

    List.insert(List.Begin()->next, 99);

    List.Show();

    return 0;
}

