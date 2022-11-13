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
    /**
     * If the root is null, return false. Otherwise, add the root to the path, and if the root's data
     * is the number we're looking for, return true. Otherwise, if the number is found in the left or
     * right subtree, return true. Otherwise, remove the root from the path and return false
     * 
     * @param p This is the vector that will store the path from the root to the node with value n.
     * @param n The node whose path we want to find.
     * @param root The root of the tree
     * 
     * @return true if the path is found and false if the path is not found.
     */
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
    /**
     * Find the paths from root to n1 and root to n2, and return the last common node in the two paths
     * 
     * @param root The root of the binary tree.
     * @param n1 The first node to find the path.
     * @param n2 The second node to find the path.
     * 
     * @return The lowest common ancestor of the two nodes.
     */
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

    /**
     * If the current node is one of the nodes, return it. Otherwise, recursively call the function on
     * the left and right subtrees. If the left subtree returns a non-null value, return that value.
     * Otherwise, return the value returned by the right subtree
     * 
     * @param root The root of the tree
     * @param n1 First node,
     * @param n2 Second node whose LCA we want to find.
     * 
     * @return The lowest common ancestor of the two nodes.
     */
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