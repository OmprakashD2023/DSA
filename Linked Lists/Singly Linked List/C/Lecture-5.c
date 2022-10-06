//? Reversing The Linked Lists

#include <stdio.h>
#include <stdlib.h>
#include "Lecture-1.c"

//* Function For Reversing The Linked Lists
struct node *reverse(struct node *head)
{
    struct node *cur = head;
    struct node *prev = NULL;
    struct node *next = head;
    while (next != NULL)
    {
        next = next->next; 
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head=prev;

    return head;
}

int main()
{
    struct node *head = create();
    print(head);
    struct node *rev = reverse(head);
    print(rev);
    return 0;
}