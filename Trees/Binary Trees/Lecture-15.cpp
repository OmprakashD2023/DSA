/*
    Iterative Preorder Traversal
    Time Complexity : O(n)
    Space Complexity : O(n) Extra space for stack
*/

#include <bits/stdc++.h>
#include "Lecture-1.cpp"
using namespace std;

void iterativePreorderTraversal(TreeNode *root)
{
    if (root == NULL)
        return;
    stack<TreeNode *> s;
    s.push(root);
    while (!s.empty())
    {
        TreeNode *node = s.top();
        s.pop();
        cout << node->data << " ";
        if (node->right != NULL)
            s.push(node->right);
        if (node->left != NULL)
            s.push(node->left);
    }
}

//Space Complexity : O(H) Since we store only the right children of the tree it can be atmost H nodes.
void iterativePreorderTraversalEfficient(TreeNode *root)
{
    if (root == NULL)
        return;
    stack<TreeNode *> s;
    TreeNode *curr = root;
    while (curr != NULL || !s.empty())
    {
        while (curr != NULL)
        {
            cout << curr->data << " ";
            if (curr->right != NULL)
                s.push(curr->right);
            curr = curr->left;
        }
        if (!s.empty())
        {
            curr = s.top();
            s.pop();
        }
    }
}

int main()
{
    TreeNode *root = NULL;
    BinaryTree obj = BinaryTree();
    root = obj.create();
    cout << "Recursive Preorder Traversal : ";
    obj.preorderTraversal(root);
    cout << endl
         << "Iterative Preorder Traversal : ";
    iterativePreorderTraversal(root);
    cout << endl
         << "Efficient Iterative Preorder Traversal : ";
    iterativePreorderTraversalEfficient(root);
    return 0;
}