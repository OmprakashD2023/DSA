#include<bits/stdc++.h>
#include "Linked_List.cpp"
using namespace std;

class FindNode : public Node{
public:
    int find(Node *head,int pos){
        Node *slow_ptr = head,*fast_ptr = head;
        int i=0;
        if(head==NULL)
            return -1;
        while(i<pos){
            if(fast_ptr==NULL)
                return -1;
            fast_ptr=fast_ptr->next;
            i++;
        }
        while(fast_ptr!=NULL){
            fast_ptr=fast_ptr->next;
            slow_ptr=slow_ptr->next;
        }
        return slow_ptr->data;
    }
};

int main(){
    int pos;
    FindNode obj = FindNode();
    Node *head = NULL;
    head=obj.create();
    cout<<"Enter the position of the node from the end : ";
    cin>>pos;
    cout<<"Answer : "<<obj.find(head,pos);
    return 0;
}