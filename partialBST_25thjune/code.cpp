#include <bits/stdc++.h> 
using namespace std;

    template <typename T>
    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

bool validateBST(BinaryTreeNode<int> *root) {
  // Write your code here
    if(root==NULL||(root->left==NULL && root->right==NULL))
    {
        return true;
    }

    bool left = validateBST(root->left);
    bool right = validateBST(root->right);

    bool ans = true;

    if(root->left!=NULL && root->data<root->left->data)
    {
        ans = false;
    }

    if(root->right!=NULL && root->data>root->right->data)
    {
        ans = false;
    }

    return ans && (left && right);
}