#include <bits/stdc++.h>
#include "Lecture-1.cpp"
using namespace std;

class Insertion : public Node
{
public:
    //! Using Head Pointer
    Node *Insert(Node *head, int pos = 0, int end = 0)
    {
        Node *temp = new Node();
        cout << "Enter the data : ";
        cin >> temp->data;
        if (head == NULL)
        {
            temp->next = temp;
            return temp;
        }
        if (pos == 0)
        {
            Node *curr = head;
            while (curr->next != head)
            {
                curr = curr->next;
            }
            curr->next = temp;
            temp->next = head;
            return temp;
        }
        else if (end == -1)
        {
            Node *curr = head;
            while (curr->next != head)
            {
                curr = curr->next;
            }
            curr->next = temp;
            temp->next = head;
            return head;
        }
        else
        {
            if (pos < 0 || pos - 1 > c){
                cout<<"Invalid position"<<endl;
                return head;
            }
            Node *curr = head;
            int i = 0;
            while (i < pos - 2)
            {
                curr = curr->next;
                i++;
            }
            temp->next = curr->next;
            curr->next = temp;
            return head;
        }
    }

    //! Using Tail Pointer
    /*
    Node* Insert(Node *tail){
        Node *temp=new Node();
        cout<<"Enter the data : ";
        cin>>temp->data;
        if(tail == NULL){
            temp->next = temp;
            return temp;
        }
        if(pos==0){
            temp->next=tail->next;
            tail->next=temp;
            ? If head pointer is provided do the above operation and swap the two data from temp and tail
            return tail;
        }
        else if(end==-1){
            temp->next=tail->next;
            tail->next=temp;
            tail=temp;
            ? If head pointer is provided do the above operation and swap the two data from temp and tail and then return temp which is the new head pointer
            return tail;
        }
        else{
            if (pos < 0 || pos - 1 > c){
                cout<<"Invalid position"<<endl;
                return head;
            }
            Node *curr = tail->next;
            int i = 0;
            while (i < pos - 2)
            {
                curr = curr->next;
                i++;
            }
            temp->next = curr->next;
            curr->next = temp;
            return tail;
        }
    }
    */
};

int main()
{
    Insertion obj = Insertion();
    Node *head = NULL;
    head = obj.create(head);
    obj.print(head);
    int pos;
    cout<<"Enter the position to insert : ";
    cin>>pos;
    if (pos == 0)
        head = obj.Insert(head);
    else if (pos == -1)
        head = obj.Insert(head, -1, pos);
    else
        head = obj.Insert(head, pos, 0);
    obj.print(head);
    return 0;
}