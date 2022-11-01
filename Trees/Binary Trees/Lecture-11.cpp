/*
    Construct Binary Tree from
    i)Inorder And Preorder Sequence
        Time Complexity : O(n^2)
        Space Complexity : O(n)

    ii)Inorder And Postorder Sequence
        Time Complexity : O(n^2)
        Space Complexity : O(n)
*/

#include <bits/stdc++.h>
#include "Lecture-1.cpp"
using namespace std;

class Construction : public BinaryTree
{
    int preIndex, postIndex;

public:
    Construction(int n)
    {
        this->preIndex = 0;
        this->postIndex = 0;
    }

    TreeNode *constructTreePre(vector<int> in, vector<int> pre, int is, int ie)
    {
        if (ie < is)
            return NULL;
        TreeNode *root = new TreeNode();
        root->data = pre[preIndex++];
        int index = 0;
        for (int i = is; i <= ie; i++)
        {
            if (in[i] == root->data)
            {
                index = i;
                break;
            }
        }
        root->left = constructTreePre(in, pre, is, index - 1);
        root->right = constructTreePre(in, pre, index + 1, ie);
        return root;
    }

    TreeNode *constructTreePost(vector<int> in, vector<int> post, int is, int ie)
    {
        if (ie < is)
            return NULL;
        TreeNode *root = new TreeNode();
        root->data = post[postIndex--];
        if (is == ie)
            return root;
        int index = 0;
        for (int i = is; i <= ie; i++)
        {
            if (in[i] == root->data)
            {
                index = i;
                break;
            }
        }
        root->right = constructTreePost(in, post, index + 1, ie);
        root->left = constructTreePost(in, post, is, index - 1);
        return root;
    }
};

int main()
{
    int n;
    cout << "Enter the number of nodes in the Binary Tree : ";
    cin >> n;
    vector<int> in, pre, post;
    int choice;
    TreeNode *root = new TreeNode();
    Construction obj = Construction(n);
    cout << "Enter 1 for Inorder and Preorder Combination \nEnter 2 for Inorder and Postorder Combination\n";
    cout << "Enter your choice : ";
    cin >> choice;
    if (choice == 1)
    {
        int x;
        cout << "Enter the Inorder Sequence...\n";
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            in.push_back(x);
        }
        cout << "Enter the Preorder Sequence...\n";
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            pre.push_back(x);
        }
        root = obj.constructTreePre(in, pre, 0, n - 1);
        cout << "Tree : ";
        obj.postorderTraversal(root);
    }
    if (choice == 2)
    {
        int x;
        cout << "Enter the Inorder Sequence...\n";
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            in.push_back(x);
        }
        cout << "Enter the Postorder Sequence...\n";
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            post.push_back(x);
        }
        root = obj.constructTreePre(in, post, n - 1, 0);
        cout << "Tree : ";
        obj.preorderTraversal(root);
    }
    return 0;
}