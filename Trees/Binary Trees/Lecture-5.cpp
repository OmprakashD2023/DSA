/*
    Maximum in Binary Tree
    Time Complexity : O(n)
    Spac Complexity : O(H)
*/

#include <bits/stdc++.h>
#include "Lecture-1.cpp"
using namespace std;

class Maximum : public BinaryTree
{
public:
    int maximum(TreeNode *node)
    {
        if (node == NULL)
            return 0;
        return max(node->data, max(maximum(node->left), maximum(node->right)));
    }
};

int main(){
    TreeNode* node = new TreeNode();
    Maximum obj = Maximum();
    node = obj.create();
    cout<<"Maximum in Binary Tree : "<<obj.maximum(node);
    return 0;
}