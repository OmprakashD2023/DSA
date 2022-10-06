//* Implementation of two stacks in a single array
#include <bits/stdc++.h>
using namespace std;
class MyStack
{
private:
    int *arr;
    int capacity;
    int next1, next2;

public:
    MyStack(int n)
    {
        capacity = n;
        arr = new int[capacity];
        next1 = -1;
        next2 = n;
    }

    void push1(int x)
    {
        if (next1 < next2 - 1)
        {
            next1++;
            arr[next1] = x;
            return;
        }
        cout << "Stack Overflow!" << endl;
        exit(1);
    }

    void push2(int x)
    {
        if (next1 < next2 - 1)
        {
            next2--;
            arr[next2] = x;
            return;
        }
        cout << "Stack Overflow!" << endl;
        exit(1);
    }

    int pop1()
    {
        if (next1 >= 0)
        {
            int x = arr[next1];
            next1--;
            return x;
        }
        cout << "Stack Underflow" << endl;
        return -999;
    }

    int pop2()
    {
        if (next2 < capacity)
        {
            int x = arr[next2];
            next2++;
            return x;
        }
        cout << "Stack Underflow" << endl;
        return -999;
    }

    int size1()
    {
        return next1 + 1;
    }

    int size2()
    {
        return capacity - next2;
    }
};

int main()
{
    MyStack s = MyStack(10);
    int c;
    cout << "Enter 1 To Push Into Stack1,2 To Push Into Stack2,3 To Pop From Stack1,4 To Pop From Stack2,5 To Get The Size Of Stack1,6 To Get The Size Of Stack2" << endl;
    cin >> c;
    while (c)
    {
        if (c == 1)
        {
            int x;
            cout << "Enter the data to insert into the stack1 : ";
            cin >> x;
            s.push1(x);
        }
        else if (c == 2)
        {
            int x;
            cout << "Enter the data to insert into the stack2 : ";
            cin >> x;
            s.push2(x);
        }
        else if (c == 3)
        {
            int x = s.pop1();
            if (x != -999)
            {
                cout << x << endl;
            }
        }
        else if (c == 4)
        {
            int x = s.pop2();
            if (x != -999)
            {
                cout << x << endl;
            }
        }
        else if (c == 5)
        {
            cout << s.size1() << endl;
        }
        else if (c == 6)
        {
            cout << s.size2() << endl;
        }
        else
        {
            cout << "Invalid Choice..." << endl;
        }

        cout << "Enter 1 To Push Into Stack1,2 To Push Into Stack2,3 To Pop From Stack1,4 To Pop From Stack2,5 To Get The Size Of Stack1,6 To Get The Size Of Stack2" << endl;
        cin >> c;
    }
    return 0;
}