/*
    Children Sum Property
    Time Complexity : O(n)
    Space Complexity : O(H)
*/

#include <bits/stdc++.h>
#include "Lecture-1.cpp"
using namespace std;

class ChildrenSum : public BinaryTree
{
public:
    bool childrenSum(TreeNode *root)
    {
        if (root == NULL)
            return true;
        if (root->left == NULL && root->right == NULL)
            return true;
        int sum = 0;
        if (root->left != NULL)
            sum += root->left->data;
        if (root->right != NULL)
            sum += root->right->data;
        return (root->data == sum && childrenSum(root->left) && childrenSum(root->right));
    }
};

int main()
{
    TreeNode *root = new TreeNode();
    ChildrenSum obj = ChildrenSum();
    root = obj.create();
    if (obj.childrenSum(root))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}