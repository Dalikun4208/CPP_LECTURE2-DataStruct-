#include <iostream>

using namespace std;

template <typename T>

class CircleLinkedList
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
	CircleLinkedList()
	{
		size = 0;
		head = nullptr;
	}

	void PushBack(T data)
	{
		Node* newnode = new Node;
		newnode->data = data;
		newnode->next = nullptr;

		if (head == nullptr)
		{
			head = newnode;
			newnode->next = head;
		}
		else 
		{
			newnode->next = head->next;
			head->next = newnode;
			head = newnode;
		}
		size++;
	}

	void PushFront(T data)
	{
		Node* newnode = new Node;
		newnode->data = data;
		newnode->next = nullptr;

		if (head == nullptr)
		{
			head = newnode;
			newnode->next = head;
		}
		else
		{
			newnode->next = head->next;
			head->next = newnode;
		}
		size++;
	}

	void PopFront()
	{
		Node* deletenode = new Node;
		deletenode->next = nullptr;

		if (size == 0)
		{
			cout << "List Is Empty" << endl;
		}
		else if (size == 1)
		{
			deletenode = head;
			head = nullptr;
			delete deletenode;
		} 
		else 
		{
			deletenode = head->next;
			head->next = deletenode->next;
			delete deletenode;
		}
		size--;
	}

	void PopBack()
	{
		Node* deletenode = new Node;
		Node* currentnode = new Node;
		deletenode->next = nullptr;
		currentnode->next = nullptr;

		if (size == 0)
		{
			cout << "List Is Empty" << endl;
		}
		else if (size == 1)
		{
			head = nullptr;
		}
		else
		{
			deletenode = head;
			currentnode = head;

			for (int i = 0; i < size - 1; i++)
			{
				currentnode = currentnode->next;
			}
			currentnode->next = head->next;
			head = currentnode;
			delete deletenode;
		}
		size--;
	}

	void Show()
	{
		if (head != nullptr)
		{
			Node* currentnode = new Node;
			currentnode = head->next;

			for (int i = 0; i < size; i++)
			{
				cout << currentnode->data << endl;
				currentnode = currentnode->next;
			}
		}
	}

};

int main()
{
	CircleLinkedList<int>  list;

	list.PushBack(10);
	list.PushBack(20);
	list.PushBack(30);
	list.PushFront(99);

	list.Show();

	cout << "----------------------------------" << endl;

	list.PopFront();
	list.Show();

	cout << "----------------------------------" << endl;

	list.PopBack();
	list.Show();

	

	return 0;
}