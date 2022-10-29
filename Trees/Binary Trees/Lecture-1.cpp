/*
    Implementation of Binary Tree
*/

#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
};

class BinaryTree : public TreeNode
{
public:
    TreeNode *create()
    {
        int x;
        cout << "Enter the Data : ";
        cin >> x;
        if (x == -9999)
            return NULL;
        TreeNode *newNode = new TreeNode();
        newNode->data = x;
        cout << "Enter the Left Child for " << x << "\n";
        newNode->left = create();
        cout << "Enter the Right Child " << x << "\n";
        newNode->right = create();
        return newNode;
    }

    void inorderTraversal(TreeNode *root)
    {
        if (root != NULL)
        {
            inorderTraversal(root->left);
            cout << root->data << " ";
            inorderTraversal(root->right);
        }
    }
    
    void preorderTraversal(TreeNode *root)
    {
        if (root != NULL)
        {
            cout << root->data << " ";
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
    }
    
    void postorderTraversal(TreeNode *root)
    {
        if (root != NULL)
        {
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            cout << root->data << " ";
        }
    }

    void levelorderTraversal(TreeNode *root){
        if(root == NULL)
            return;
        queue<TreeNode*> q;
        q.push(root);
        //q.push(NULL);
        while (!q.empty())//q.size() > 1
        {
            TreeNode *node = q.front();
            q.pop();
            /*
            if(node == NULL){
                cout<<endl;
                q.push(NULL);
                continue;
            }
            */
            cout<<node->data<<" ";
            if(node->left == NULL)  
                q.push(node->left);
            if(node->right == NULL)  
                q.push(node->right);
        }
    }
};


/*

int main()
{
    TreeNode *root = new TreeNode();
    BinaryTree obj = BinaryTree();
    root = obj.create();
    cout << "Inorder Traversal.." << endl;
    obj.inorderTraversal(root);
    cout << "Preorder Traversal.." << endl;
    obj.preorderTraversal(root);
    cout << "Postorder Traversal.." << endl;
    obj.postorderTraversal(root);
    return 0; 
}

*/