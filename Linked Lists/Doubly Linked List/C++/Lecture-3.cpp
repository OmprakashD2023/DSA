#include <bits/stdc++.h>
#include "Lecture-1.cpp"

class Delete : public Node
{
public:
    Node *deleteNode(Node *head, int pos = 0, int end = 0)
    {
        Node *temp = head;
        if (head == NULL)
            return NULL;
        if (head->next == NULL)
        {
            delete head;
            return NULL;
        }
        if (pos == 0)
        {
            Node *temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
            return head;
        }
        else if (pos == c || end == -1)
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->prev->next = NULL;
            delete temp;
            return head;
        }
        else
        {
            if (pos - 1 > c)
            {
                cout << "Invalid position";
                return head;
            }
            Node *temp = head;
            int i = 0;
            while (i < pos - 2)
            {
                temp = temp->next;
                i++;
            }
            Node *cur = temp->next;
            temp->next = temp->next->next;
            temp->next->prev = temp;
            delete cur;
            return head;
        }
    }
};

int main()
{
    Delete obj = Delete();
    Node *head = NULL;
    head = obj.create(head);
    int pos;
    cout << "Enter the position to delete : ";
    cin >> pos;
    if (pos == 0)
        head = obj.deleteNode(head);
    else if (pos == -1)
        head = obj.deleteNode(head, -1, pos);
    else
        head = obj.deleteNode(head, pos, 0);
    obj.print(head);
    return 0;
}