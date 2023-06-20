#include <bits/stdc++.h>
using namespace std;

    template <typename T>
    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

void solve(BinaryTreeNode<int> *root,int &ans,int X)
{
    if(root==NULL)
    {
        return;
    }

    if(root->data>X)
    {
        ans = root->data;
        solve(root->left,ans,X);
    }
    else if(root->data<X)
    {
        solve(root->right,ans,X);
    }
    else
    {
        ans = root->data;
        return;
    }
}

int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    int ans = -1;
    solve(node,ans,x);
    return ans;
}