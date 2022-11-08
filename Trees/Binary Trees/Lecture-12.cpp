/*
    Convert Binary Tree into Doubly Linked List
    Time Complexity : O(n)
    Space Complexity : O(H)
*/

#include <bits/stdc++.h>
#include "Lecture-1.cpp"
using namespace std;

class LinkedList : public BinaryTree
{
public:
    TreeNode *linkedList(TreeNode *root)
    {
        static TreeNode *prev = NULL;
        if (root == NULL)
            return root;
        TreeNode *head = linkedList(root->left);
        if (prev == NULL)
            head = root;
        else
        {
            root->left = prev;
            prev->right = root;
        }
        prev = root;
        linkedList(root->right);
        return head;
    }

    void print(TreeNode *head)
    {
        while (head != NULL)
        {
            cout << head->data << " ";
            head = head->right;
        }
    }
};

int main()
{
    TreeNode *root = NULL;
    LinkedList obj = LinkedList();
    root = obj.create();
    cout << "Inorder Traversal : ";
    obj.inorderTraversal(root);
    cout << endl;
    root = obj.linkedList(root);
    cout << "Doubly linked list : ";
    obj.print(root);
    return 0;
}