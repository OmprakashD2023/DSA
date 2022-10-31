/*
    Search and Insertion in Binary Search Tree
*/

#include <bits/stdc++.h>
using namespace std;

class BST
{
    int data;
    BST *left, *right;

public:
    BST(){
        left = right = NULL;
    }

    BST(int x)
    {
        data = x;
        left = right = NULL;
    }

    // Time Complexity : O(H),Space Complexity : O(H)
    bool searchRecursive(BST *root, int data)
    {
        if (root->data == data)
            return true;
        if (root->data > data)
            return searchRecursive(root->left, data);
        else
            return searchRecursive(root->right, data);
    }

    // Time Complexity : O(H), Space Complexity : O(1)
    bool searchIterative(BST *root, int data)
    {
        while (root != NULL)
        {
            if (root->data == data)
                return true;
            if (root->data > data)
                root = root->left;
            if (root->data < data)
                root = root->right;
        }
        return false;
    }

    // Time Complexity : O(H),Space Complexity : O(H)
    BST *insertRecursive(BST *root, int data)
    {
        if (root == NULL)
            return new BST(data);
        if (root->data > data)
            root->left = insertRecursive(root->left, data);
        if (root->data < data)
            root->right = insertRecursive(root->right, data);
        return root;
    }

    // Time Complexity : O(H), Space Complexity : O(1)
    BST *insertIterative(BST *root, int data)
    {
        BST *temp = new BST(data);
        BST *parent = NULL, *curr = root;
        while (curr != NULL)
        {
            parent = curr;
            if (curr->data > data)
                curr = curr->left;
            else if (curr->data < data)
                curr = curr->right;
            else
                return root;
        }
        if (parent == NULL)
            return temp;
        if (parent->data > data)
            parent->left = temp;
        if (parent->data < data)
            parent->right = temp;
        return root;
    }

    void inorderTraversal(BST *root)
    {
        if (root != NULL)
        {
            inorderTraversal(root->left);
            cout << root->data << " ";
            inorderTraversal(root->right);
        }
    }
};

int main()
{
    BST obj;
    BST *root = NULL;
    int choice = 1;
    while (choice)
    {
        int x;
        cout << "Enter the data to insert into the BST : ";
        cin >> x;
        root = obj.insertIterative(root, x);
        cout << "\nEnter 1 to continue : ";
        cin >> choice;
    }
    obj.inorderTraversal(root);
    return 0;
}