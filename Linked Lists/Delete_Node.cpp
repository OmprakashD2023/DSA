/*
? This is one of the tricky problem asked in an interview where a random address to a node of the linked list is given and the user needs to delete the node of the given address. The address can point to any random node in-between a linked list.
*/

#include<bits/stdc++.h>
#include "Linkd_List.cpp"
using namespace std;

void deleteNode(Node *curr){
    Node *temp=curr->next;
    curr->data=temp->data;
    curr->next=temp->next;
    delete temp;
}