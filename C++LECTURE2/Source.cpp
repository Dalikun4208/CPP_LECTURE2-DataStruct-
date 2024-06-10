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

};


int main()
{



    return 0;
}

