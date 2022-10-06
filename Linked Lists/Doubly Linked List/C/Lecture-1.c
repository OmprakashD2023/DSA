//? Implementation Of Doubly Linked List

#include <stdio.h>
#include <stdlib.h>

//* Structure Of Doubly Linked List
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

//* Creating A Doubly Linked List
struct node *create(struct node *head)
{
    int choice;
    do
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        struct node *tmp;
        printf("Enter The Value : ");
        scanf("%d", &new->data);
        new->next = NULL;
        new->prev = NULL;
        if (head == NULL)
        {
            head = new;
            tmp = new;
        }
        else
        {
            new->prev = tmp;
            tmp->next = new;
            tmp = new;
        }

        printf("Enter 1 To Continue.... : ");
        scanf("%d", &choice);
    } while (choice);

    return head;
}

//* Displaying A Doubly Linked List
void print(struct node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}