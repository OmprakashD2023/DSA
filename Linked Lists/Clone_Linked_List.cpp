#include <bits/stdc++.h>
#include "Linked_List.cpp"
using namespace std;

Node *cloneList(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        Node *next = curr->next;
        Node *newNode = new Node();
        // newNode->data=curr->data; //? Clone the data from the original node
        newNode->next = next;
        curr->next = newNode;
        curr = next;
    }
    for (curr = head; curr != NULL; curr = curr->next->next)
    {
        curr->next->random = (curr->random == NULL) ? NULL : curr->random->next;
    }
    Node *head1=head;
    Node *head2 = head->next;
    Node *clone = head2;
    //? Separate the original and cloned linked list 
    while(head1 && head2) {
        head1->next=head1->next?head1->next->next:NULL;
        head2->next=head2->next?head2->next->next:NULL;
        head1=head1->next;
        head2=head2->next;
    }
    return clone;
}