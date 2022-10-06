//? Inserting A New Node In A Doubly Linked List

#include <stdio.h>
#include <stdlib.h>
#include "Lecture-1.c"

//* Inserting A New Node In A Doubly Linked List
struct node *insert(struct node *head, int index, int value, int pos)
{
    struct node *temp = NULL;
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = value;
    temp = head;
    if (index == 0) //! At The Beginning
    {
        new->next = head;
        head->prev = new;
        head = new;
    }
    else if (index == -1) //! At The End
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
        new->prev = temp;
        new->next = NULL;
        temp=new;//? For Accessing The List In The Reverse Order
    }
    else //! At The Specified Position
    {
        if (pos == 1) //! Before The Specified Position
        {
            for (int i = 0; i < index - 1; i++)
            {
                temp = temp->next;
            }
            new->next = temp->next;
            temp->next->prev = new;//new->next->prev = new; Also Be Used
            temp->next = new;
            new->prev = temp;
        }
        else //! After The Specified Position
        {
            for (int i = 0; i < index; i++)
            {
                temp = temp->next;
            }
            new->next = temp->next;
            temp->next->prev = new;//new->next->prev = new; Also Be Used
            temp->next = new;
            new->prev = temp;
        }
    }
    return head;
}

int main()
{
    struct node *head = NULL;
    head = create(head);
    print(head);
    head = insert(head, 0, 2320, 0);//! At The Beginning
    print(head);
    head = insert(head, -1, 2320, 0);//! At The End
    print(head);
    head = insert(head, 3, 2320, 1);//! Before The Specified Position
    print(head);
    head = insert(head, 4, 2320, -1);//!After The Specified Position
    print(head);
    return 0;
}