#include <bits/stdc++.h>
#include "Lecture-1.cpp"
using namespace std;

class Reverse : public Node
{
public:
    Node *reverseList(Node *head)
    {
        Node *temp = NULL;
        Node *cur = head;
        if (head == NULL || head->next == NULL)
        {
            return NULL;
        }
        while (cur != NULL)
        {
            prev = cur->prev;
            cur->prev = cur->next;
            cur->next = prev;
            cur = cur->prev;
        }
        return prev->prev;
    }
};

int main()
{
    Reverse obj = Reverse();
    Node *head = NULL;
    head = obj.create(head);
    head = obj.reverseList(head);
    obj.print(head);
    return 0;
}