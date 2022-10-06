#include<bits/stdc++.h>
#include "Linked_List.cpp"
using namespace std;

bool detectLoop(Node *head){
    Node *slow_ptr = head,*fast_ptr = head;
    while(fast!=NULL && fast->next != NULL){
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
        if(slow_ptr==fast_ptr){
            return true;
        }
    }
    return false;
}
