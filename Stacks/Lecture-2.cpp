/*
  ? Linked List implementation of the stack
 */

#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
	int data;
	Node *next;

	Node(int data)
	{
		this->data = data;
	}
};

class MyStack
{
private:
	Node *head;
	int size;

public:
	MyStack()
	{
		head = NULL;
		size = 0;
	}

	void push(int x)
	{
		Node *temp = new Node(x);
		temp->next = head;
		head = temp;
		if(head == NULL)
			head = temp;
		size++;
	}

	int pop()
	{
		if (head == NULL)
		{
			cout << "Stack Underflow!" << endl;
			return -1;
		}
		int res = head->data;
		Node *temp = head;
		head = head->next;
		delete temp;
		size--;
		return res;
	}

	int sizeStack()
	{
		return size;
	}

	bool isEmpty()
	{
		return head == NULL;
	}

	int top()
	{
		if (head == NULL)
		{
			cout << "Stack is empty" << endl;
			return -1;
		}
		return head->data;
	}

	void print()
	{
		if (head == NULL)
		{
			cout << "Stack is empty" << endl;
			return;
		}
		Node *temp = head;
		while (temp!=NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << "\n";
	}
};
int main()
{
	MyStack stack = MyStack();
	int choice;
	cout << "Enter 1 to push an element into the stack.\nEnter 2 to pop an element from the stack.\nEnter 3 to print the size of the stack.\nEnter 4 to print the top of the stack.\nEnter 5 to print the stack." << endl;
	cin >> choice;
	do
	{
		if (choice == 1)
		{
			int x;
			cout << "Enter the data : ";
			cin >> x;
			stack.push(x);
		}
		else if (choice == 2)
		{
			cout << stack.pop() << endl;
		}
		else if (choice == 3)
		{
			cout << stack.sizeStack() << endl;
		}
		else if (choice == 4)
		{
			cout << stack.top() << endl;
		}
		else if (choice == 5)
		{
			stack.print();
		}
		else
		{
			cout << "Invalid choice" << endl;
		}
		cout << "Enter 1 to push an element into the stack.\nEnter 2 to pop an element from the stack.\nEnter 3 to print the size of the stack.\nEnter 4 to print the top of the stack.\nEnter 5 to print the stack." << endl;
		cin >> choice;
	}while(choice);
	return 0;
}