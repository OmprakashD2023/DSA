/*
? Given a singly linked list, the task is to segregate or separate the even and odd nodes of the linked list.
*/
#include <bits/stdc++.h>
#include "Linked_List.cpp"
using namespace std;

Node* segregateNodes(Node *head){
    Node *es=NULL,*ee=NULL,*os=NULL,*oe=NULL;
    Node *curr=head;
    while(curr!=NULL){
        if(curr->data%2==0){
            if(es==NULL){
                es=ee=curr;
            }
            else{
                ee->next=curr;
                ee=ee->next;
            }
        }
        else{
            if(os==NULL){
                os=oe=curr;
            }
            else{
                oe->next=curr;
                oe=oe->next;
            }
        }
        curr=curr->next;
    }
    if(os==NULL||es==NULL){
        return head;
    }
    ee->next=os;
    oe->next=NULL;
    return es;
}

int main(){
    Node obj=Node();
    Node *head=NULL;
    head=obj.create();
    obj.print(head);
    head=segregateNodes(head);
    obj.print(head);
    return 0;
}