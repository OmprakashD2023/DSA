/*
  Implementation of two stacks in an array
*/

#include <bits/stdc++.h>
using namespace std;

class TwoStack
{
private:
    int *arr;
    int capacity;
    int top1, top2;

public:
    TwoStack(int n)
    {
        this->capacity = n;
        this->top1 = -1;
        this->top2 = capacity - 1;
        this->arr = new int[n];
    }
    void push1(int x)
    {
        if (top1 < top2 - 1)
        {
            top1++;
            arr[top1] = x;
            return;
        }
        cout << "Stack overflow" << endl;
        return;
    }
    void push2(int x)
    {
        if (top1 < top2 - 1)
        {
            top2--;
            arr[top2] = x;
            return;
        }
        cout << "Stack overflow" << endl;
        return;
    }
    int pop1()
    {
        if (top1 < 0)
        {
            cout << "Stack underflow" << endl;
            return -9999;
        }
        int x = arr[top1];
        top1--;
        return x;
    }
    int pop2()
    {
        if (top2 < capacity)
        {
            cout << "Stack underflow" << endl;
            return -9999;
        }
        int x = arr[top2];
        top2++;
        return x;
    }
    int size1()
    {
        return (top1 + 1);
    }
    int size2()
    {
        return capacity - top2;
    }
};

int main()
{
    int n;
    cout << "Enter the number of elements in the array : ";
    cin >> n;
    int choice;
    TwoStack stack = TwoStack(n);
    cout << "Enter 1 to push an element into the stack 1.\nEnter 2 to push an element into the stack 2.\nEnter 3 to pop an the top element from the stack 1.\nEnter 4 to pop an the top element from the stack 2.\nEnter 5 to print the size of the stack 1.\nEnter 6 to print the size of the stack 2." << endl;
    cin >> choice;
    int x;
    while (choice)
    {
        if (choice == 1)
        {
            cout << "Enter the data to push into stack 1 : ";
            cin >> x;
            stack.push1(x);
        }
        else if (choice == 2)
        {
            cout << "Enter the data to push into stack 2 : ";
            cin >> x;
            stack.push2(x);
        }
        else if (choice == 3)
        {
            cout << stack.pop1() << endl;
        }
        else if (choice == 4)
        {
            cout << stack.pop2() << endl;
        }
        else if (choice == 5)
        {
            cout << stack.size1() << endl;
        }
        else if (choice == 6)
        {
            cout << stack.size2() << endl;
        }
        else
            cout << "Invalid choice" << endl;
        cout << "Enter 1 to push an element into the stack 1.\nEnter 2 to push an element into the stack 2.\nEnter 3 to pop an the top element from the stack 1.\nEnter 4 to pop an the top element from the stack 2.\nEnter 5 to print the size of the stack 1.\nEnter 6 to print the size of the stack 2." << endl;
        cin >> choice;
    }
    return 0;
}