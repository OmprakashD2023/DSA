#include <bits/stdc++.h>
using namespace std;

static int c = 0;

class Node
{
public:
    int data;
    Node *next;
    Node *create()
    {
        int n;
        Node *head = NULL;
        Node *tail = NULL;
        do
        {
            Node *cur = new Node();
            c++;
            cout << "Enter the data : ";
            cin >> cur->data;
            if (head == NULL)
                head = tail = cur;
            else
            {
                tail->next = cur;
                tail = cur;
                tail->next = NULL;
            }
            cout << "Enter 1 to continue... : ";
            cin >> n;
        } while (n);
        return head;
    }

    //* Iterative Approach
    void print(Node *head)
    {
        Node *temp = head;
        while (head != NULL)
        {
            cout << head->data << " ";
            head = head->next;
        }
    }

    //* Recursive Approach
    void printRecursive(Node *head)
    {
        if (head == NULL)
            return;
        cout << head->data << " ";
        printRecursive(head->next);
    }
};