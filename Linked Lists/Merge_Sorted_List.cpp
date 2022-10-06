#include <bits/stdc++.h>
#include "Linked_List.cpp"
using namespace std;

Node *mergeSortedList(Node *head1, Node *head2)
{
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;
    Node *head = NULL, *tail = NULL;
    if (head1->data <= head2->data)
    {
        head = tail = head1;
        head1 = head1->next;
    }
    else
    {
        head = tail = head2;
        head2 = head2->next;
    }
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data <= head2->data)
        {
            tail->next = head1;
            tail=head1;
            head1 = head1->next;
        }
        else
        {
            tail->next = head2;
            tail=head2;
            head2 = head2->next;
        }
    }
    if(head1==NULL)
        tail->next = head2;
    else
        tail->next = head1;
    return head;
}

int main(){
    Node obj1 = Node();
    Node obj2 = Node();
    Node *head1 = obj1.create();
    Node *head2 = obj2.create();
    cout<<"List 1 : "<<obj1.print(head1)<<endl;
    cout<<"List 2 : "<<obj2.print(head2)<<endl;
    Node *newHead = new Node();
    newHead = mergeSortedList(head1, head2);
    cout<<"Sorted List : "<<newHead->print(newHead);
    return 0;
}