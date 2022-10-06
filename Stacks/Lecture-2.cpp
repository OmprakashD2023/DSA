//* Balanced Parenthesis
#include <bits/stdc++.h>
using namespace std;
class MyStack
{
private:
	char *arr;
	int next;
	int capacity;

public:
	MyStack(int c)
	{
		arr = new char[c];
		capacity = c;
		next = -1;
	}

	void push(char x)
	{
		if (next == capacity - 1)
		{
			cout << "Stack overflow" << endl;
			return;
		}
		/*
			T *newarr = new T[2*capacity];
			capacity = 2*capacity;
			for(int i=0; i<capacity; i++){
				newarr[i] = arr[i];
			}
			delete[] arr;
			arr = newarr;
			next++;
			arr[next]=x;
		*/
		next++;
		arr[next] = x;
	}

	char pop()
	{
		if (next == -1)
		{
			cout << "Stack underflow" << endl;
			return 'A';
		}
		char res = arr[next];
		next--;
		return res;
	}

	char top()
	{
		if (next == -1)
		{
			cout << "Undefined Behavior" << endl;
			return 'A';
		}
		return arr[next];
	}

	int size()
	{
		return next + 1;
	}

	bool isEmpty()
	{
		return (next == -1);
	}
};

bool match(char a, char b)
{
	return (a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}');
}

bool isBalanced(string str)
{
	MyStack s = MyStack(str.length());
	for (char x : str)
	{
		if (x == '{' || x == '(' || x == '[')
		{
			s.push(x);
		}
		else
		{
			if (s.isEmpty() == true)
			{
				return false;
			}
			if (match(s.top(), x) == false)
			{
				return false;
			}
			else
				s.pop();
		}
	}
	return s.isEmpty() == true;
}

int main()
{
	string s;
	cout << "Enter the sequence : ";
	cin >> s;
	if (isBalanced(s))
		cout << "True" << endl;
	else
		cout << "False" << endl;
	return 0;
}