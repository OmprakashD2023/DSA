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
        Node *temp = NULL;
        int n;
        do
        {
            Node *cur = new Node();
            c++;
            cout << "Enter the data : ";
            cin >> cur->data;
            cur->next = NULL;
            cur->prev = NULL;
            if (head == NULL)
            {
                head = temp = cur;
                head->next = NULL;
                head->prev = NULL;
            }
            else
            {
                cur->prev = temp;
                temp->next = cur;
                temp = cur;
            }
            cout << "Enter your choice...";
            cin >> n;
        } while (n);
        return head;
    }

    Node* tail(Node *head){
        while(head->next != NULL)
        {
            head = head->next;
        }
        return head;
    }

    void printReverse(Node *tail){
        while(tail!=NULL){
            cout<<tail->data<<" ";
            tail = tail->prev;
        }
    }

    void print(Node *head)
    {
        while (head != NULL)
        {
            cout << head->data << " ";
            head = head->next;
        }
    }
};

/*
int main()
{
    Node obj = Node();
    Node *head = NULL;
    head = obj.create(head);
    head->print(head);
    Node *tail = obj.tail(head);
    tail->printReverse(tail);
    return 0;
}
*/