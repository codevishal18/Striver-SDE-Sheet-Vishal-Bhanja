#include <bits/stdc++.h>
using namespace std; 

    template <typename T>
    class TreeNode {
        public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

//reverse preorder traversal
void solve(TreeNode<int> *root,TreeNode<int> *&prev)
{
    if(root==NULL)
    {
        return;
    }

    solve(root->right,prev);
    solve(root->left,prev);
    root->right=prev;
    root->left=NULL;
    prev = root;
}

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    TreeNode<int> *prev = NULL;
    solve(root,prev);
    return prev;
}