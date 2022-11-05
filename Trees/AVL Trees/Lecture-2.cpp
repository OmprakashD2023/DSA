/*
    AVL Tree Insertion
*/

#include <bits/stdc++.h>
#include "Lecture-1.cpp"
#define SPACE 10
using namespace std;

class Insertion : public AVLTreeNode
{
public:
    int height(AVLTreeNode *node)
    {
        if (node == NULL)
            return -1;
        return max(height(node->left), height(node->right)) + 1;
    }

    int getBalanceFactor(AVLTreeNode *root)
    {
        if (root == NULL)
            return -1;
        return height(root->left) - height(root->right);
    }

    AVLTreeNode *leftRotate(AVLTreeNode *y)
    {
        AVLTreeNode *x = y->right;
        AVLTreeNode *T2 = x->left;

        x->left = y;
        y->right = T2;
        return x;
    }

    AVLTreeNode *rightRotate(AVLTreeNode *y)
    {
        AVLTreeNode *x = y->left;
        AVLTreeNode *T2 = x->right;

        x->right = y;
        y->left = T2;
        return x;
    }

    AVLTreeNode *insert(AVLTreeNode *root, int data)
    {
        if (root == NULL)
            return new AVLTreeNode(data);
        else if (root->data > data)
            root->left = insert(root->left, data);
        else if (root->data < data)
            root->right = insert(root->right, data);
        else
        {
            cout << "No Duplicates Nodes" << endl;
            return root;
        }
        int balanceFactor = getBalanceFactor(root);
        if (balanceFactor > 1 && data < root->left->data)
            return rightRotate(root);
        if (balanceFactor < -1 && data > root->right->data)
            return leftRotate(root);
        if (balanceFactor > 1 && data > root->left->data)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if (balanceFactor < -1 && data < root->right->data)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        return root;
    }

    void print(AVLTreeNode *root)
    {
        if (root != NULL)
        {
            print(root->left);
            cout << root->data << " ";
            print(root->right);
        }
    }

    void print2D(AVLTreeNode *r, int space)
    {
        if (r == NULL)
            return;
        space += SPACE;
        print2D(r->right, space);
        cout << endl;
        for (int i = SPACE; i < space; i++)
            cout << " ";
        cout << r->data << "\n";
        print2D(r->left, space);
    }
};

int main()
{
    AVLTreeNode *root = NULL;
    Insertion obj = Insertion();
    int data, choice;
    int count = 0;
    do
    {
        cout << "Enter the data to be inserted : ";
        cin >> data;
        root = obj.insert(root, data);
        cout << "Enter the choice : ";
        cin >> choice;
    } while (choice);
    cout << endl
         << "-----------------";
    obj.print2D(root, 5);
    cout << endl
         << "-----------------"
         << endl;
    cout << "Inorder Sequence : ";
    obj.print(root);
    return 0;
}