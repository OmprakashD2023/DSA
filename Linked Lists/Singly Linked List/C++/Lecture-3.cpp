#include <bits/stdc++.h>
#include "Lecture-1.cpp"
using namespace std;

class Delete : public Node
{
public:
    Node *deleted(Node *head, int pos = 0, int end = 0)
    {
        if (head == NULL)
            return NULL;
        if (pos == 0)//!From the beginning
        {
            Node *temp = head->next;
            delete head;
            return temp;
        }
        else if (end == -1)//!From the end
        {
            if (head->next == NULL)
            {
                delete head;
                return NULL;
            }
            else//!From any position
            {
                Node *temp = head;
                while (temp->next->next != NULL)
                {
                    temp = temp->next;
                }
                delete temp->next;
                temp->next = NULL;
                return head;
            }
        }
        else
        {
            if (pos > c)
            {
                cout << "Invalid position" << endl;
                return head;
            }
            Node *temp = head;
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
};

int main()
{
    Delete obj = Delete();
    Node *head = obj.create();
    int pos;
    cout << "Enter the position to delete : ";
    cin >> pos;
    if (pos == 0)
        head = obj.deleted(head);
    else if (pos == -1)
        head = obj.deleted(head, -1, pos);
    else
        head = obj.deleted(head, pos);
    head->print(head);
    return 0;
}