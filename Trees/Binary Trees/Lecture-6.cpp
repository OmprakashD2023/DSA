/*
    Print Left View of the Binary Tree

    Recursive Solution
        Time Complexity : O(n)
        Space Complexity : O(H)

    Iterative Solution
        Time Complexity : O()
        Space Complexity : O()
*/

#include <bits/stdc++.h>
#include "Lecture-1.cpp"
using namespace std;

class LeftView : public BinaryTree
{
    int maxLevel;

public:
    LeftView()
    {
        maxLevel = 0;
    }

    // Recursive Solution
    void printLeftView(TreeNode *root, int level)
    {
        if (root == NULL)
            return;
        if (maxLevel < level)
        {
            cout << root->data << " ";
            maxLevel = level;
        }

        printLeftView(root->left, level + 1);
        printLeftView(root->right, level + 1);
    }

    // Iterative Solution
    void leftView(TreeNode *root)
    {
        if (root == NULL)
            return;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int count = q.size();
            for (int i = 0; i < count; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if(i==0)
                    cout<<node->data<<" ";
            }
            if (root->left == NULL)
                q.push(root->left);
            if (root->right == NULL)
                q.push(root->right);
        }
    }
};

int main()
{
    TreeNode *root = new TreeNode();
    LeftView obj = LeftView();
    root = obj.create();
    obj.printLeftView(root, 1);
    return 0;
}