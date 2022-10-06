//? Program Tto Check If A Singly Linked List Is Palindrome

#include <stdio.h>
#include <stdlib.h>

int count = 0;

//* Structure Of A Singly Linked List
struct node
{
    char name;
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
        scanf(" %c", &cur->name);

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
        printf("%c ", tail->name);
        tail = tail->next;
    }
}

//* Function To Reverse The Other Half Of The Linked Lists
struct node *reverse_list(struct node *head)
{
    struct node *prev = NULL;
    struct node *next = head;
    struct node *cur = head;
    while (cur != NULL)
    {
        next = next->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

//* Function To Check Whether The Linked List Is A Palindrome Or Not
int isPalindrome(struct node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return 0;
    }
    struct node *slow_ptr = head;
    struct node *fast_ptr = head;

    //! To Find The Middle Of The Linked Lists
    while (fast_ptr->next != NULL && fast_ptr->next->next != NULL)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }

    //!To Reverse The Nodes After The Middle Of The Linked Lists
    slow_ptr->next = reverse_list(slow_ptr->next);
    slow_ptr = slow_ptr->next;

    //? Check If The Linked List Is A Palindrome Or Not
    while (slow_ptr != NULL)
    {
        if (head->name != slow_ptr->name)
            return 0;
        head = head->next;
        slow_ptr = slow_ptr->next;
    }
    return 1;
}

int main()
{
    struct node *head = create();
    if (isPalindrome(head))
    {
        printf("\nIt Is A Palindrome");
    }
    else
    {
        printf("\nIt Is Not A Palindrome");
    }
    return 0;
}