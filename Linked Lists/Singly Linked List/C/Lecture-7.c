//? Middle Of The Linked Lists

#include <stdio.h>
#include <stdlib.h>
#include "Lecture-1.c"

//* Function To Find The Middle Node Of The Linked Lists
struct node *Middle(struct node *head, int middle)
{
    struct node *slow_ptr = head;
    struct node *temp = head;
    struct node *fast_ptr = head;
    while (fast_ptr != NULL && fast_ptr->next != NULL)
    {
        temp = slow_ptr;
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }
    if (count % 2 == 0)
    {
        if (middle == 1)
            return temp;
        else
            return slow_ptr;
    }
    else
    {
        return slow_ptr;
    }
}

int main()
{
    struct node *head = create();
    int middle = 1;
    if (count % 2 == 0)
    {
        printf("Which Middle Has To Be Searched : ");
        scanf("%d", &middle);
    }
    struct node *mid = Middle(head, middle);
    printf("Middle Element : %d", mid->data);
    return 0;
}