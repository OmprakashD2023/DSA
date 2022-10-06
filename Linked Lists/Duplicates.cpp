#include<bits/stdc++.h>
#include "Linked_List.cpp"
using namespace std;

void removeDuplicates(Node* head){
    Node *curr=head;
    if(head==NULL){
        return head;
    }
    while(curr!=NULL && curr->next!=NULL){
        if(curr->data==curr->next->data){
            Node *temp=curr->next;
            curr->next=curr->next->next;
            delete temp;
        }
        else{
            curr=curr->next;
        }
    }
}

int main(){
    Node obj=Node();
    Node *head = NULL;
    head=obj.create();
    head=removeDuplicates(head);
    obj.print(head);
    return 0;
}