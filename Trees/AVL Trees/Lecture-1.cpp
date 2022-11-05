/*
    AVL Tree Node
*/

#include<bits/stdc++.h>
using namespace std;

class AVLTreeNode {
public:
    int data;
    AVLTreeNode *left;
    AVLTreeNode *right;

    AVLTreeNode(){
        right = left = NULL;
    }

    AVLTreeNode(int data){
        this->data = data;
        right = left = NULL;
    }
};