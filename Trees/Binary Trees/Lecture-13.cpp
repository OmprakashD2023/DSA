/*
    Tree Traversal in Spiral Form
*/

#include <bits/stdc++.h>
#include "Lecture-1.cpp"
using namespace std;

class Spiral : public BinaryTree
{
public:
    // Using Two Stacks
    void spiralFormEfficient(TreeNode *root)
    {
        if (root == NULL)
        {
            cout << "Tree is empty!" << endl;
            return;
        }
        stack<TreeNode *> s1, s2;
        s1.push(root);
        while (!s1.empty() || !s2.empty())
        {
            while (!s1.empty())
            {
                TreeNode *temp = s1.top();
                cout << temp->data << " ";
                s1.pop();
                if (temp->left != NULL)
                    s2.push(temp->left);
                if (temp->right != NULL)
                    s2.push(temp->right);
            }
            while (!s2.empty())
            {
                TreeNode *temp = s2.top();
                cout << temp->data << " ";
                s2.pop();
                if (temp->left != NULL)
                    s1.push(temp->left);
                if (temp->right != NULL)
                    s1.push(temp->right);
            }
        }
    }

    // Using A Queue and A Stack
    void spiralForm(TreeNode *root)
    {
        if (root == NULL)
            return;
        queue<TreeNode *> q;
        stack<TreeNode *> s;
        bool reverse = false;
        q.push(root);
        while (!q.empty())
        {
            int count = q.size();
            for (int i = 0; i < count; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                if (reverse)
                    s.push(curr);
                else
                    cout << curr->data << " ";
                if (curr->left != NULL)
                    q.push(curr->left);
                if (curr->right != NULL)
                    q.push(curr->right);
            }
            if (reverse)
            {
                while (!s.empty())
                {
                    TreeNode *temp = s.top();
                    cout << temp->data << " ";
                    s.pop();
                }
            }
            reverse = !reverse;
        }
    }
};

int main()
{
    TreeNode *root = NULL;
    Spiral obj = Spiral();
    root = obj.create();
    cout << "Spiral Form of the Binary Tree : ";
    obj.spiralFormEfficient(root);
    /*
        cout << "Spiral Form of the Binary Tree : ";
        obj.spiralForm(root);  
    */
    return 0;
}