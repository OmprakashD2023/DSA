/*
    Lowest Common Ancestor
    1. Naive Solution -> Two tree traversal
    *Time Complexity : theta(n)
    *Space Complexity : theta(n)

    2. Efficient Solution -> Single tree traversal
    *Time Complexity : O(n)
    *Space Complexity : O(H)
*/

#include <bits/stdc++.h>
#include "Lecture-1.cpp"
using namespace std;

class LCA : public BinaryTree
{
    bool findPath(vector<TreeNode *> &p, int n, TreeNode *root)
    {
        if (root == NULL)
            return false;
        p.push_back(root);
        if (root->data == n)
            return true;
        if (findPath(p, n, root->left) || findPath(p, n, root->right))
            return true;
        p.pop_back();
        return false;
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, int n1, int n2)
    {
        vector<TreeNode *> path1, path2;
        if (findPath(path1, n1, root) == false || findPath(path2, n2, root) == false)
            return NULL;
        for (int i = 0; i < path1.size() - 1 && i < path2.size() - 1; i++)
        {
            if (path1[i + 1] != path2[i + 1])
                return path1[i];
        }
        return NULL;
    }

    TreeNode *lowestCommonAncestorEfficient(TreeNode *root, int n1, int n2)
    {
        if (root == NULL)
            return NULL;
        if (root->data == n1 || root->data == n2)
            return root;
        TreeNode *lca1 = lowestCommonAncestorEfficient(root->left, n1, n2);
        TreeNode *lca2 = lowestCommonAncestorEfficient(root->right, n1, n2);

        if (lca1 != NULL && lca2 != NULL)
            return root;
        if (lca1 != NULL)
            return lca1;
        else
            return lca2;
    }
};

int main()
{
    TreeNode *root = NULL;
    LCA obj = LCA();
    root = obj.create();
    int n1, n2;
    cout << "Enter two nodes to find their Lowest Common Ancestor : ";
    cin >> n1 >> n2;
    TreeNode *LCA = obj.lowestCommonAncestorEfficient(root, n1, n2);
    if (root != NULL)
        cout << "Lowest Common Ancestor : " << LCA->data;
    else
        cout << "No Lowest Common Ancestor";
    return 0;
}