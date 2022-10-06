#include<bits/stdc++.h>
#include "Lecture-1.cpp"
using namespace std;

class Reverse : public Node{
public:
    //! When head pointer is given
    Node* reverseList(Node* head){
        Node *curr,*prev,*newNode;
        curr = head;
        newNode = head->next;
        do{
            prev = curr;
            curr = newNode;
            newNode = curr->next;
            curr->next = prev;
        }while(curr!=head);
        return curr->next;
    }

    /*
    ! When tail pointer is given 
    Node *curr,*prev,*newNode;
        curr = tail->next;
        newNode = curr->next;
        while(curr!=tail){
            prev = curr;
            curr = newNode;
            newNode = curr->next;
            curr->next = prev;
        };
        newNode->next =tail;
        tail = newNode;
        return tail;
    */
};

int main(){
    Reverse obj=Reverse();
    Node *head = NULL;
    head = obj.create(head);
    head = obj.reverseList(head);
    obj.print(head);
    return 0;
}