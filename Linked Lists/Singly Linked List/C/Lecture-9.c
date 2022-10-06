//? Program To Find The n’th Node From The End Of A Linked List

#include <stdio.h>
#include <stdlib.h>
#include "Lecture-1.c"

struct node *find(struct node *head, int n)
{
    struct node *cur = head;
    struct node *temp = head;

    while (n--)
    {
        temp = temp->next;
    }

    while (temp != NULL)
    {
        cur=cur->next;
        temp=temp->next;
    }

    return cur;
}

int main()
{
    struct node *head = create();
    int n;
    printf("\nEnter The Number To Find The Node From The End Of A Linked List : ");
    scanf("%d", &n);
    struct node *node = find(head, n);
    printf("\nAnswer : %d", node->data);
    return 0;
}