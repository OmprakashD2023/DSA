#include <bits/stdc++.h>
#include "Linked_List.cpp"
using namespace std;

Node *pairWiseSwap(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *prev = head;
    Node *curr = head->next->next;
    head = head->next;
    head->next = prev;
    while (curr != NULL && curr->next != NULL)
    {
        prev->next=curr->next;
        prev=curr;
        Node *next=curr->next->next;
        curr->next->next = curr;
        curr = next;
    }
    prev->next = curr;
    return head;
}

int main(){
    Node obj = Node();
    Node *head=NULL;
    head=obj.create();
    obj.print(head);
    head=pairWiseSwap(head);
    obj.print(head);
    return 0;
}