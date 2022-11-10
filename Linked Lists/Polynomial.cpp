/*
    Polynomial Operation
    * Addition
    * Multiplication
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    float coef;
    int expo;
    Node *next;
};

class Polynomial : public Node
{
    Node *insert(Node *head, float coef, int expo)
    {
        Node *temp;
        Node *newNode = new Node();
        newNode->coef = coef;
        newNode->expo = expo;
        newNode->next = NULL;

        // If there is no node in the list or given exponent is greater than the first node exponent
        if (head == NULL || expo > head->expo)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            temp = head;
            while (temp->next != NULL && temp->next->expo >= expo)
                temp = temp->next;
            newNode->next = temp->next;
            temp->next = newNode;
        }
        return head;
    }

public:
    Node *create(Node *head)
    {
        float coef;
        int expo;
        do
        {
            cout << "Enter the Coefficient Term : ";
            cin >> coef;
            if (coef == -9999)
                break;
            cout << "Enter the Exponent Term : ";
            cin >> expo;
            head = insert(head, coef, expo);
        } while (1);
        return head;
    }

    void print(Node *root)
    {
        if (root == NULL)
        {
            cout << "No Polynomial" << endl;
            return;
        }
        Node *temp = root;
        while (temp != NULL)
        {
            cout << temp->coef << "X^" << temp->expo;
            temp = temp->next;
            if (temp != NULL)
                cout << "+";
            else
                cout << endl;
        }
    }

    // Using Singly Linked List
    Node *polyAdd(Node *head1, Node *head2, Node *head3)
    {
        Node *ptr1 = head1;
        Node *ptr2 = head2;
        while (ptr1 != NULL && ptr2 != NULL)
        {
            if (ptr1->expo == ptr2->expo)
            {
                head3 = insert(head3, ptr1->coef + ptr2->coef, ptr1->expo);
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            else if (ptr1->expo > ptr2->expo)
            {
                head3 = insert(head3, ptr1->coef, ptr1->expo);
                ptr1 = ptr1->next;
            }
            else if (ptr1->expo < ptr2->expo)
            {
                head3 = insert(head3, ptr2->coef, ptr2->expo);
                ptr2 = ptr2->next;
            }
        }
        while (ptr1 != NULL)
        {
            head3 = insert(head3, ptr1->coef, ptr1->expo);
            ptr1 = ptr1->next;
        }
        while (ptr2 != NULL)
        {
            head3 = insert(head3, ptr2->coef, ptr2->expo);
            ptr2 = ptr2->next;
        }
        return head3;
    }

    Node *polyMulti(Node *head1, Node *head2, Node *head3)
    {
        Node *ptr1 = head1;
        Node *ptr2 = head2;
        if (head1 == NULL || head2 == NULL)
            return NULL;
        while (ptr1 != NULL)
        {
            while (ptr2 != NULL)
            {
                head3 = insert(head3, ptr1->coef * ptr2->coef, ptr1->expo + ptr2->expo);
                ptr2 = ptr2->next;
            }
            ptr1 = ptr1->next;
            ptr2 = head2;
        }

        Node *ptr3 = head3;
        Node *temp = NULL;
        while (ptr3->next != NULL)
        {
            if (ptr3->expo == ptr3->next->expo)
            {
                ptr3->coef += ptr3->next->coef;
                temp = ptr3->next;
                ptr3->next = ptr3->next->next;
                free(temp);
                temp = NULL;
            }
            else
            {
                ptr3 = ptr3->next;
            }
        }

        return head3;
    }
};

int main()
{
    Node *n1 = NULL;
    Node *n2 = NULL;
    Node *n3 = NULL;
    Polynomial obj = Polynomial();
    cout << "Polynomial 1 : ";
    n1 = obj.create(n1);
    cout << "Polynomial 2 : ";
    n2 = obj.create(n2);
    cout << "Polynomial 1 : ";
    obj.print(n1);
    cout << endl;
    cout << "Polynomial 2 : ";
    obj.print(n2);
    n3 = obj.polyAdd(n1, n2, n3);
    cout << endl
         << "Polynomial Additon : ";
    obj.print(n3);
    cout << endl;
    n3 = NULL;
    cout << "Polynomial Multiplication : ";
    cout << endl;
    n3 = obj.polyMulti(n1, n2, n3);
    obj.print(n3);
    return 0;
}
