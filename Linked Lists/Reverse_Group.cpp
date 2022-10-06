#include <bits/stdc++.h>
#include "Linked_List.cpp"
using namespace std;

//! Using recursion
Node *reverseRec(Node *head, int k)
{
    Node *curr = head, *prev = NULL, *next = NULL;
    int c = 0;
    while (curr != NULL && c < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        c++;
    }
    if (next != NULL)
    {
        Node *rest_head = reverseRec(next, k);
        head->next = rest_head;
    }
    return prev;
}

//! Using iterative approach
Node *reverseIterative(Node *head, int k)
{
    Node *curr = head, *prevFirst = NULL;
    bool isFirstPass = true;
    while (curr != NULL)
    {
        Node *first = curr, *prev = NULL;
        int count = 0;
        while (curr != NULL && count < k)
        {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if (isFirstPass)
        {
            head = prev;
            isFirstPass = false;
        }
        else
        {
            prevFirst->next = prev;
        }
        prevFirst = first;
    }
    return head;
}

int main()
{
    Node obj = Node();
    Node *head = NULL;
    head = obj.create();
    obj.print(head);
    int k;
    cout << "Enter the number of groups to reverse : ";
    cin >> k;
    head = reverseRec(head, k);
    obj.print(head);
    head = reverseIterative(head, k);
    obj.print(head);
    return 0;
}