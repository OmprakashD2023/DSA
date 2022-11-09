/*
    Iterative Inorder Traversal
*/

#include <bits/stdc++.h>
#include "Lecture-1.cpp"
using namespace std;

void iterativeInorderTraversal(TreeNode *root)
{
    if (root == NULL)
        return;
    stack<TreeNode *> s;
    TreeNode *curr = root;
    while (curr != NULL || !s.empty())
    {
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

int main(){
    TreeNode *root = NULL;
    BinaryTree obj = BinaryTree();
    root = obj.create();
    cout<<"Iterative Inorder Traversal : ";
    iterativeInorderTraversal(root);
    cout<<endl<<"Recursive Inorder Traversal : ";
    obj.inorderTraversal(root);
    return 0;
}