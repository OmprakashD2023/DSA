#include <bits/stdc++.h>
#include "Lecture-1.cpp"
using namespace std;

class Deletion : public Node
{
public:
    Node *Delete(Node *head, int pos = 0, int end = 0)
    {
        Node *temp = NULL;
        if (head == NULL)
            return head;
        if (pos == 0 || pos == 1)
        {
            if (head->next == head)
            {
                delete head;
                return NULL;
            }
            /* //! Naive Implementation
            temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = head->next;
            delete head;
            return temp->next;
            */

            head->data = head->next->data;
            temp = head->next;
            head->next = head->next->next;
            delete temp;
            return head;
        }
        else if (end == -1 || pos == c)
        {
            temp = head;
            while (temp->next->next != head)
            {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = head;
            return head;

            /* //! Using Tail Pointer
            temp = tail->next;
            ? Traverse the list using temp upto last before element and delete the last element and point the temp->next to head
            */
        }
        else
        {
            if (pos < 0 || pos > c)
            {
                cout << "Invalid position" << endl;
                return NULL;
            }
            else
            {
                temp = head;
                int i = 0;
                while (i < pos - 2)
                {
                    temp = temp->next;
                    i++;
                }
                Node *tmp = temp->next;
                temp->next = tmp->next;
                delete tmp;
                return head;
            }
        }
    }
};

int main()
{
    Deletion obj = Deletion();
    Node *head = NULL;
    head = obj.create(head);
    int pos;
    cout << "Enter the position to delete : ";
    cin >> pos;
    if (pos == 0)
        head = obj.Delete(head);
    else if (pos == -1)
        head = obj.Delete(head, -1, pos);
    else
        head = obj.Delete(head, pos, 0);
    obj.print(head);
    return 0;
}