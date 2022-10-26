/*
    Implementation of Queue using Linked List
*/

#include <bits/stdc++.h>
using namespace std;

class QueueNode
{
public:
    int data;
    QueueNode *next;
    QueueNode(int data)
    {
        data = data;
        next = NULL;
    }
};

class Queue : public QueueNode
{
public:
    QueueNode *front = NULL, *rear = NULL;
    int size = 0;

    void enQueue(int x)
    {

        QueueNode *temp = new QueueNode(x);

        if (rear == NULL)
        {
            front = rear = temp;
            return;
        }
        size++;
        rear->next = temp;
        rear = temp;
    }

    void deQueue()
    {

        if (front == NULL)
            return;

        QueueNode *temp = front;
        front = front->next;

        if (front == NULL)
            rear = NULL;
        size--;
        delete (temp);
    }

    int getSize(){
        return size;
    }

    int getFront(){
        return front == NULL ? -9999 : front->data;
    }

    int getRear(){
        return rear == NULL ? -9999 : rear->data;
    }

    bool isEmpty(){
        return front == NULL;
    }
};
