/*
    Diameter of the Binary Tree
*/

#include <bits/stdc++.h>
#include "Lecture-2.cpp"
using namespace std;

class Diameter : public Height
{
    Height obj = Height();
    int res = 0;

public:
    // Time Complexity : O(n^2) since T(n) = T(n-1) + theta(n)
    int diameter(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right)
            return 1;
        int d1 = obj.height(root->left) + obj.height(root->right);
        int d2 = diameter(root->left);
        int d3 = diameter(root->right);
        return max(d1, max(d2, d3));
    }

    // Time Complexity : O(n)
    // This function will return the height of the Tree, but sets the "res" variable to have the diameter value
    int diameterEfficient(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int lh = diameterEfficient(root->left);
        int rh = diameterEfficient(root->right);
        res = max(res, lh + rh);
        return max(lh, rh);
    }

    int getDiameter()
    {
        return res;
    }
};

int main()
{
    TreeNode *root = new TreeNode();
    Diameter obj = Diameter();
    root = obj.create();
    cout << "Height : " << obj.diameterEfficient(root)<<endl;
    cout << "Diameter : " << obj.getDiameter();
    return 0;
}