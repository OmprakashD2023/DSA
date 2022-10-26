/*
    Implementation of Stack using Single Queue
*/

#include <bits/stdc++.h>
using namespace std;

class Stack
{
    queue<int> q;

public:
    void push(int x)
    {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    void pop()
    {
        if (q.empty())
            return;
        q.pop();
    }

    int top()
    {
        return (q.empty()) ? -1 : q.front();
    }

    int size()
    {
        return q.size();
    }

    bool isEmpty()
    {
        return q.empty();
    }
};