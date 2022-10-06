//? Implementation Of Singly Linked Lists

#include <stdio.h>
#include <stdlib.h>

int count = 0;

//* Structure Of Linked Lists
struct node
{
    int data;
    struct node *next;
};

//* Function For Creating A New Linked Lists
struct node *create()
{
    int n = 1;
    struct node *head = NULL;
    struct node *tail = NULL;
    struct node *cur = NULL;
    while (n)
    {
        cur = (struct node *)malloc(sizeof(struct node));

        printf("Enter Data : ");
        scanf("%d", &cur->data);

        if (head == NULL)
        {
            head = tail = cur;
        }
        else
        {
            tail->next = cur;
            tail = cur;
            tail->next = NULL;
        }

        count++;

        printf("Enter Your Choice : ");
        scanf("%d", &n);
    }

    tail = head;

    return tail;
}

//* Function For Displaying Linked Lists
void print(struct node *tail)
{
    while (tail != NULL)
    {
        printf("%d ", tail->data);
        tail = tail->next;
    }
}