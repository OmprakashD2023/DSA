/*
    Implementation of Queue using Array
*/

#include <bits/stdc++.h>
using namespace std;

class Queue
{
private:
    int size, capacity;
    int *arr;

public:
    Queue(int c)
    {
        capacity = c;
        size = 0;
        arr = new int[capacity];
    }

    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "Queue is full!" << endl;
            return;
        }
        arr[size] = x;
        size++;
    }

    void dequeue() // Time Complexity : O(n)
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        for (int i = 0; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    int getFront()
    {
        if (isEmpty())
            return -1;
        return arr[0];
    }

    int getRear()
    {
        if (isEmpty())
            return -1;
        return arr[size - 1];
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == capacity;
    }

    int getSize()
    {
        return size;
    }

    void print()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
    }
};

int main()
{
    int n;
    cout << "Enter the number of elements in the Queue : ";
    cin >> n;
    int choice;
    Queue queue = Queue(n);
    cout << "Enter 1 to insert a new element in the Queue\nEnter 2 to delete the front element in the Queue\nEnter 3 to print the queue\nEnter 4 to get the Front Element in the Queue\nEnter 5 to get the Back Element in the Queue\nEnter 6 to get the Size of the Queue\nEnter 7 to check whether the Queue is full\nEnter 8 to check whether the Queue is empty\n";
    cout<<"Enter your choice : ";
    cin >> choice;
    do
    {
        if (choice == 1)
        {
            int x;
            cout << "Enter the data to insert into the Queue : ";
            cin >> x;
            queue.enqueue(x);
        }
        else if (choice == 2)
        {
            queue.dequeue();
        }
        else if (choice == 3)
        {
            queue.print();
        }
        else if (choice == 4)
        {
            cout << queue.getFront() << endl;
        }
        else if (choice == 5)
        {
            cout << queue.getRear() << endl;
        }
        else if (choice == 6)
        {
            cout << queue.getSize() << endl;
        }
        else if (choice == 7)
        {
            if (queue.isFull())
                cout << "Queue is full" << endl;
            else
                cout << "Queue is not full" << endl;
        }
        else if (choice == 8)
        {
            if (queue.isEmpty())
                cout << "Queue is empty" << endl;
            else
                cout << "Queue is not empty" << endl;
        }
        else
            cout << "Invalid Choice" << endl;
        cout << "Enter 1 to insert a new element in the Queue\nEnter 2 to delete the front element in the Queue\nEnter 3 to print the queue\nEnter 4 to get the Front Element in the Queue\nEnter 5 to get the Back Element in the Queue\nEnter 6 to get the Size of the Queue\nEnter 7 to check whether the Queue is full\nEnter 8 to check whether the Queue is empty\n";
        cout<<"Enter your choice : ";
        cin >> choice;
    }while(choice);
    return 0;
}