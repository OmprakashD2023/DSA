//? Inserting Into The Linked Lists

#include <stdio.h>
#include <stdlib.h>
#include "Lecture-1.c"

//* Function For Inserting A Node Into The Linked Lists
struct node *insert(struct node *head, int position)
{
    if (count < position)
    {
        printf("Invalid Position");
    }
    else
    {
        struct node *tail = head;
        struct node *new = NULL;
        new = (struct node *)malloc(sizeof(struct node));
        printf("Enter The Data : ");
        scanf("%d", &new->data);
        //* In The Beginning Of The Linked Lists
        if (position == 0)
        {
            new->next = head;
            head = new;
        }
        //* In The End Of The Linked Lists
        if (position == -1)
        {
            while (tail->next != NULL)
            {
                tail = tail->next;
            }
            tail->next = new;
            new->next = NULL;
        }
        //* In The  Specified Position In The Linked Lists
        else
        {
            int i = 0;
            while (i < position-1)//! position-1 So That We Can Access The Predecessor Of The Given Position Node 
            {
                tail = tail->next;
                i++;
            }
            new->next = tail->next;
            tail->next = new;
        }
        return head;
    }
}

int main()
{
    //* Head Pointer To Linked List
    struct node *head = create();
    int position;
    print(head);
    printf("\nEnter The Position To Insert The Data : ");
    scanf("%d", &position);
    head = insert(head, position);
    print(head);
    return 0;
}