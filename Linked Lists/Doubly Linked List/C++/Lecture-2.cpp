#include <bits/stdc++.h>
#include "Lecture-1.cpp"
using namespace std;

class Insert : public Node
{
public:
    Node *insert(Node *head, int pos = 0, int end = 0)
    {
        Node *newNode = new Node();
        Node *temp = NULL;
        temp = head;
        cout << "Enter the data to insert : ";
        cin >> newNode->data;
        if (head == NULL)
        {
            c++;
            newNode->next = newNode->prev = NULL;
            return newNode;
        }
        if (pos == 0)
        {
            c++;
            newNode->next = head;
            head->prev = newNode;
            return newNode;
        }
        else if (end == -1)
        {
            if (head == NULL)
            {
                c++;
                newNode->next = newNode->prev = NULL;
                return newNode;
            }
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = NULL;
            return head;
        }
        else
        {
            if (pos - 1 > c)
            {
                cout << "Invalid position";
                return head;
            }
            int i = 0;
            while (i < pos - 2)
            {
                temp = temp->next;
                i++;
            }
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
            return head;
        }
    }
};

int main()
{
    Insert obj = Insert();
    Node *head = NULL;
    head = obj.create(head);
    int pos;
    cout << "Enter the position to insert : ";
    cin >> pos;
    if (pos == 0)
        head = obj.insert(head);
    else if (pos == -1)
        head = obj.insert(head, -1, pos);
    else
        head = obj.insert(head, pos, 0);
    head->print(head);
    return 0;
}