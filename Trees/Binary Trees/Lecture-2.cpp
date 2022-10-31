/*
    Height of the Binary Tree
*/

#include <bits/stdc++.h>
#include "Lecture-1.cpp"
using namespace std;

class Height : public BinaryTree
{
public:
    int height(TreeNode *node)
    {
        if (node == NULL)
            return 0;
        return (max(height(node->left), height(node->right)) + 1);
    }
};

/*
int main()
{
    TreeNode *root = new TreeNode();
    Height obj = Height();
    root = obj.create();
    cout<<"Height of the Tree : "<<obj.height(root);
    return 0;
}
*/