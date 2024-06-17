#include <iostream>

using namespace std;

#define SIZE 5;

template <typename T>

class Stack
{
private :
	int top;
	T container[5];
public:
	Stack()
	{
		top = -1;
		for (int i = 0; i < 5; i++)
		{
			container[i] = 0;
		}
	}

	void Push(T data)
	{
		if (top >= 5)
		{
			cout << "stack overflow" << endl;

		}
		else
		{
			container[++top] = data;
		}
	}

	void Pop()
	{
		if (Empty())
		{
			cout << "stack is empty" << endl;
		}
		else
		{
			top--;
		}
	}

	int& size()
	{
		return top;
	}

	T& Top()
	{
		return container[top];
	}

	bool Empty()
	{
		if (top <= -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

};

int main()
{
	Stack<int> stack;
	stack.Push(10);
	stack.Push(20);
	stack.Push(30);
	stack.Push(40);
	stack.Push(50);

	while (stack.Empty() == false)
	{
		cout << stack.Top() << endl;
		stack.Pop();
	}


	return 0;
}