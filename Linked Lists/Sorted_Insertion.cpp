#include <bits/stdc++.h>
#include "Linked_List.cpp"
using namespace std;

class SortedInsertion : public Node
{
public:
    Node *Insert(Node *head, int data)
    {
        Node *curr = head;
        Node *newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;
        if (head == NULL)
            return newNode;
        if (head->data > data)
        {
            newNode->next = head;
            return newNode;
        }
        while (curr->next != NULL && curr->next->data < data)
        {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;

        return head;
    }
};

int main()
{
    SortedInsertion obj = SortedInsertion();
    Node *head = NULL;
    head = obj.create();
    obj.print(head);
    int data;
    cout << "Enter the data to be inserted : ";
    cin >> data;
    obj.Insert(head, data);
    obj.print(head);
    return 0;
}