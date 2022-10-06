//? Program To Detect Loop In A Linked List

#include <stdio.h>
#include <stdlib.h>
#include "Lecture-1.c"


//* Function To Detect Loop In A Linked List
int detectLoop(struct node *head)
{
    struct node *slow_ptr = head;
    struct node *fast_ptr = head;

    while (slow_ptr != NULL && fast_ptr != NULL && fast_ptr->next != NULL)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;

        if (slow_ptr == fast_ptr)
        {
            return 1;
        }
    }
    return 0;
}

int main(){
    struct node *head=create();
    if(detectLoop(head)){
        printf("Loop Detected\n");
    }
    else{
        printf("No Loop Detected\n");
    }
    return 0;
}