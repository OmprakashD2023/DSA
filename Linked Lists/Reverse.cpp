#include <bits/stdc++.h>
#include "Linked_List.cpp"
using namespace std;

//* Iterative Approach 
Node *reverseList(Node *head)
{
    //! Using 3 Pointers
    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;

    //! Using 2 Pointers More Efficient A Bit Tricky
    /*
    while (curr->next != NULL) {
        next = curr->next;
        curr->next = next->next;
        next->next =head;
        head = next;
    }
    return head;
    */
}

Node* recursiveReverse(Node* head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    Node *rest_head=recursiveReverse(head->next);
    Node *rest_tail=head->next;
    rest_tail->next=head;
    head->next=NULL;
    return rest_head;
}

Node* recursiveReverse2(Node *curr,Node *prev){
    if(curr==NULL)
        return prev;
    Node *next = curr->next;
    curr->next = prev;
    return recursiveReverse2(next,curr);
}

int main()
{
    Node obj = Node();
    Node *head = NULL;
    head = obj.create();
    obj.print(head);
    head=reverseList(head);
    obj.print(head);
    head=recursiveReverse(head);
    obj.print(head);
    cout<<endl;
    obj.print(recursiveReverse2(head,NULL));
    return 0;
}