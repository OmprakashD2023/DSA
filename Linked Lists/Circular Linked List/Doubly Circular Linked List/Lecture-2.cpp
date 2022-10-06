#include <bits/stdc++.h>
#include "Lecture-1.cpp"
using namespace std;

class Insert : public Node
{
public:
    Node *insert(Node *head, int pos = 0, int end = 0)
    {
        Node *temp = head;
        Node *curr = NULL;
        Node *newNode = new Node();
        if (head == NULL)
        {
            cout << "Enter the data to insert : ";
            cin >> newNode->data;
            newNode->next = newNode;
            newNode->prev = newNode;
            return newNode;
        }
        if (pos == 0 || end == -1 || pos == c)
        {
            if (pos == c)
                end = -1;
            c++;
            cout << "Enter the data to insert : ";
            cin >> newNode->data;
            newNode->prev = head->prev;
            newNode->next = head;
            head->prev->next = newNode;
            head->prev = newNode;
            return end == -1 ? head : newNode;
        }
        else
        {
            if (pos < 0 || pos > c)
            {
                cout << "Invalid position" << endl;
                return head;
            }
            int i = 0;
            while (i < pos - 2)
            {
                temp = temp->next;
                i++;
            }
            c++;
            cout << "Enter the data to insert : ";
            cin >> newNode->data;
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
    obj.print(head);
    int pos;
    cout << "Enter the position to insert : ";
    cin >> pos;
    if (pos == 0)
        head = obj.insert(head);
    else if (pos == -1)
        head = obj.insert(head, -1, pos);
    else
        head = obj.insert(head, pos, 0);
    obj.print(head);
    return 0;
}