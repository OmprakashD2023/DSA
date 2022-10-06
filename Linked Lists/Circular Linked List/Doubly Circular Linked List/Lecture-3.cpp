#include <bits/stdc++.h>
#include "Lecture-1.cpp"
using namespace std;

class Deletion : public Node
{
public:
    Node *deleteNode(Node *head, int pos = 0, int end = 0)
    {
        Node *temp = NULL;
        if (head == NULL)
        {
            return NULL;
        }
        else if (head->next == NULL)
        {
            delete head;
            return NULL;
        }
        else if (pos == 0)
        {
            c--;
            head->next->prev = head->prev;
            head->prev->next = head->next;
            temp = head->next;
            delete head;
            return temp;
        }
        else if (end == -1 || pos == c)
        {
            c--;
            temp = head->prev;
            Node *tail = temp->prev;
            tail->next = head;
            head->prev = tail;
            delete temp;
            return head;
        }
        else
        {
            if (pos < 0 || pos > c)
            {
                cout << "Invalid position" << endl;
                return NULL;
            }
            int i=0;
            temp=head;
            while(i<pos-2){
                temp=temp->next;
                i++;
            }
            c--;
            temp->next->prev=temp;
            Node *del=temp->next;
            temp->next = temp->next->next;
            delete del;
            return head;
        }
    }
};

int main()
{
    Deletion obj = Deletion();
    Node *head = NULL;
    head = obj.create(head);
    obj.print(head);
    int pos;
    cout << "\nEnter the position to delete : ";
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