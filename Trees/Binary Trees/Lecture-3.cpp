/*
    Print Nodes at K distance
    Time Complexity : O(n)
    Space Complexity : O(H)
*/

#include <bits/stdc++.h>
#include "Lecture-1.cpp"
using namespace std;

class PrintNode : public BinaryTree
{
public:
    void printNode(TreeNode *node, int k)
    {
        if (node == NULL)
            return;
        if (k == 0)
            cout << node->data << " ";
        else
        {
            printNode(node->left, k - 1);
            printNode(node->right, k - 1);
        }
    }
};

int main()
{
    TreeNode *root = new TreeNode();
    PrintNode obj = PrintNode();
    root = obj.create();
    int k;
    cout << "Enter the Distance, k : ";
    cin >> k;
    obj.printNode(root, k);
    return 0;
}