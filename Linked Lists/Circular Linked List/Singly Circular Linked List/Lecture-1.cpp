#include <bits/stdc++.h>
using namespace std;

static int c = 0;

class Node
{
public:
    int data;
    Node *next;
    //! Using Head Pointer
    Node *create(Node *head)
    {
        int choice = 1;
        Node *tail = NULL;
        while (choice)
        {
            c++;
            Node *newNode = new Node();
            cout << "Enter the data : ";
            cin >> newNode->data;
            newNode->next = NULL;
            if (head == NULL)
            {
                head = tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
            cout << "Enter your choice : ";
            cin >> choice;
        }
        tail->next = head;
        return head;
    }

    void print(Node *head)
    {
        if (head == NULL)
            return;
        Node *temp = head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }

    //! Using Tail Pointer
    /*
    Node *create(Node *tail)
    {
        int choice = 1;
        while (choice)
        {
            Node *newNode = new Node();
            cout << "Enter the data : ";
            cin >> newNode->data;
            newNode->next = NULL;
            if (tail == NULL)
            {
                tail = newNode;
                tail->next = newNode;
            }
            else
            {
                newNode->next = tail->next;
                tail->next = newNode;
                tail = newNode;
            }
            cout << "Enter your choice : ";
            cin >> choice;
        }
        cout << tail->next->data;
        return tail;
    }

    void print(Node *head)
    {
        Node *temp = head->next;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (head->next != temp);
    }
    */
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