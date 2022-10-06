#include<bits/stdc++.h>
#include "Linked_List.cpp"
using namespace std;

class MiddleNode : public Node{
public:
    int middle(Node *head){
        if(head==NULL)
            return -9999;
        Node *slow_ptr = head,*fast_ptr = head;
        while(fast_ptr != NULL && fast_ptr->next != NULL){
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
        }
        return slow_ptr->data; //! For finding only the middle node value
    }
};

int main(){
    MiddleNode obj = MiddleNode();
    Node *head = NULL;
    head=obj.create();
    obj.print(head);
    cout<<endl<<"Middle Node : "<<obj.middle(head);
    return 0;
}