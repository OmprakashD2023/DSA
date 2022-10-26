/*
    Implementation of Circular Queue using Array

    Enqueue()
        rear = (front + size - 1) % capacity;
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        size ++ ;

    Dequeue()
        front = (front + 1) % capacity;
        size -- ;
*/

#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    int front, rear, size;
    int capacity;
    int *arr;
};

Queue *createQueue(int capacity)
{
    Queue *queue = new Queue();
    queue->capacity = capacity;
    queue->size = queue->front = 0;

    // queue->rear = capacity - 1;
    queue->arr = new int[queue->capacity * sizeof(int)];
    return queue;
}

bool isFull(Queue *queue)
{
    return queue->capacity == queue->size;
}

bool isEmpty(Queue *queue)
{
    return queue->size == 0;
}

void enqueue(Queue *queue, int item)
{
    if (isFull(queue))
    {
        return;
    }
    queue->rear = (queue->front + queue->size - 1) % queue->capacity;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->arr[queue->rear] = item;
    queue->size += 1;
}

int dequeue(Queue *queue)
{
    if (isEmpty(queue))
    {
        return 0;
    }
    int item = queue->arr[queue->front]; 
	queue->front = (queue->front + 1) 
				% queue->capacity; 
    queue->size = queue->size - 1;
    return item;
}

int front(Queue *queue)
{
    if (isEmpty(queue))
        return 0;
    return queue->arr[queue->front];
}

int rear(Queue *queue)
{
    if (isEmpty(queue))
        return 0;
    return queue->arr[queue->rear];
}

void print(Queue *queue)
{
    for (int i = 0; i < queue->size; i++)
        cout << queue->arr[i] << " ";
}

int getSize(Queue *queue)
{
    return queue->size;
}

int main()
{
    int n;
    cout << "Enter the number of elements in the Queue : ";
    cin >> n;
    int choice;
    Queue *queue = createQueue(n);
    cout << "Enter 1 to insert a new element in the Queue\nEnter 2 to delete the front element in the Queue\nEnter 3 to print the queue\nEnter 4 to get the Front Element in the Queue\nEnter 5 to get the Back Element in the Queue\nEnter 6 to get the Size of the Queue\nEnter 7 to check whether the Queue is full\nEnter 8 to check whether the Queue is empty\n";
    cout << "Enter your choice : ";
    cin >> choice;
    do
    {
        if (choice == 1)
        {
            int x;
            cout << "Enter the data to insert into the Queue : ";
            cin >> x;
            enqueue(queue, x);
        }
        else if (choice == 2)
        {
            cout << "Element Dequeued : " << dequeue(queue);
        }
        else if (choice == 3)
        {
            print(queue);
        }
        else if (choice == 4)
        {
            cout << front(queue) << endl;
        }
        else if (choice == 5)
        {
            cout << rear(queue) << endl;
        }
        else if (choice == 6)
        {
            cout << getSize(queue) << endl;
        }
        else if (choice == 7)
        {
            if (isFull(queue))
                cout << "Queue is full" << endl;
            else
                cout << "Queue is not full" << endl;
        }
        else if (choice == 8)
        {
            if (isEmpty(queue))
                cout << "Queue is empty" << endl;
            else
                cout << "Queue is not empty" << endl;
        }
        else
            cout << "Invalid Choice" << endl;
        cout << "Enter 1 to insert a new element in the Queue\nEnter 2 to delete the front element in the Queue\nEnter 3 to print the queue\nEnter 4 to get the Front Element in the Queue\nEnter 5 to get the Back Element in the Queue\nEnter 6 to get the Size of the Queue\nEnter 7 to check whether the Queue is full\nEnter 8 to check whether the Queue is empty\n";
        cout << "Enter your choice : ";
        cin >> choice;
    } while (choice);
    return 0;
}