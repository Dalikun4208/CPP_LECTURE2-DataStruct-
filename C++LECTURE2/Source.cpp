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
    struct Node
    {
        T data;
        Node* next;
        Node* previous;
    };
    Node* head;
    Node* tail;
public:
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
                head == nullptr;
                tail == nullptr;

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

    int& Size()
    {
        return size;
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

};


int main()
{

    DoubleLinkedList<int> List;

    List.PushBack(10);
    List.PushBack(20);
    List.PushBack(30);

    cout << "사이즈는 : " << List.Size() << endl;

    List.Show();

    return 0;
}

