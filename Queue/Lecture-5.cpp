/*
    Reverse a Queue using Stack and Recursion 
*/

#include<bits/stdc++.h>
using namespace std;

void reverseIterative(queue<int> &q){
    stack<int> s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}

void reverseRecursion(queue<int> &q){
    if(q.empty())
        return;
    int x = q.front();
    q.pop();
    reverseRecursion(q);
    q.push(x);
}