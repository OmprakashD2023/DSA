#include<bits/stdc++.h>
#include "Linked_List.cpp"
using namespace std;

int getCount(Node* head) 
{ 
    Node* curr = head; 
    int count = 0; 
    while (curr != NULL) { 
        count++; 
        curr = curr->next; 
    } 
    return count; 
}

int intersectNode(int d,Node *head1,Node *head2){
    Node* current1 = head1; 
    Node* current2 = head2; 
  
    for (int i = 0; i < d; i++) { 
        if (current1 == NULL) { 
            return -1; 
        } 
        current1 = current1->next; 
    } 
  
    while (current1 != NULL && current2 != NULL) { 
        if (current1 == current2) 
            return current1->data; 
  
        current1 = current1->next; 
        current2 = current2->next; 
    } 
  
    return -1; 
}

int getIntersection(Node* head1, Node* head2) 
{ 
    int c1 = getCount(head1); 
    int c2 = getCount(head2); 
    int d; 
  
    if (c1 > c2) { 
        d = c1 - c2; 
        return intersectNode(d, head1, head2); 
    } 
    else { 
        d = c2 - c1; 
        return intersectNode(d, head2, head1); 
    }
} 