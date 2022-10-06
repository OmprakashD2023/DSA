#include <bits/stdc++.h>
#include "Linked_List.cpp"
using namespace std;

void removeLoop(Node *head)
{
    Node *slow_ptr = *fast_ptr = head;
    while (fast_ptr != NULL && fast_ptr->next != NULL)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next;
        if (slow_ptr == fast_ptr)
        {
            break;
        }
    }
    if (slow_ptr != fast_ptr)
    {
        return;
    }
    slow_ptr = head;
    while (fast_ptr->next != slow_ptr->next)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next;
    }
    fast_ptr->next = NULL;
    return;

    /*

    TODO: Analyze This Code
    Node *fast = head;
    Node *slow = head;
    Node *temp = NULL;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
            if (slow == fast)
            {
                slow = head;
                fast = fast;
                while (slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                temp = slow;
                while (temp->next != slow)
                {
                    temp = temp->next;
                }
                temp->next = NULL;
            }
        }
    }
    */
}