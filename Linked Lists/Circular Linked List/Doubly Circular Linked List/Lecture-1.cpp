#include <bits/stdc++.h>
using namespace std;

static int c = 0;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node *create(Node *head)
    {
        Node *tail = new Node();
        int n = 1;
        while (n)
        {
            c++;
            Node *newNode = new Node();
            cout << "Enter the data : ";
            cin >> newNode->data;
            if (head == NULL)
            {
                head = tail = newNode;
                head->next = head->prev = newNode;
            }
            else
            {
                tail->next = newNode;
                newNode->prev = tail;
                newNode->next = head;
                head->prev = newNode;
                tail = newNode;
            }
            cout << "Enter your choie : ";
            cin >> n;
        }
        return head;
    }

    void print(Node *head)
    {
        Node *temp = head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        }while (temp != head);

    }
};

/*
int main()
{
    Node obj = Node();
    Node *head = NULL;
    head = obj.create(head);
    obj.print(head);
    return 0;
}
*/