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
class SingleLinkedList
{
private:
    int size;
    struct Node
    {
        T data;
        Node* next;
    };

    Node* head;

public:
    SingleLinkedList()
    {
        size = 0;
        head = nullptr;
    }

    void PushFront(T data)
    {
        if (head == nullptr)
        {
            head = new Node;
            head->data = data;
            head->next = nullptr;
        }
        else
        {
            Node* newNode = new Node;

            newNode->data = data;
            newNode->next = head;

            head = newNode;
        }
        size++;
    }

    void PopFront()
    {

        if (head == nullptr)
        {
            cout << "Linked List is Empty" << endl;
        }
        else
        {
            Node* deleteNode = head;

            head = deleteNode->next;

            delete deleteNode;

            size--;
        }

    }

    void PushBack(T data)
    {
        if (head == nullptr)
        {
            head = new Node;
            head->data = data;
            head->next = nullptr;
        }
        else
        {
            Node* currentNode = head;
            while (currentNode->next != nullptr)
            {
                currentNode = currentNode->next;
            }

            Node* newNode = new Node;

            currentNode->next = newNode;
            newNode->data = data;
            newNode->next = nullptr;
        }

        size++;

    }

    void PopBack()
    {

        if (head == nullptr)
        {
            cout << "Linked List is Empty" << endl;
        }
        else
        {
            Node* deleteNode = head;
            Node* previousNode;

            if (size == 1)
            {
                head = deleteNode->next;
                delete deleteNode;
            }
            else if (size > 1)
            {
                while (deleteNode->next != nullptr)
                {
                    previousNode = deleteNode;
                    deleteNode = deleteNode->next;
                }

                previousNode->next = nullptr;
                delete deleteNode;
            }
            size--;
        }

    }

    void Show()
    {
        Node* currentNode;

        currentNode = head;

        while (currentNode != nullptr)
        {
            cout << "값은 : " << currentNode->data << endl;
            currentNode = currentNode->next;
        }

    }

    ~SingleLinkedList()
    {
        if (head != nullptr)
        {

        }
    }

};


int main()
{

    SingleLinkedList<int> LinkList;

    LinkList.PushFront(30);
    LinkList.PushFront(20);
    LinkList.PushFront(10);
    LinkList.PushBack(0);
    LinkList.PushBack(-10);
    LinkList.PushBack(-20);

    //LinkList.PopFront();

    LinkList.Show();

    return 0;
}

