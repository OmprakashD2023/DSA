/*
    Polynomial Addition
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
    int coef;
    int expo;
    Node *next;

    Node *insert(Node *head, Node *node)
    {
        Node *temp = NULL;
        if (head == NULL || node->expo > head->expo)
        {
            node->next = head;
            return head;
        }
        else
        {
            temp = head;
            while (temp->next != NULL && temp->next->expo > node->expo)
                temp = temp->next;
            node->next = temp->next;
            temp->next = node;
        }
        return head;
    }

public:
    Node(int coef, int expo)
    {
        this->coef = coef;
        this->expo = expo;
        this->next = NULL;
    }

    Node *create()
    {
        Node *head = NULL;
        int coef, expo;
        do
        {
            cout << "Enter the coefficient : ";
            cin >> coef;
            cout << "Enter the exponent : ";
            cin >> expo;
            Node *node = new Node(coef, expo);
            head = insert(head, node);
        } while (coef != -9999);
    }

    void print(Node *head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->coef << "x^" << temp->expo << " ";
            temp = temp->next;
        }
    }

    Node *poly_add(Node *head1, Node *head2)
    {
        Node *temp1 = head1->next;
        Node *temp2 = head2->next;
        Node *result = new Node(0, 0);
        Node *res = result;
        while (temp1 != NULL && temp2 != NULL)
        {
            if (temp1->expo == temp2->expo)
            {
                int res = temp1->coef + temp2->coef;
                if (res != 0)
                {
                    Node *temp = new Node(res, temp1->expo);
                    result->next = temp;
                    result = temp;
                }
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            else if (temp1->expo > temp2->expo)
            {
                Node *temp1_res = new Node(temp1->coef, temp1->expo);
                result->next = temp1_res;
                result = temp1_res;
                temp1 = temp1->next;
            }
            else
            {
                Node *temp2_res = new Node(temp2->coef, temp2->expo);
                result->next = temp2_res;
                result = temp2_res;
                temp2 = temp2->next;
            }
        }
        while (temp1 != NULL)
        {
            Node *temp_res = new Node(temp1->coef, temp1->expo);
            result->next = temp_res;
            result = temp_res;
            temp1 = temp1->next;
        }
        while (temp2 != NULL)
        {
            Node *temp_res = new Node(temp2->coef, temp2->expo);
            result->next = temp_res;
            result = temp_res;
            temp2 = temp2->next;
        }
        return res->next;
    }
};

int main()
{
    Node *n1 = new Node(0, 0);
    Node *n2 = new Node(0, 0);
    Node *n3 = new Node(0, 0);
    Node *head1 = n1->create();
    Node *head2 = n2->create();
    cout << "Polynomial 1 : ";
    n1->print(head1);
    cout<<endl;
    cout << "Polynomial 2 : ";
    n2->print(head2);
    Node *res = n3->poly_add(head1, head2);
    cout<<endl<<"Polynomial Additon : ";
    n3->print(res);
    return 0;
}
