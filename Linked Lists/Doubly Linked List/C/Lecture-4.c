//? Reversing A Doubly Linked List

#include <stdio.h>
#include <stdlib.h>
#include "Lecture-1.c"

//* Reversing A Doubly Linked List
struct node *reverse(struct node *head)
{
    struct node *temp = NULL;
    struct node *cur = NULL;
    cur = temp = head;
    while (cur != NULL)
    {
        head=temp;
        cur->next = cur->prev;
        cur->prev = temp;
        temp = temp->next;
        cur = temp;
    }
    return head;
}

int main()
{
    struct node *head = NULL;
    head = create(head);
    head = reverse(head);
    print(head); 
    return 0;
}