//? Deleting A Node In A Doubly Linked List

#include <stdio.h>
#include <stdlib.h>
#include "Lecture-1.c"

//* Delete A Node From A Doubly Linked List
struct node *delete (struct node *head, int index)
{
    struct node *temp = NULL;
    struct node *cur = head;
    if (index == 0) //! At The Beginning
    {
        head = cur->next;
        head->prev = NULL;
        free(cur);
        cur = NULL;
    }
    else if (index == -1) //! At The End
    {
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->prev->next = NULL;
        free(cur);
        cur = NULL;
    }
    else//! At The Specified Position
    { 
        for (int i = 0; i < index - 1; i++)
        {
            cur = cur->next;
        }
        temp = cur->next;
        cur->next = cur->next->next;
        cur->next->prev = cur;
        free(temp);
        temp = NULL;

        //? Also Be Used
        /*
        for(int i=0;i<index;i++){
            cur=cur->next;
        }
        cur->prev->next=cur->next;
        cur->next->prev=cur->prev;
        free(cur);
        cur=NULL;
        */

    }
    return head;
}

int main()
{
    struct node *head = NULL;
    head = create(head);
    print(head);
    head = delete (head, 0); //! At The Beginning
    print(head);
    head = delete (head, -1); //! At The End
    print(head);
    head = delete (head, 2); //! At The Specified Position
    print(head);
    return 0;
}