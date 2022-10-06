//? Length Of The Linked List

#include <stdio.h>
#include <stdlib.h>
#include "Lecture-1.c"

//* Function For Finding The Length Of A Linked Lists Using Iterative Method
int length(struct node *head)
{
    int len = 0;
    while (head != NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}

//* Function For Finding The Length Of A Linked Lists Using Recursive Method
int Length(struct node *head)
{
    static int len = 0;
    if(head == NULL)
        return len;
    else
    {
        len++;
        return Length(head->next);
    }
    return 0;
}

int main()
{
    struct node *head = create();
    int len = length(head);
    //int len = Length(head);
    printf("\nLength Of The Linked List : %d", len);
    return 0;
}