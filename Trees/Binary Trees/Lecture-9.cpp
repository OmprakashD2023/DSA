/*
    Maximum Width of the Binary Tree
    Time Complexity : O(n)
    Space Complexity : O(H)
*/

#include <bits/stdc++.h>
#include "Lecture-1.cpp"
using namespace std;

class MaximumWidth : public BinaryTree
{
public:
    int maximumWidth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        queue<TreeNode *> q;
        q.push(root);
        int res = 0;
        while (!q.empty())
        {
            int count = q.size();
            res = max(res, count);
            for (int i = 0; i < count; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);
            }
        }
        return res;
    }
};

int main()
{
    TreeNode *root = new TreeNode();
    MaximumWidth obj = MaximumWidth();
    root = obj.create();
    cout << "Maximum Width : " << obj.maximumWidth(root);
    return 0;
}