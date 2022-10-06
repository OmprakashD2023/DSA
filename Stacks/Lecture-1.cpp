/*
  ? Array based implementation of the stack
*/

#include <bits/stdc++.h>
using namespace std;
template<typename T>
class MyStack
{
private:
    T *arr; 
    int top;
    int capacity;

public:
    MyStack(int c)
    {
        arr = new T[c];
        capacity = c;
        top = -1;
    }

    void push(T x)
    {
        if (top == capacity - 1)
        {
            cout << "Stack overflow" << endl;
            return;
        }
        /* 
            ! To increase the stack size...
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
        top++;
        arr[top] = x;
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        T res = arr[top];
        top--;
        return res;
    }

    T top()
    {
        if (top == -1)
        {
            cout << "Undefined Behavior" << endl;
            return -1;
        }
        return arr[top];
    }

    int size()
    {
        return top + 1;
    }

    bool isEmpty()
    {
        return (top == -1);
    }
};

/*
int main()
{
    int n;
    cout << "Enter the number of elements in the stack : ";
    cin >> n;
    Stack<int> s(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cout << "Enter the data : ";
        cin >> x;
        s.push(x);
    }
    cout << s.isEmpty() << endl;
    s.push(9);//!Error
    cout << s.top() << endl;
    cout << s.size() << endl;
    for (int i = 0; i < n; i++)
    {
        cout << s.top() << " ";
        int res = s.pop();
    }
    return 0;
}
*/
