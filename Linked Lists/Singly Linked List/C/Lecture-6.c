//? Searching The Given Data In The Linked List

#include <stdio.h>
#include <stdlib.h>
#include "Lecture-1.c"

//* Function For Searching The Key In The Linked Lists Using The Iterative Method
int search(struct node *head, int key)
{
    while (head != NULL)
    {
        if (head->data == key)
        {
            return 1;
        }
        head = head->next;
    }
    return 0;
}

//* Function For Searching The Key In The Linked Lists Using The Recursive Method
int Search(struct node *head,int key){
    if (head == NULL)
        return 0;
    else if(head->data == key)
        return 1;
    else
        return Search(head->next,key);
}

int main()
{
    struct node *head = create();
    print(head);
    int key;
    printf("\nEnter The Key To Search : ");
    scanf("%d", &key);
    if (search(head, key))//Search(head, key)
    {
        printf("\nKey Found\n");
    }
    else
    {
        printf("\nKey Not Found\n");
    }
    return 0;
}