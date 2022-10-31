/*
    Check for Balanced Binary Tree
*/

#include <bits/stdc++.h>
#include "Lecture-2.cpp"
using namespace std;

class BalancedTree : public Height
{
    Height obj = Height();

public:
    // Time Complexity : O(n^2) since this function executes for n - 1 nodes which in turn calls height function which is O(n)
    bool isBalanced(TreeNode *root)
    {
        if (root == NULL)
            return true;
        int lh = obj.height(root->left);
        int rh = obj.height(root->right);
        return (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right));
    }

    // Time Complexity : O(n)
    int isBalancedEfficient(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int lh = isBalancedEfficient(root->left);
        if (lh == -1)
            return -1;
        int rh = isBalancedEfficient(root->right);
        if (rh == -1)
            return -1;
        if (abs(lh - rh) > 1)
            return -1;
        return max(lh, rh) + 1;
    }
};

int main(){
    TreeNode *root = new TreeNode();
    BalancedTree obj = BalancedTree();
    root = obj.create();
    if(obj.isBalancedEfficient(root) == -1)
        cout<<"Not a Balanced Tree!"<<endl;
    else 
        cout<<"Yes, it is a Balanced Tree!"<<endl;
    return 0;
}