//? Deleting The Linked Lists

#include <stdio.h>
#include <stdlib.h>
#include "Lecture-1.c"

//* Function For Deleting The Node From The Given Position In The Linked Lists
void delete (struct node *head, int position)
{
    struct node *cur = head;
    struct node *tail = NULL;
    //* At The Beginning of the Linked Lists
    if (position == 0)
    {
        head = head->next;
        free(cur);
        cur = NULL;
    }
    //* At The End Of The Linked Lists
    if (position == -1)
    {
        while (cur->next != NULL)
        {
            tail = cur;
            cur = cur->next;
        }
        if (head == tail)
        {
            head = NULL;
        }
        else
        {
            tail->next = NULL;
        }
        free(cur);
        cur = NULL;
    }
    //* At The Specified Position In The Linked Lists
    else
    {
        int i = 0;
        while (i < position)
        {
            tail = cur;
            cur = cur->next;
            i++;
        }
        tail->next = cur->next;
        free(cur);
        cur = NULL;
    }
}

//* Function For Deleting The Node From The Linked Lists
void delete_node(struct node *head, int key)
{
    struct node *cur = head;
    struct node *prev = NULL;
    while (cur != NULL)
    {
        if(cur->data == key){
            break;
        }
        prev = cur;
        cur = cur->next;
    }
    prev->next = cur->next;
}

int main()
{
    //* Head Pointer To Linked List
    struct node *head = create();
    int position;
    print(head);
    printf("\nEnter The Position To Delete The Data : ");
    scanf("%d", &position);
    if (count < position)
    {
        printf("\nInvalid Position");
    }
    else
    {
        delete (head, position);
    }
    // int key;
    // printf("\nEnter The Position To Delete The Data : ");
    // scanf("%d", &key);
    // delete_node(head,key);
    print(head);
    return 0;
}