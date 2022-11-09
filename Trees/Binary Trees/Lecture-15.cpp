/*
    Iterative Preorder Traversal
    Time Complexity : O(n)
    Space Complexity : O(n) Extra space for stack
*/

#include<bits/stdc++.h>
#include "Lecture-1.cpp"
using namespace std;

void iterativePreorderTraversal(TreeNode *root){
    if(root == NULL)
        return ;
    stack<TreeNode *> s;
    s.push(root);
    while(!s.empty()){
        TreeNode *node = s.top();
        s.pop();
        cout<<node->data<<" ";
        if(node->right!=NULL)
            s.push(node->right);
        if(node->left!=NULL)
            s.push(node->left);
    }
}

int main(){
    TreeNode *root = NULL;
    BinaryTree obj = BinaryTree();
    root = obj.create();
    cout<<"Recursive Preorder Traversal : ";
    obj.preorderTraversal(root);
    cout<<endl<<"Iterative Preorder Traversal : ";
    iterativePreorderTraversal(root);
    return 0;
}