#include <bits/stdc++.h>
#include "Lecture-1.cpp"
using namespace std;

class Insert : public Node
{
public:
    Node *insert(Node *head, int pos = 0, int end = 0)
    {
        Node *newNode = new Node();
        cout << "Enter the data : ";
        cin >> newNode->data;
        if (head == NULL || pos == 0) //! At the beginning
        {
            c++;
            newNode->next = head;
            return newNode;
        }
        else if (end == -1) //! At the end
        {
            if (head == NULL)
            {
                c++;
                newNode->next = NULL;
                head = newNode;
                return head;
            }
            else
            {
                c++;
                Node *temp = head;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newNode;
                newNode->next = NULL;
                return head;
            }
        }
        else//!At any position
        {
            if(pos-1>c){
                cout<<"Invalid position"<<endl;
                return head;   
            }
            Node *temp = head;
            int i = 0;
            c++;
            while (i < pos - 2)
            {
                temp = temp->next;
                i++;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            return head;
        }
    }
};

int main()
{
    Insert obj = Insert();
    Node *head = obj.create();
    int pos;
    cout<<"Enter the position to insert : ";
    cin>>pos;
    if(pos == 0)
        head = obj.insert(head);
    else if(pos==-1)
        head = obj.insert(head,-1,pos);
    else
        head = obj.insert(head,pos);
    head->print(head);
    return 0;
}