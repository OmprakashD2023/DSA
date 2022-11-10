/*
    Count nodes in a Complete Binary Tree
    Naive Solution:
    Time Complexity : theta(n)
    Efficient Solution:
    Time Complexity...
    * Best Case : theta(h)
    * Worst Case : theta(log n * log n) since T(n) < T(2n/3) + theta(h) here theta(h) = log n
*/

#include <bits/stdc++.h>
#include "Lecture-1.cpp"
using namespace std;

int countNodes(TreeNode *root)
{
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int countNodesEfficient(TreeNode *root)
{
    int lh = 0, rh = 0;
    TreeNode *curr = root;
    while (curr != NULL)
    {
        lh++;
        curr = curr->left;
    }
    curr = root;
    while (curr != NULL)
    {
        rh++;
        curr = curr->right;
    }
    if (lh == rh)
        return pow(2, lh) - 1;
    return 1 + countNodesEfficient(root->left) + countNodesEfficient(root->right);
}

int main(){
    TreeNode *root = NULL;
    BinaryTree obj = BinaryTree();
    cout<<"Construct only a Complete BinaryTree...\n";
    root =obj.create();
    cout<<"Total No. of Nodes : "<<countNodesEfficient(root);
    return 0;
}