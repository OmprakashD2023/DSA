#include <bits/stdc++.h>
using namespace std;

static int c = 0;

class Node
{
public:
    char data;
    Node *next;
    Node *create()
    {
        int n;
        Node *head = NULL;
        Node *tail = NULL;
        do
        {
            Node *cur = new Node();
            c++;
            cout << "Enter the data : ";
            cin >> cur->data;
            if (head == NULL)
                head = tail = cur;
            else
            {
                tail->next = cur;
                tail = cur;
                tail->next = NULL;
            }
            cout << "Enter 1 to continue... : ";
            cin >> n;
        } while (n);
        return head;
    }

    //* Iterative Approach
    void print(Node *head)
    {
        Node *temp = head;
        while (head != NULL)
        {
            cout << head->data << " ";
            head = head->next;
        }
    }

    //* Recursive Approach
    void printRecursive(Node *head)
    {
        if (head == NULL)
            return;
        cout << head->data << " ";
        printRecursive(head->next);
    }

    Node *middleNode(Node *head)
    {
        if (head == NULL)
            return NULL;
        Node *slow_ptr = head, *fast_ptr = head;
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
        }
        return slow_ptr; //! It returns the address of the middle node
    }

    bool checkPalindrome(Node *head)
    {
        if (head == NULL)
            return true;
        Node *middle = middleNode(head);
        Node *prev = NULL;
        Node *next = NULL;
        while(middle != NULL){
            next = middle->next;
            middle -> next = prev;
            prev = middle;
            middle = next;
        }
        while(prev != NULL){
            if(prev->data != head->data){
                return false;
            }
            prev=prev->next;
            head=head->next;
        }
        return true;
    }
};

int main(){
    Node obj = Node();
    Node *head=NULL;
    head = obj.create();
    cout<<"List : ";
    obj.print(head);
    cout<<endl;
    if(obj.checkPalindrome(head))
        cout<<"It is a palindrome!"<<endl;
    else    
        cout<<"It is not a palindrome!"<<endl;
    return 0;
}