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
    /**
     * If the exponent of the new node is greater than the exponent of the first node, then the new
     * node is inserted at the beginning of the list. Otherwise, the new node is inserted at the
     * appropriate position in the list
     * 
     * @param head The head of the linked list
     * @param coef coefficient
     * @param expo exponent
     * 
     * @return The head of the linked list.
     */
    Node *insert(Node *head, float coef, int expo)
    {
        Node *temp;
        Node *newNode = new Node();
        newNode->coef = coef;
        newNode->expo = expo;
        newNode->next = NULL;

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

    /**
     * It returns the last node in the linked list
     * 
     * @param head The head of the linked list.
     * 
     * @return The tail of the linked list.
     */
    Node *getTail(Node *head)
    {
        while (head->next != NULL)
            head = head->next;
        return head;
    }

public:
    /**
     * The function creates a new Linked List
     * 
     * @param head The head of the linked list
     * 
     * @return The head of the linked list.
     */
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

    /**
     * It creates a circular linked list from a linear linked list
     * 
     * @param head the head of the linked list
     * 
     * @return A pointer to the head of the circular list.
     */
    Node *createCircularList(Node *head)
    {
        head = create(head);
        Node *tail = getTail(head);
        Node *temp = new Node();
        temp->coef = 0;
        temp->expo = -1;
        tail->next = temp;
        temp->next = head;

        return head;
    }

    /**
     * The function prints the polynomial in the form of a linked list and prints the polynomial
     * 
     * @param root The root of the polynomial
     * 
     * @return a pointer to the head of the linked list.
     */
    void print(Node *root)
    {
        if (root == NULL)
        {
            cout << "Zero Polynomial" << endl;
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

    /**
     * It prints the polynomial in the form of a linked list
     * 
     * @param head the head of the linked list
     * 
     * @return a pointer to the head of the linked list.
     */
    void printCircular(Node *head)
    {
        if (head == NULL)
        {
            cout << "Zero polynomial" << endl;
            return;
        }
        while (head->expo != -1)
        {
            cout << head->coef << "X^" << head->expo;
            head = head->next;
            if (head->expo
             != -1)
                cout << "+";
            else
                cout << endl;
        }
    }

    // Using Singly Linked List
    /**
     * The function takes two polynomial linked lists as input and returns a new polynomial linked list
     * which is the sum of the two input polynomials
     * 
     * @param head1 The first polynomial
     * @param head2 The second polynomial
     * @param head3 The head of the third linked list.
     * 
     * @return The head of the third linked list.
     */
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

    // Using Circular Linked List
    /**
     * The function takes two polynomials as input and returns the sum of the two polynomials
     * 
     * @param head1 head of the first polynomial
     * @param head2 head of the second polynomial
     * @param head3 The head of the third polynomial
     * 
     * @return The head of the third polynomial.
     */
    Node *polyAddCircular(Node *head1, Node *head2, Node *head3)
    {
        Node *ptr1 = head1;
        Node *ptr2 = head2;
        while (1)
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
            if (ptr1->expo == -1 && ptr2->expo == -1)
                break;
        }
        return head3;
    }

    /**
     * The function takes two polynomials as input and returns the product of the two polynomials
     * 
     * @param head1 head of the first polynomial
     * @param head2 head of the second polynomial
     * @param head3 the head of the third linked list
     * 
     * @return The head of the third linked list.
     */
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
    // Using Circular Linked List
    cout << "Polynomial 1 : ";
    n1 = obj.createCircularList(n1);
    cout << "Polynomial 2 : ";
    n2 = obj.createCircularList(n2);
    cout << "Polynomial 1 : ";
    obj.printCircular(n1);
    cout << endl;
    cout << "Polynomial 2 : ";
    obj.printCircular(n2);
    n3 = obj.polyAddCircular(n1, n2, n3);
    cout << endl
         << "Polynomial Additon : ";
    obj.printCircular(n3);
    cout << endl;

    /*
        //Using Singly Linked List
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
    */
    n3 = NULL;
    cout << "Polynomial Multiplication : ";
    cout << endl;
    n3 = obj.polyMulti(n1, n2, n3);
    obj.print(n3);
    return 0;
}
