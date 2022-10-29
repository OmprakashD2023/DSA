/*
    Size of the Binary Tree
    Time Complexity : O(n)
    Space Complexity : O(H)
*/

#include <bits/stdc++.h>
#include "Lecture-1.cpp"
using namespace std;

class Size : public BinaryTree
{
public:
    int size(TreeNode *node)
    {
        if (node == NULL)
            return 0;
        return 1 + size(node->left) + size(node->right);
    }
};

int main(){
    TreeNode *root = new TreeNode();
    Size obj = Size();
    root = obj.create();
    cout<<"Size of the BinaryTree : "<<obj.size(root);
    return 0;
}